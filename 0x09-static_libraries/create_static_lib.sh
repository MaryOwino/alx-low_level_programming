#!/bin/bash
gcc -Wall -pedantic - werror -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
