all:test

test:test.o
	gcc  test.o -o test

test.o:test.c
	gcc -c test.c -o test.o
	
.PHONY:clean
clean:
	rm test.o test
