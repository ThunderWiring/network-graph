CXX=g++
CXXFLAGS=-std=c++11

RM=rm -f

GENERICS=Generics
UTILTOOLS_H=Generics/utility_using.h
SERVER_SRC=Generics/server
CLIENT_SRC=Generics/client

TESTS=Tests
TESTS_INTERFACE=$(TESTS)/test_interface.h

OBJS= server.o client.o main.o
TARGET=search

all: $(TARGET)

search: $(OBJS)
	$(CXX) $(CXXFLAGS) -o search $(OBJS)

server.o: $(SERVER_SRC)/server.cpp $(SERVER_SRC)/server.h $(UTILTOOLS_H)
	$(CXX) $(CXXFLAGS) -c $(SERVER_SRC)/server.cpp

client.o: $(CLIENT_SRC)/client.cpp $(CLIENT_SRC)/client.h $(UTILTOOLS_H)
	$(CXX) $(CXXFLAGS) -c $(CLIENT_SRC)/client.cpp

main.o: $(TESTS)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(TESTS)/main.cpp
 
clean:
	rm -f *~ *.o $(TARGET)
