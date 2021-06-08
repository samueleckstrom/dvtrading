CXX = g++ -std=c++17

CXXFLAGS = -g -Wall -pthread

interval.o: interval.cpp interval.h
	$(CXX) $(CXXFLAGS) -c interval.cpp

sequence.o: sequence.cpp sequence.h interval.h
	$(CXX) $(CXXFLAGS) -c sequence.cpp

main.o: main.cpp sequence.h
	$(CXX) $(CXXFLAGS) -c main.cpp

app: interval.o sequence.o main.o
	$(CXX) $(CXXFLAGS) interval.o sequence.o main.o -o app

unittest.o: unittest.cpp sequence.h
	$(CXX) $(CXXFLAGS) -c unittest.cpp

test: interval.o sequence.o unittest.o
	$(CXX) $(CXXFLAGS) interval.o sequence.o unittest.o -lgtest_main -lgtest -lpthread -o test

clean:
	rm -f app test *.o