
LIB = $(TARGET).so

../$(LIB): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -shared $(OBJS) -o ../$(LIB)
	chmod 0644 ../$(LIB)	

clean:
	rm -f $(OBJS) ../$(LIB)
