LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

main: esercizio4.0.cc funzioni.h
	g++ esercizio4.0.cc -o esercizio4.0 ${INCS} ${LIBS} 
