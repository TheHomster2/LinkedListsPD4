all: list.c
	gcc list.c -o list
run: list
	./list
clean: rm *.o
	rm *.~