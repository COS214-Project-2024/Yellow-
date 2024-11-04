run: main
	./main
	make c

main: *.o
	g++ -std=c++23  -o main *.o

*.o: *.cpp
	g++ -std=c++23  -c -w *.cpp

debugcpp: debugo
	g++ -std=c++23 -ggdb3 -fprofile-arcs -ftest-coverage -o main *.o

debugo: *.cpp
	g++ -std=c++23 -ggdb3 -fprofile-arcs -ftest-coverage -c -w *.cpp

cov: 
	make main
	./main
	gcov *.cpp

# GDB target to run the program in gdb
gdb: debugcpp
	gdb -q ./main

# GDB target to run gdb and immediately start execution
gdb-run: debugcpp
	gdb -q -ex run ./main

doxygenCreate:
	mkdir docs
	cd docs/
	doxygen -g

doxygenFiles:
	doxygen ./docs/Doxyfile
v: 
	make debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
	make c

c:
	rm *.o main *.gcda *.gcno *.gcov
