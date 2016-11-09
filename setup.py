from setuptools import setup, Extension

version = '0.1'

ext_modules = [
    Extension('pynibbles', ['./pynibbles.c']),
]

setup(
    name="pynibbles",
    version=version,
    author='Gavin Guo',
    ext_modules=ext_modules,
)
