CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

SRC = main.cpp \
      indice.cpp \
      textprocessor.cpp \
      indexer.cpp \
      serializer.cpp \
      querryprocessor.cpp \
      commandlineinterface.cpp

OBJ = $(SRC:.cpp=.o)

EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

clean:
	rm -f *.o $(EXEC)
