

.PHONY:all

all:test

test:cJSON.c test.c cJSON.h
	cc -o test cJSON.c test.c

.PHONY:clean

clean:
	rm test
