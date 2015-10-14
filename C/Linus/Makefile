LIBS = -lm
CFLAGS = -g -O2 -std=gnu99 -static

SRC=$(wildcard *.c)

$(SRC:.c=): $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
