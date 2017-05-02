# Compiler
CC := g++

# Compiler Flags
DEBUG := -g
CFLAGS := -std=c++11

# Targets
APP := app
EXE := algos.out

# Library
LIBS := -lalgos

all: $(APP)
	@echo "Building all targets..."

$(APP): main.cpp 
	@echo "Building executable..."
	$(CC) $(DEBUG) $(CFLAGS) $(LIBS) main.cpp -o $(EXE)

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -rf $(EXE) *.dSYM
