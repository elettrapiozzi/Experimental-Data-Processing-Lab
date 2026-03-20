LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio8.2.cc VectorOperations.h EquazioniDifferenziali.h
	g++ -o esercizio8.2 esercizio8.2.cc ${INCS} ${LIBS} 

