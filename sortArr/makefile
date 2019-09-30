test2:main.o fun.o fun1.o sort.o
	gcc main.o fun.o fun1.o sort.o -o test2
main.o:main.c
	gcc main.c -c
fun.o:fun.c
	gcc fun.c -c
fun1.o:fun1.c
	gcc fun1.c -c
sort.o:sort.c
	gcc sort.c -c
clean:
	rm -f *.o
