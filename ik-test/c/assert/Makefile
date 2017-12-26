CC = gcc
#CFLAGS += -DNDEBUG -UNDEBUG
#CFLAGS += -UNDEBUG
CFLAGS += -DNDEBUG

all: test
.PHONY: all

objects = a.o b.o main.o
test: $(objects)
	$(CC) -o $@ $(CFLAGS) $(objects)

	#$(CC) -o $@ $(CFLAGS) $<

.PHONY: clean
clean:
	-rm -f test $(objects)

