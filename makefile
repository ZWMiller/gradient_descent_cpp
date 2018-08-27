
objects = sgdReressor.cpp sgdClassifier.cpp
BIN = $(patsubst %.cpp, %, $(SRC))

all: $(BIN)

clean: rm -f $(BIN)

.PHONY: all clean
