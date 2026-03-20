LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio7.0.cc FunzioneBase.h Integral.h Midpoint.h
	g++ -o esercizio7.0 esercizio7.0.cc ${INCS} ${LIBS} 

