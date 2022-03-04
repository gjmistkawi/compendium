CC = clang++
CXXFLAGS = -std=c++17

all: example

example: example.o
	$(CC) $(CXXFLAGS) -o example.exe example.o -pthread

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm *.exe *.o