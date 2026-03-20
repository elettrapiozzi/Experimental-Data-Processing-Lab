LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio7.2.cc FunzioneBase.h Integral.h Trapezi.h
	g++ -o esercizio7.2 esercizio7.2.cc ${INCS} ${LIBS} 

