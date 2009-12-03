CXXFLAGS += -Wall -O2 -fPIC
LDFLAGS += -Llibs/ -lenv -lobj -lchar -lgameengine -Wl,-rpath,libs/
SUBDIRS = char env obj

SHLIB_FLAGS = -shared
LIB_SUFFIX = .so
ifeq ($(shell uname -s),Darwin)
SHLIB_FLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup
LIB_SUFFIX = .dylib
endif


all: engine $(SUBDIRS) game

engine: libs/libgameengine$(LIB_SUFFIX)

game: game.o playercontroller.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 

libs/libgameengine$(LIB_SUFFIX): gameengine.cpp
	$(CXX) $(CXXFLAGS) $(SHLIB_FLAGS) $^ -o $@
	chmod 0644 $@

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game libs/libgameengine$(LIB_SUFFIX)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

