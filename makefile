CC = gcc
CFLAGS = -c –Wall -Werror
EXECUTABLE = main
SOURCES = src/main.c src/figure_name.c src/get_lpar.c src/get_point.c src/take_zpt.c src/get_radius.c src/get_rpar.c src/last_check.c
OBJECTS=$(SOURCES: .c=.o)

all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/$@

.c.o:
	$(CC) $(CFLAGS) $< -o build/$@

clean:
	rm -rf *.o *.exe