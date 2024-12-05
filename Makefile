CXX = g++
CXXFLAGS = -std=c++17 # -Wall para warnings, -g para debugging

SRCS = main.cpp pointers.cpp sorting.cpp sort.cpp files.cpp vector.cpp bits.cpp struct.cpp employee.cpp design/herencia.cpp design/figure.cpp design/rectangle.cpp design/circle.cpp design/point.cpp design/funcion.cpp ConstructorDestructorHerencia.cpp lists.cpp
OBJS = $(SRCS:.cpp=.o) # Convertir .cpp a .o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean # Marcar all y clean como objetivos falsos

