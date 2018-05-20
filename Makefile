# Makefile for compiling
CC=gcc
LD=gcc
RM=rm -f
#CFLAGS=-std=gnu99  `pkg-config --cflags --libs  opencv`  -ldl -lm -Wall -O2 -fopenmp -Wno-unused-result
CFLAGS=-std=gnu99  -lm -Wall -O2 -fopenmp -Wno-unused-result
LDFLAGS=-std=gnu99   -Wall -O2 -fopenmp -Wno-unused-result
OBJS:=$(patsubst %.c,%.o,$(wildcard *.c))
HS:=$(wildcard *.h)

MAIN=hw
all:$(MAIN) $(HS)
$(MAIN):$(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(MAIN) -lm
%.o: %.c $(HS)
	$(CC) $(CFLAGS) -c $<
debug:
	make "CFLAGS=-std=gnu99   -lm -Wall -g -fopenmp"  "LDFLAGS=-std=gnu99   -lm -Wall -g -fopenmp"
clean:
	$(RM) $(OBJS) *.*~ *~
cleanall:
	$(RM) $(OBJS) *.*~ *~ $(MAIN)
run:
	echo "running pending"
