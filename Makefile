.KEEP.STATE: 

CC = g++
OBJECTS = malla.o debug.o punto.o hexagono.o cursor.o listas.o matriz.o nodo.o nodoX.o nodoY.o 
CFLAGS  = -Wall -Wextra -ansi -pedantic -g
INC = 
LIBS =  

TARGET = hexagonal
all :$(TARGET)
$(TARGET) : main.o $(OBJECTS)
			$(CC) $(CFLAGS) $(INC) $(LIBS) -o hexagonal main.o $(OBJECTS)
debug.o : debug.cpp debug.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c debug.cpp
main.o : main.cpp main.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c main.cpp
malla.o : malla.cpp malla.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c malla.cpp
punto.o : punto.cpp punto.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c punto.cpp
crsor.o: cursor.cpp cursor.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c cursor.cpp
hexagono.o : hexagono.cpp hexagono.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c hexagono.cpp
listas.o : listas.cpp listas.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c listas.cpp
matriz.o : matriz.cpp matriz.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c matriz.cpp
nodo.o : nodo.cpp nodo.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c nodo.cpp	
nodoX.o : nodoX.cpp nodoX.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c nodoX.cpp	
nodoY.o : nodoY.cpp nodoY.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c nodoY.cpp	
panelPrincipal.o : panelPrincipal.cpp panelPrincipal.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c panelPrincipal.cpp	
panelDirectorio.o : panelDirectorio.cpp panelDirectorio.h
			$(CC) $(CFLAGS) $(INC) $(LIBS) -c panelDirectorio.cpp	
		
clean : 
	$(RM) count *.o $(TARGET)
