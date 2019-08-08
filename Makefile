.POSIX:

binhex: binhex.o binary.o

binhex.o: binhex.c binary.h
binary.o: binary.c binary.h

clean:
	rm -f binhex *.o
