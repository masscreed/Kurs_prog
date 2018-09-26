sorting: main.o libsort.so
	gcc main.o -L. -lsort -o sorting -lm

libsort.so: sort.o
	gcc -shared -o libsort.so sort.o

sort.o: sort.c sort.h
	gcc -fPIC -c sort.c

main.o: main.c
	gcc -c main.c

.PHONY: clean 
clean:
	rm -rf *.o
.PHONY: export 
export:
	export LD_LIBRARY_PATH=.



