obj = main.o stack.o getop.o getch.o

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
calc: $(obj)
	cc -o calc $(obj)

$(obj): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	-rm -rf calc $(obj)
