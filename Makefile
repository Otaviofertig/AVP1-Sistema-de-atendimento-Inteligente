CC     = gcc
CFLAGS = -Wall -Wextra -g
TARGET = sistema
SRCS   = $(wildcard src/*.c)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
