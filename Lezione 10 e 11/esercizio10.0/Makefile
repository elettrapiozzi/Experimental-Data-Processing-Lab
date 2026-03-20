LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio10.0.cc FunzioneBase.h RandomGen.h
	g++ -o esercizio10.0 esercizio10.0.cc ${INCS} ${LIBS} 

