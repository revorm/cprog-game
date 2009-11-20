CXXFLAGS += -Wall -O2 -fPIC
LDFLAGS += -L. -lenv -lobj -lchar -Wl,-rpath=$(shell pwd)
SUBDIRS = char env obj

all: project_file $(SUBDIRS) game 

project_file: cprog_game.files 
	./update_project_file.sh

game: game.cpp gameengine.o

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

