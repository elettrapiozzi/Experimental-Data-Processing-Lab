
LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)

all: esercizio12.cc EsperimentoPrisma.h RandomGen.h print.h EsperimentoPrisma.cc FunzioneBase.h
	g++ esercizio12.cc EsperimentoPrisma.cc -o esercizio12 ${INCS} ${LIBS}