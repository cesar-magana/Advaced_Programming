# Compilador
CXX = g++

NOMBRE   = Hough

DIR= .
program_objects = $(NOMBRE).o $()
LDFLAGS += -Wall

INCLUDES = ${}
LIBS = ${}

all : programa

.cpp.o:
	$(CXX) -c $< $(LDFLAGS) $(LIBS) $(INCLUDES)

programa: $(NOMBRE).cpp $(program_objects)
	$(CXX) -o $(NOMBRE) $(program_objects) $(LDFLAGS) $(LIBS)


clean:
	rm -f *.o $(NOMBRE)

