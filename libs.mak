
LIB = $(TARGET).so

../libs/$(LIB): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -shared $(OBJS) -o ../libs/$(LIB) -L ../libs -lgameengine
	chmod 0644 ../libs/$(LIB)	

clean:
	rm -f $(OBJS) ../libs/$(LIB)
