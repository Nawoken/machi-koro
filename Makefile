CC = gcc
CFLAGS = -g -std=c99 -Wall -I ./include

.PHONY: clean doc

doc:
	doxygen conf/doxygen.conf

%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $^

compile-all: minivilles.c minimaxvilles.c
	$(CC) $(CFLAGS) -o $@ $^


add-files-svn:
	svn add --force *.c *.h --auto-props --parents --depth infinity -q

