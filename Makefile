# Compiler
CC := g++

# Compiler Flags
DEBUG := -g
CFLAGS := -std=c++11

# Prefix
PREFIX := /usr/local

# Directories
INCDIR := include
SRCDIR := src
TESTDIR := tests
BUILDDIR := build
SRCSUBDIRS := $(shell find $(SRCDIR) -type d)
BUILDSUBDIRS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SRCSUBDIRS))
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

all: $(LIBRARY) $(TESTS)
	@echo "Building all targets..."

$(LIBRARY): $(OBJS)
	@echo "Building library..."
	@mkdir -p $(BINDIR)
	ar ru $(LIBEXE) $(OBJS)
	ranlib $(LIBEXE) 

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(INCDIR)/%.$(INCEXT)
	@echo "Making objects..."
	@mkdir -p $(BUILDSUBDIRS)
	$(CC) $(DEBUG) $(CFLAGS) $(INC) -c -o $@ $< 

$(TESTS): $(BUILDDIR)/tests-main.o $(TESTDIR)/tests.cpp
	echo "Building Tests..."
	if ! [ -a $(TESTDIR)/catch.hpp ]; then wget -O $(CATCHSRC) $(CATCHURL); fi;
	@mkdir -p $(BINDIR)
	$(CC) $(DEBUG) $(CFLAGS) $(INC) $(OBJS) $(BUILDDIR)/tests-main.o $(TESTDIR)/tests.cpp -o $(TESTEXE)
	./$(TESTEXE)

$(BUILDDIR)/tests-main.o: $(TESTDIR)/tests-main.cpp
	$(CC) $(TESTDIR)/tests-main.cpp -c -o $(BUILDDIR)/tests-main.o

.PHONY: install
install: $(LIBEXE)
	@echo "Installing headers and library..."
	mkdir -p $(PREFIX)/lib
	install -m 0755 $(LIBEXE) $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/algos
	cp -r $(INCDIR)/* $(PREFIX)/include/algos 

.PHONY: uninstall
uninstall: $(LIBEXE)
	@echo "Uninstalling headers and library..."
	rm -f $(PREFIX)/lib/libalgos.a
	rm -rf $(PREFIX)/include/algos

.PHONY: clean
clean:
	@echo "Cleaning..."
	rm -rf $(BUILDDIR) $(EXE) $(TESTEXE) $(LIBEXE) $(BINDIR)/*.dSYM

