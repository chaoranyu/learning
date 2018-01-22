STR_A="Hello!"

STR_B=$(shell date --rfc-3339=date)

all:
	gcc -DSTR_INFO=\"$(STR_A)\" -DSTR_DATE=\"$(STR_B)\" -o test main.c
