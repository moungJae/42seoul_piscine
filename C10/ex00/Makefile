CFLAGS = -Wall -Wextra -Werror

TARGET = ft_display_file
SOURCES = main.c 
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $<

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
