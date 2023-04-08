#!/bin/bash
gcc -c *.c 
ar rcs liball *.o
ranlib liball.a
