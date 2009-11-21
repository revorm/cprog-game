CXXFLAGS += -Wall -O2 -fPIC
LDFLAGS += -Llibs/ -lenv -lobj -lchar -lgameengine -Wl,-R libs/
SUBDIRS = char env obj

all: project_file engine $(SUBDIRS) game

project_file: cprog_game.files 
	./update_project_file.sh

engine: libs/libgameengine.so

game: game.cpp

libs/libgameengine.so: gameengine.o
	$(CXX) $(CXXFLAGS) -shared gameengine.o -o ./libs/libgameengine.so 
	chmod 0644 libs/libgameengine.so

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

