make: main.o Customer.o 
	g++ main.o Customer.o -o make

Customer.o: Customer.cpp
	g++ --std=c++11 Customer.cpp

main.o: main.cpp
	g++ --std=c++11 main.cpp

clean:
	rm *.o make
