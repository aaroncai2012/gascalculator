.PHONY : clean

gascalculator : gascalculator.exe

gascalculator.exe : source.cc			\
		interface.cc
	g++ -g -std=c++11 $^ -o gascalculator.exe

clean :
	rm *.exe
