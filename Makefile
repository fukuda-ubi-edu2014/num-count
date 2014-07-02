#
# Copyright (c) 2014, Kyushu Univ.
# All rights reserved.
#

CC	= gcc
TARGET	= num_count
CFLAGS	= -Wall
OBJ	= main.o
LDFLAGS	= 


.SUFFIXES: .c .o .h


# primary target
.PHONY: all debug
all: depend $(TARGET)

# debug target
debug: DB_CFLAGS = -g
debug: all


# main target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(DB_CFLAGS) -o $@ $(LDFLAGS) $^


# Cleaning
.PHONY: clean cleanup
clean:
	-@$(RM) $(OBJ)
	-@$(RM) depend.inc

cleanup: clean
	-@$(RM) $(TARGET)


# Suffixes for .o (.c -> .o)
.c.o:
	$(CC) $(CFLAGS) $(DB_CFLAGS) -c $<


# header file dependency calculation
.PHONY: depend
depend: $(OBJ:.o=.c)
	-@$(RM) depend.inc
	-@for i in $^; do\
		$(CC) $(CFLAG) -MM $$i | sed "s/\ [_a-zA-Z0-9][_a-zA-Z0-9]*\.c//g" >> depend.inc;\
	done

-include depend.inc
