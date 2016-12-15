obj = main.o stack.o getop.o getch.o

calc: $(obj)
	cc -o calc $(obj)

$(obj): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	-rm -rf calc $(obj)
