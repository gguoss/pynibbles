/*************************************************************************
 * Copyright (c) 2016 Gavin Guo                                          *
 * Distributed under the MIT software license.                           *
 *************************************************************************/

#include <Python.h>
#include <string.h>
#include <malloc.h>

static PyObject *py_nibbles_to_bin(PyObject *self, PyObject *args)
{
    uint8_t *str;
    int len;
    int i = 0;
    PyObject *list = PyTuple_GET_ITEM(args, 0);
    len = PyList_GET_SIZE(list);
    if (len == 0 || len & 0x01) {
        return NULL;
    }
    len = len / 2;
    uint8_t *retValue = (uint8_t *)malloc(sizeof(uint8_t) *(len + 1));
    for (; i < len; i++) {
        retValue[i] = ((uint8_t)(PyInt_AsLong(PyList_GET_ITEM(list, 2 * i)))) * 16 + (uint8_t)(PyInt_AsLong(PyList_GET_ITEM(list, 2 * i + 1)));
    }
    retValue[len] = '\0';
    PyObject *ret = (PyObject *)Py_BuildValue("s", retValue);
    free(retValue);
    return ret;
}

static PyObject *py_bin_to_nibbles(PyObject *self, PyObject *args)
{
    int res;
    uint8_t *str;
    int len;
    int i = 0;
    res = PyArg_ParseTuple(args, "t#", &str, &len);
    if (!res) {
        return NULL;
    }
    if (len < 0) {
        return NULL;
    }
    PyObject *v = PyList_New(len * 2);
    if (v == NULL) {
        return NULL;
    }
    uint8_t byte;
    for (i = 0; i < len; i++) {
        PyObject *w1 = PyInt_FromLong((long)(byte = (str[i] >> 4) & 0x0f));
        PyObject *w2 = PyInt_FromLong((long)(byte = str[i] & 0x0f));
        if (w1 == NULL || w2 == NULL) {
            Py_DECREF(v);
            return NULL;
        }
        PyList_SET_ITEM(v, 2 * i, w1);
        PyList_SET_ITEM(v, 2 * i + 1, w2);
    }
    return v;
}

static PyMethodDef PyextMethods[] = {
    {"nibbles_to_bin", py_nibbles_to_bin, METH_VARARGS},
    {"bin_to_nibbles", py_bin_to_nibbles, METH_VARARGS},
    {NULL, NULL,},
};

PyMODINIT_FUNC initpynibbles(void)
{
    Py_InitModule("pynibbles", PyextMethods);
}
