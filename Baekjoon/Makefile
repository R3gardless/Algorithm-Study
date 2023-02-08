CC = g++
name = main
exec : $(name).o
	$(CC) -g $(name).o -o exec 
	rm -rf *.o
	./exec
	
main.o : $(name).cpp
	$(CC) -c $(name).cpp

clean : 
	rm -rf *.o exec