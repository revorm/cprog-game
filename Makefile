CXXFLAGS += -Wall -O2 -fPIC
LDFLAGS += -Llibs/ -lenv -lobj -lchar -lgameengine -Wl,-rpath libs/
SUBDIRS = char env obj

SHLIB_FLAGS = -shared
LIB_SUFFIX = .so
ifeq ($(shell uname -s),Darwin)
SHLIB_FLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup
LIB_SUFFIX = .dylib
endif


all: project_file engine $(SUBDIRS) game

project_file: cprog_game.files 
	./update_project_file.sh

engine: libs/libgameengine.so

game: game.o playercontroller.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 

libs/libgameengine$(LIB_SUFFIX): gameengine.cpp
	$(CXX) $(CXXFLAGS) $(SHLIB_FLAGS) gameengine.cpp -o ./libs/libgameengine$(LIB_SUFFIX) 
	chmod 0644 libs/libgameengine$(LIB_SUFFIX)

$(SUBDIRS):
	$(MAKE) CXXFLAGS="$(CXXFLAGS)" -C $@

.PHONY: $(SUBDIRS) clean

clean:
	rm -f *.o game libs/libgameengine$(LIB_SUFFIX)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

