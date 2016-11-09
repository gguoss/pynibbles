import time
import pynibbles as nib

def bin_to_nibbles(s):
    return nib.bin_to_nibbles(s)

def nibbles_to_bin(nibbles):
    return nib.nibbles_to_bin(nibbles)

if __name__ == '__main__':
    test = "hello"
    start = time.time()
    for i in range(10000):
        bin_to_nibbles(test)
    print "bin_to_nibbles delay:%f" %(time.time() - start)
    print bin_to_nibbles(test)

    test1 = bin_to_nibbles(test)
    start = time.time()
    for i in range(10000):
        nibbles_to_bin(test1)
    print "nibbles_to_bin delay:%f" %(time.time() - start)
    print nibbles_to_bin(test1)
