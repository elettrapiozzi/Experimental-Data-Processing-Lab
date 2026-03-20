LIBS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --libs) 
INCS := $(shell PATH=/home/elettra/root/bin:$$PATH root-config --cflags)


main: main.cc 
	g++ -o main main.cc ${INCS} ${LIBS} 

clean:
	@rm -f main
	@echo "Everything has been cleaned"
