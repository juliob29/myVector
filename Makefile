#
# A very simple makefile
#

# The default C compiler
CC = gcc

# The CFLAGS variable sets compile flags for gcc:
#  -g          compile with debug information
#  -Wall       give verbose compiler warnings
#  -O0         do not optimize generated code
#  -std=gnu99  use the GNU99 standard language definition
CPPFLAGS = -g -Wall -O0 -std=c++14
CFLAGS = -g -Wall -O0 -std=gnu99

practice: vec.cpp
	$(CC) $(CPPFLAGS) -o vector vec.cpp -lstdc++

practiceC: practice.c
	$(CC) $(CFLAGS) -o practice practice.c



.PHONY: clean

clean:
	rm -f practice *.o
