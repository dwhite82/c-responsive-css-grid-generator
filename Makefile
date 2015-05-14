IDIR =inc
CC=gcc
STD = -std=c99
VER = v0.0.2
CFLAGS=-I$(IDIR)

ODIR=obj
BDIR = bin

LIBS=-lm

ifeq ($(OS),Windows_NT)
	RM = del /Q $(ODIR)
else
	RM = rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 
endif

_DEPS = main.h cssgenerator.h htmlgenerator.h css_util.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o cssgenerator.o htmlgenerator.o css_util.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(OBJ): $(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) $(STD) -c -o $@ $< $(CFLAGS)

gridgenerator: $(OBJ)
	gcc $(STD) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
	$(info ******* Compiled program and dependent folders in /bin directory *******)
	
.PHONY: clean

clean:
	$(RM)