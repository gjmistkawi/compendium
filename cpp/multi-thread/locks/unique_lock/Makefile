CC = clang++
CXXFLAGS = -std=c++17

all: simple complete

simple: simple.o
	$(CC) $(CXXFLAGS) -o simple.exe simple.o -pthread

complete: complete.o
	$(CC) $(CXXFLAGS) -o complete.exe complete.o -pthread

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm *.exe *.o