LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio7.1.cc FunzioneBase.h Integral.h Simpson.h
	g++ -o esercizio7.1 esercizio7.1.cc ${INCS} ${LIBS} 

