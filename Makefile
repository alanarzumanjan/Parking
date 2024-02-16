TARGET = main
SRC_FILE = $(TARGET).cpp

CC = g++
CFLAGS = -lm -std=c++14

all: clean build run

build:
	$(CC) $(SRC_FILE) -o $(TARGET) $(CFLAGS)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
	
push:
	git add .
<<<<<<< HEAD
	git commit -a -m "Markus super pony"
=======
	git commit -a -m "Markus is so hard pony"
	git pull
	git rebase
>>>>>>> 19a19b3 (Markus is so hard pony)
	git push