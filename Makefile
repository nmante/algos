# Compiler
CC := g++

# Compiler Flags
DEBUG := -g
CFLAGS := -std=c++11

# Directories
INCDIR := include
SRCDIR := src
TESTDIR := tests
BUILDDIR := build
BINDIR := bin

# Targets
APP := app
LIBRARY := library
TESTS := test
EXE := bin/algos.out
TESTEXE := bin/algos-tests.out
LIBEXE := bin/libalgos.a

# Extensions
SRCEXT :=cpp
INCEXT :=hpp

# Sources and Includes
SRCS := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJS :=$(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SRCS:.cpp=.o))
INC := -I$(INCDIR)

# Catch C++ Testing framework
CATCHURL := https://raw.githubusercontent.com/philsquared/Catch/master/single_include/catch.hpp
CATCHSRC := $(TESTDIR)/catch.hpp


all: $(APP) $(LIBRARY) $(TESTS)
	@echo "Building all targets..."

$(APP): $(OBJS)
	@echo "Building executable..."
	@mkdir -p $(BINDIR)
	$(CC) $(DEBUG) $(CFLAGS) $^ main.cpp -o $(EXE)

$(LIBRARY): $(OBJS)
	@echo "Building library..."
	@mkdir -p $(BINDIR)
	ar ru $(LIBEXE) $(OBJS)
	ranlib $(LIBEXE) 
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(INCDIR)/%.$(INCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Making objects..."
	$(CC) $(DEBUG) $(CFLAGS) $(INC) -c -o $@ $< 

$(TESTS): $(TESTDIR)/tests.cpp
	echo "Building Tests..."
	if ! [ -a $(TESTDIR)/catch.hpp ]; then wget -O $(CATCHSRC) $(CATCHURL); fi;
	@mkdir -p $(BINDIR)
	$(CC) $(DEBUG) $(CFLAGS) $(INC) $(OBJS) $(TESTDIR)/tests.cpp -o $(TESTEXE)
	./$(TESTEXE)

clean:
	@echo "Cleaning..."
	rm -rf $(BUILDDIR) $(EXE) $(TESTEXE) $(LIBEXE) $(BINDIR)/*.dSYM

.PHONY: clean

