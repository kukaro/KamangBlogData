CC = gcc
OBJS = calc.o main.o
TARGET = Main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -rf $(OBJS) $(TARGET)
