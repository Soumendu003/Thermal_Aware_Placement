HOME = /home/guddu/Thermal_Aware_Placement
SRC = $(shell pwd)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -lpthread -ggdb3 -pg 
FLAGS = $(TOPFLAGS)

INCLUDE = util MemManager ParallelHashmap			# Required for header files
LINKDIR = MemManager								# Required for .a or .so files

#LIB_TYPE = {static,shared}
LIB_TYPE = $(LIB)

ifeq ($(LIB_TYPE),shared)
   LIB_EXT = so
else
   LIB_EXT = a
endif

OBJECTS = $(addsuffix .o, $(basename $(wildcard *.cpp)))
SOBJECTS = parser.o lexer.o
HEADERS = $(wildcard *.h)

ifeq ($(shell uname),Linux)
	OS = linux
endif
ifeq ($(shell uname | head -c 6),CYGWIN)
	OS = Cygwin
endif


TARGET := RtlCoreParser-$(OS).$(LIB_EXT)

CLEANLIST =  $(OBJECTS) \
				 rtlcore_parser.tab.cc rtlcore_parser.tab.hh \
				 location.hh position.hh \
			    stack.hh rtlcore_parser.output parser.o \
				 lexer.o rtlcore_lexer.yy.cc \

default : target

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -I. $(patsubst %,-I$(HOME)/%,$(INCLUDE)) $< $(FLAGS)

$(OBJECTS) : $(HEADERS) $(patsubst %,$(HOME)/%/*.h,$(INCLUDE)) 

$(SOBJECTS) : parser lexer 

target: $(SOBJECTS) $(OBJECTS)
	#creates library
	ld -r -o $(TARGET) *.o


parser: rtlcore_parser.yy
	bison -d -v rtlcore_parser.yy
	$(CXX) $(CXXFLAGS) -c -o parser.o rtlcore_parser.tab.cc -I. $(patsubst %,-I$(HOME)/%,$(INCLUDE)) $(FLAGS)

lexer: rtlcore_lexer.l
	flex --outfile=rtlcore_lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c rtlcore_lexer.yy.cc -o lexer.o -I. $(patsubst %,-I$(HOME)/%,$(INCLUDE)) $(FLAGS)

.PHONY: build
build: target clean

.PHONY: clean
clean: $(CLEANLIST)
	rm -rf $(CLEANLIST)

.PHONY: clean-all
	rm -rf $(CLEANLIST) $(TARGET)
