
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

LIB = $(TARGET).so

LIBFILE = ../libs/$(LIB)

LIBFILE: $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -shared $(OBJS) -o $(LIBFILE) -L ../libs -lgameengine
	chmod 0644 $(LIBFILE)

clean:
	rm -f $(OBJS) $(LIBFILE)
