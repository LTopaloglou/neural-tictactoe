CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror=vla -MMD
EXEC = tictactoe
OBJECTS = Board.o MinMaxNode.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}