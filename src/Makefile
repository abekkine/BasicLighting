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
FLAGS+=-O0 -coverage
CCLIBS=

all: $(OBJECTS)
	g++ $(FLAGS) -o $(TARGET) $(OBJECTS) $(CCLIBS)

.cpp.o:
	g++ $(FLAGS) -c -o $*.o $<

clean:
	$(RM) -rf $(TARGET) *.o *~ core* *.gcov *.gcda *.gcno *.info report

coverage: all
	./$(TARGET)
	lcov -o report.info -c -d .
	genhtml -o report --no-branch-coverage report.info 