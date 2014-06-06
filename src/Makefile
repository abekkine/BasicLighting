TARGET=lights.bin

SOURCES=Main.cpp \
		Application.cpp \
		Block.cpp \
		Light.cpp \
		Edge.cpp \
		EdgeShadow.cpp \
		Config.cpp \
		Display.cpp \
		Vector2f.cpp \
		Color.cpp \
		Util.cpp

OBJECTS=$(SOURCES:%.cpp=%.o)

FLAGS=-g -Wall -Wextra -Werror -Wfatal-errors
CCLIBS=

all: $(OBJECTS)
	g++ $(FLAGS) -o $(TARGET) $(OBJECTS) $(CCLIBS)

.cpp.o:
	g++ $(FLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) *.o *~ core*