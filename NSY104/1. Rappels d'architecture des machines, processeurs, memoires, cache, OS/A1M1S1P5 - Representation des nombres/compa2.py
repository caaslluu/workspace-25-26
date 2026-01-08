#!/usr/bin/python
# -*- coding: utf-8 -*-

def twos_comp(val, bits):
    """compute the 2's compliment of int value val"""
    if( (val&(1<<(bits-1))) != 0 ):
        val = val - (1<<bits)
    return val


binary_string = '1111' # or whatever... no '0b' prefix
out = twos_comp(int(binary_string,2), len(binary_string))
print(out)

hex_string = '0xFFFFFFFF' # or whatever... '0x' prefix doesn't matter
out = twos_comp(int(hex_string,16), 32)
print(out)

overflow = bin(129) # en binaire = 0b1000001 et en hexa = 0x81
out = twos_comp(int(overflow,2), 8)
print(out)

overflow = bin(4294967292) # en binaire = 0b11111111111111111111111111111100 et en hexa = 0xfffffffc
out = twos_comp(int(overflow,2), 32)
print(out)
