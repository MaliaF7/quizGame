COMPILER = g++
OPTIONS = -Wall
PROGRAM = main.out 

all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM) database.txt

$(PROGRAM): main.cpp printResult.cpp Quiz.cpp
		$(COMPILER) $(OPTIONS) main.cpp printResult.cpp Quiz.cpp -o $(PROGRAM)

clean:
	rm -f *.out