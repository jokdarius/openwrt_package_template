TMPL_SOURCES = template.c
TMPL_OBJS = $(TMPL_SOURCES:.c=.o)
TMPL_TARGET = template
CFLAGS = -lm -O3 -Wall -Wextra -g
RM = rm -f

all:
	$(CC) $(TMPL_SOURCES) $(CFLAGS) -o $(TMPL_TARGET)

clean:
	$(RM) $(TMPL_SOURCES) $(TMPL_TARGET)

