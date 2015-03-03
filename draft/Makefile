TARGET=go.bin
SRCS=main.cpp application.cpp display.cpp light.cpp block.cpp vector2f.cpp
OBJS=$(SRCS:%.cpp=%.o)
FLAGS=-Wall -Wextra -Werror -Wfatal-errors #-DDEBUG
CCLIBS=-lglut -lGLEW -lGL

all: $(OBJS)
	g++ $(FLAGS) -o $(TARGET) $(OBJS) $(CCLIBS)

.cpp.o:
	g++ $(FLAGS) -c -o $*.o $<

clean:
	$(RM) $(TARGET) *.o *~ core*
