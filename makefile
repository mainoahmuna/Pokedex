CC=g++ -g
exe=pika

$(exe): pokedex.o driver.cpp
	$(CC) pokedex.o driver.cpp -o $(exe)

pokedex.o: pokedex.cpp pokedex.h
	$(CC) -c pokedex.cpp 

clean: 
	rm -f *.o $(exe)