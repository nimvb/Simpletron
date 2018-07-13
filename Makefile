all: simulator

# COMPILER
CC = g++

# COMPILER FLAGS
CFLAGS = -std=c++11

# INCLUDE FILES DIRECTORY
INCLUDE_DIR = ./include

simulator: simulator.o cpu.o memory.o
	$(CC) -o $@ -I$(INCLUDE_DIR) $(CFLAGS) simulator.o cpu.o memory.o
  
simulator.o: ./src/simulator.cpp cpu.o memory.o
	$(CC) -c $< -I$(INCLUDE_DIR) $(CFLAGS) ./src/simulator.cpp
  
cpu.o: ./src/cpu/cpu.cpp
	$(CC) -c $< -I$(INCLUDE_DIR) $(CFLAGS) ./src/cpu/cpu.cpp
  
memory.o: ./src/memory/memory.cpp
	$(CC) -c $< -I$(INCLUDE_DIR) $(CFLAGS) ./src/memory/memory.cpp

clean:
	-rm simulator.o cpu.o memory.o