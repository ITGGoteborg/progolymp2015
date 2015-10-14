LIBS = -lm
CFLAGS = -g -O2 -std=gnu99 -static

SRC=talfamiljer.c

all: talfamiljer talfamilj

talfamiljer: talfamiljer.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

talfamilj: talfamilj.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
