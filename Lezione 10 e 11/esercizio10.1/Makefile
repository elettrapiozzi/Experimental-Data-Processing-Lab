LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio10.1.cc FunzioneBase.h RandomGen.h
	g++ -o esercizio10.1 esercizio10.1.cc ${INCS} ${LIBS} 

