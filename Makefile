
CC=gcc
CFLAGS = -Wall -g -std=c99

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	@echo "clean objfiles"
	-rm *.o
