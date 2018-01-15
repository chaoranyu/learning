
CFLAGS += $(WERROR_FLAGS)
objects = *.o

.PHONY:all

all:test

test:main.o
	cc -o test main.o

main.o:main.c
	cc -o main.o -c $(CFLAGS) main.c

.PHONY:clean

clean:
	rm -f test *.o *.out
