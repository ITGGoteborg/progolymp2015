LIBS = -lm
CFLAGS = -Wall -Wextra -O2 -g -std=gnu99 -static

SRC=talfamiljer.c

all: talfamiljer talfamilj

talfamiljer: talfamiljer.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

talfamilj: talfamilj.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
