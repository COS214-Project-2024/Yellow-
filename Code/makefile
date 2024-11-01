run: main
	./main
	make c

main: *.o
	g++ -std=c++20 -o main *.o

*.o: *.cpp
	g++ -std=c++20 -c -w *.cpp

debugcpp: debugo
	g++ -std=c++20 -ggdb3 -o main *.o
	gdb ./main

debugo: *.cpp
	g++ -std=c++20 -ggdb3 -c -w *.cpp

cov: 
	make main
	./main
	gcov *.cpp

doxygenCreate:
	mkdlr docs
	cd docs/
	doxygen -g

doxygenFiles:
	doxygen ./docs/Doxyfile
v: 
	make debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
	make c

c:
	rm *.o

cgov:
	rm *.o main *.gcda *.gcno *.gcov
