TARGET = MyCalk
CC=g++
CFLAGS=-I.

PREF_SRC = ./src/
PREF_OBJ = ./obj/

$(TARGET) : $(PREF_OBJ)calkmake.o $(PREF_OBJ)calkfunc.o
	$(CC) $(PREF_OBJ)calkmake.o $(PREF_OBJ)calkfunc.o -o $(TARGET)

$(PREF_OBJ)calkmake.o : $(PREF_SRC)calkmake.cpp
	$(CC) -c $(PREF_SRC)calkmake.cpp -o $(PREF_OBJ)calkmake.o

$(PREF_OBJ)calkfunc.o : $(PREF_SRC)calkfunc.cpp
	$(CC) -c $(PREF_SRC)calkfunc.cpp -o $(PREF_OBJ)calkfunc.o

clean:
	rm $(TARGET) $(PREF_OBJ)*.o



