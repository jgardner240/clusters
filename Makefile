DirAppRoot           ?= .
DirAppOutput         ?= $(DirAppRoot)/output

SOURCES = $(wildcard $(DirAppRoot)/*.c)
OPTS = -std=c99
all:
	@mkdir -p $(DirAppOutput) 
	gcc $(OPTS) -o $(DirAppOutput)/clusters $(SOURCES)
	
clean:
	rm -f $(DirAppOutput)/*
    
