HOME = /home/guddu/Thermal_Aware_Placement
SRC = $(shell pwd)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -lpthread -ggdb3 -pg 
FLAGS = $(TOPFLAGS)

#//## For Essentials
INCLUDE = util MemManager ParallelHashmap			# Required for header files
LINKDIR = MemManager								# Required for .a or .so files
#//## For Essentials							# Required for .a or .so files

#//## For Parser
INCLUDE += rtlcore_parser
LINKDIR += rtlcore_parser
#//## For Parser

#LIB_TYPE = {static,shared}
LIB_TYPE = $(LIB)

ifeq ($(LIB_TYPE),shared)
   LIB_EXT = so
else
   LIB_EXT = a
endif

OBJECTS = $(addsuffix .o, $(basename $(wildcard *.cpp)))
HEADERS = $(wildcard *.h)

ifeq ($(shell uname),Linux)
	OS = linux
endif
ifeq ($(shell uname | head -c 6),CYGWIN)
	OS = Cygwin
endif


TARGET := RtlCoreParseTree-$(OS).$(LIB_EXT)

CLEANLIST =  $(OBJECTS)

default : target

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -I. $(patsubst %,-I$(HOME)/%,$(INCLUDE)) $< $(FLAGS)

$(OBJECTS) : $(HEADERS) $(patsubst %,$(HOME)/%/*.h,$(INCLUDE)) 

target: $(SOBJECTS) $(OBJECTS)
	#creates library
	ld -r -o $(TARGET) *.o

.PHONY: build
build: target clean

.PHONY: clean
clean: $(CLEANLIST)
	rm -rf $(OBJECTS)

.PHONY: clean-all
	rm -rf $(OBJECTS) $(TARGET)
