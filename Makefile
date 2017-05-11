CFLAGS = -Wall -Wextra -O0 -g3

all: lsort luniq

lsort: lsort.o

luniq: luniq.o

install: lsort luniq
	install lsort /usr/local/bin
	install luniq /usr/local/bin

clean: 
	rm -rf *.o lsort luniq *.dSYM

.PHONY: clean
