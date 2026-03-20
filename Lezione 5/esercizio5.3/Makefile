LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio5.3.cc CampoVettoriale.cc CampoVettoriale.h Elettrone.cc Elettrone.h Particella.cc Particella.h Posizione.cc Posizione.h PuntoMateriale.cc PuntoMateriale.h
	g++ esercizio5.3.cc CampoVettoriale.cc Elettrone.cc Particella.cc  Posizione.cc PuntoMateriale.cc -o esercizio5.3 ${INCS} ${LIBS} 

