CC = gcc
CFLAGS = -c –Wall -Werror 
EXECUTABLE = main
SOURCES = src/main.c src/figure_name.c src/get_lpar.c src/get_point.c src/get_zpt.c src/get_radius.c src/get_rpar.c src/last_check.c src/std_figure.c src/S_tri.c src/P_tri.c src/S_cir.c src/P_cir.c
OBJECTS=$(SOURCES: .c=.o)

all:	$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -lm $(OBJECTS) -o bin/$@

.c.o:
	$(CC) $(CFLAGS) $< -o build/$@

clean:
	rm -rf *.o *.exe