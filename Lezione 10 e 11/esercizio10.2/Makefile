LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio10.2.cc FunzioneBase.h Integrale.h RandomGen.h Funzioni.h
	g++ -o esercizio10.2 esercizio10.2.cc ${INCS} ${LIBS} 

