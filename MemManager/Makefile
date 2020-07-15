CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -lpthread 

ifeq ($(shell uname),Linux)
	OS = linux
endif
ifeq ($(shell uname | head -c 6),CYGWIN)
	OS = Cygwin
endif

LIB_EXT = so 
ifeq ($(LIB_TYPE),shared)
   TARGET = MemManager-$(OS).$(LIB_EXT)
else
   TARGET = MemManager-$(OS).a
endif

OBJECTS = stats.o random.o os.o arena.o region.o segment.o page.o alloc.o alloc-aligned.o alloc-posix.o heap.o options.o init.o
HEADERS = $(wildcard *.h)


default: all

.SUFFIXES: .c .cpp .o 

.c.o:
	$(CXX) $(CXXFLAGS) -c -I.  $<

$(OBJECTS) : $(HEADERS) 

target: $(OBJECTS)
	ld -r -o $(TARGET) *.o

all : target

clean:
	rm -rf $(OBJECTS) $(TARGET)
