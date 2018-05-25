CC = g++
INC =../include/
SRC = ../src
EXE = ejecut.exe
OBJ = $(SRC)/play.cpp $(SRC)/Menu.cpp $(SRC)/ventana.cpp  main.cpp 
O = $(OBJ:.cpp=.o) 
GRAFIC = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
CVERSION = -std=c++14

all: $(EXE)

$(EXE) : $(O)
	$(CC) -I $(INC) $^ -o $@ $(GRAFIC)  -o $@ $(CVERSION)

.cpp.o: $(OBJ)	
	$(CC) -I $(INC) -c $^ -o $@ $(CVERSION) -o $@ $(GRAFIC)

clean:
	$(RM) *.o $(EXE)		