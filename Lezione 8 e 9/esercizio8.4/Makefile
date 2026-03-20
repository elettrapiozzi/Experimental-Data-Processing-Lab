LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio8.4.cc VectorOperations.h EquazioniDifferenziali.h
	g++ -o esercizio8.4 esercizio8.4.cc ${INCS} ${LIBS} 

