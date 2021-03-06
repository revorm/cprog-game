CXXFLAGS = -Wall -O0 -fPIC -g

ifneq ($(shell uname -s),Darwin)
RPATH_FLAGS = -Wl,-R,libs
endif

LDFLAGS = -Llibs/ -lenv -lobj -lchar -lgameengine $(RPATH_FLAGS)
SUBDIRS = engine char env obj

all: engine $(SUBDIRS) game

game: game.o playercontroller.o playercommands.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

