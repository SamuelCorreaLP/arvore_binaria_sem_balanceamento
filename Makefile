CXX=g++
CXXFLAGS=-g -ggdb -O2 -Wall

TARGET=main
OBJS=main.o \
	arvoreBinaria.o \
	item.o 

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

install:
	cp $(TARGET) /usr/local/bin

main.o: arvoreBinaria.h item.h no.h
arvoreBinaria.o: arvoreBinaria.h no.h
item.o: item.h

$(TARGET): $(OBJS)
		   $(CXX) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
