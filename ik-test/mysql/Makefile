CC = gcc
CFLAGS += -Wall -I/usr/include/mysql
LIBS += -L/usr/lib64/mysql -lmysqlclient -lpthread -lm -lrt -ldl

all: ta tb tc
.PHONY: all

ta: a.o
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)

tb: b.o
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)

objects_c = c.o
tc: $(objects_c)
	$(CC) -o $@ $(CFLAGS) $< $(LIBS)

.PHONY: clean
clean:
	-rm -f *.o t?

.PHONY: co
co:
	-rm -f *.o

