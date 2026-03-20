LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio8.3.cc VectorOperations.h EquazioniDifferenziali.h
	g++ -o esercizio8.3 esercizio8.3.cc ${INCS} ${LIBS} 

