

all: linux

clean:
	rm -f mrxppp mrxpppoe

linux: clean
	gcc -Wall -O3 -g0 mrxppp.c   -o mrxppp
	gcc -Wall -O3 -g0 mrxpppoe.c -o mrxpppoe

install: 
	install -s mrxppp          /usr/bin/mrxppp
	install -s mrxpppoe        /usr/bin/mrxpppoe

