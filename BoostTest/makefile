CXX = g++
CXXFLAGS = -std=c++17

TARGET = Test_case
SRC = Test_case.cpp
LIBS = -lboost_unit_test_framework

compile:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LIBS)

run: compile
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o