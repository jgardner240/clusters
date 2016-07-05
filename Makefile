DirAppRoot           ?= .
DirAppOutput         ?= $(DirAppRoot)/output

SOURCES = $(wildcard $(DirAppRoot)/*.c)

all:
	@mkdir -p $(DirAppOutput) 
	gcc -o $(DirAppOutput)/clusters $(SOURCES)
	
clean:
	rm -f $(DirAppOutput)/*
    
