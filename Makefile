CFLAG = -O2 -c -fPIC
INCLUDE = -I/usr/include/python2.7 -I./
COMMON_OBJS = pynibbles.o

lib:
	gcc $(INCLUDE) $(CFLAG) pynibbles.c -o pynibbles.o
	gcc -shared $(COMMON_OBJS) -o pynibbles.so -lpython2.7
clean:
	rm *\.so *\.o
