SHLIB_FLAGS = -shared
LIB_SUFFIX = .so
ifeq ($(shell uname -s),Darwin)
SHLIB_FLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup
LIB_SUFFIX = .dylib
endif

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

LIB = $(TARGET)$(LIB_SUFFIX)

LIBFILE = ../libs/$(LIB)

LIBFILE: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SHLIB_FLAGS) $(OBJS) -o $(LIBFILE) 
	chmod 0644 $(LIBFILE)

clean:
	rm -f $(OBJS) $(LIBFILE)
