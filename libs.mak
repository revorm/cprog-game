SHLIB_FLAGS = -shared
LIB_SUFFIX = .so
ifeq ($(shell uname -s),Darwin)
SHLIB_FLAGS = -dynamiclib -Wl,-undefined,dynamic_lookup,-install_name,libs/$(LIBFILE)
LIB_SUFFIX = .dylib
endif

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

LIB = $(TARGET)$(LIB_SUFFIX)

LIBFILE = $(LIB)

LIBFILE: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SHLIB_FLAGS) $(OBJS) -o $(LIBFILE) 
	cp -f $(LIBFILE) ../libs/
	chmod 0644 ../libs/$(LIBFILE)

clean:
	rm -f $(OBJS) $(LIBFILE) ../libs/$(LIBFILE)
