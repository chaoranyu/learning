obj = cal.o io.o stack.o

cal: $(obj)
	cc -o cal $(obj)

$(obj): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	-rm -rf cal $(obj)
