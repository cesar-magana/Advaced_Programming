# Compilador
CXX = g++

NOMBRE   = HW11P01
INCLUYE	= Complejo

DIR= .
server_objects = $(INCLUYE).o $(NOMBRE).o
LDFLAGS += -Wall

INCLUDES = ${}
LIBS = ${}

all : programa

.cpp.o:
	$(CXX) -c $< $(LDFLAGS) $(LIBS) $(INCLUDES)

programa: $(NOMBRE).cpp $(server_objects)
	$(CXX) -o $(NOMBRE) $(server_objects) $(LDFLAGS) $(LIBS)


clean:
	rm -f *.o $(NOMBRE)

