# Makefile for bounded buffer project

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -pthread -std=c99

# Define the target executable name
TARGET = bounded_buffer

# Define source files
SRCS = main.c bounded_buffer.c

# Define object files from source files
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = bounded_buffer.h

# Default target
all: $(TARGET)

# Rule to link the program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
# Now with added dependency on header files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Target to clean the build files
clean:
	rm -f $(TARGET) $(OBJS)

# Target to create a zip archive of the project
zip:
	zip -r $(TARGET).zip *.c *.h Makefile

# Phony targets
.PHONY: clean zip

