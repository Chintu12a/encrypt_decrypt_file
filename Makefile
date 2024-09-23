CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall

SRC = src/encryptor.cpp src/decryptor.cpp src/main.cpp
INCLUDE = include/
TARGET = parallel-encryptor-decryptor

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
