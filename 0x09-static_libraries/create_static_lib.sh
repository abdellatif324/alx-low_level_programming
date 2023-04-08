#!/bin/bash
gcc -c *.c
ar rcs libmy.a
ar rcs libmy.a *.o
