HOME = /home/guddu/Thermal_Aware_Placement
SRC = $(shell pwd)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -lpthread -ggdb3 
FLAGS = $(TOPFLAGS)

#//## For Essentials
INCLUDE = util MemManager ParallelHashmap			# Required for header files
LINKDIR = MemManager util							# Required for .a or .so files
#//## For Essentials

#//## For Parser
INCLUDE += rtlcore/parser
LINKDIR += rtlcore/parser
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


TARGET := rtlcore-$(OS)

CLEANLIST =  $(OBJECTS) 


default : target

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -I. $(patsubst %,-I$(HOME)/%,$(INCLUDE)) $< $(FLAGS)

$(OBJECTS) : $(HEADERS) $(patsubst %,$(HOME)/%/*.h,$(INCLUDE)) 

target: $(SOBJECTS) $(OBJECTS)
	#creates executable
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(patsubst %,$(HOME)/%/*-$(OS).$(LIB_EXT),$(LINKDIR)) $(FLAGS)

.PHONY: build
build: target clean

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)

.PHONY: clean-all
	rm -rf $(CLEANLIST) $(TARGET)
