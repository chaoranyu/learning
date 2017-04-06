test: main.o foo.o
	gcc -o test main.o foo.o
 
main.o: main.c
foo.o: foo.c

.PHONY:
clean:
	rm *.o test
