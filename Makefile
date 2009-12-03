CXXFLAGS += -Wall -O0 -fPIC -g
LDFLAGS += -Llibs/ -lenv -lobj -lchar -lgameengine -Wl,-rpath,libs/
SUBDIRS = engine char env obj

all: engine $(SUBDIRS) game

game: game.o playercontroller.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

