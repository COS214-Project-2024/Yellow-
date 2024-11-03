# run: main
# 	./main
# 	make c

# main: *.o
# 	g++ -std=c++20 -fprofile-arcs -ftest-coverage -o main *.o

# *.o: *.cpp
# 	g++ -std=c++20 -fprofile-arcs -ftest-coverage -c -w *.cpp

# debugcpp: debugo
# 	g++ -std=c++20 -ggdb3 -fprofile-arcs -ftest-coverage -o main *.o

# debugo: *.cpp
# 	g++ -std=c++20 -ggdb3 -fprofile-arcs -ftest-coverage -c -w *.cpp

# cov: 
# 	make main
# 	./main
# 	gcov *.cpp

# doxygenCreate:
# 	mkdlr docs
# 	cd docs/
# 	doxygen -g

# doxygenFiles:
# 	doxygen ./docs/Doxyfile
# v: 
# 	make debugcpp
# 	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
# 	make c

# c:
# 	rm *.o main *.gcda *.gcno *.gcov

CXX = g++ -g
CXXFLAGS = -std=c++20 -fprofile-arcs -ftest-coverage -Wall
LDFLAGS = -fprofile-arcs -ftest-coverage

SRCS = main.cpp HistoryBranch.cpp HistoryNode.cpp
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: main
	./main

debugcpp: $(OBJS)
	$(CXX) -std=c++20 -ggdb3 $(LDFLAGS) -o main $(OBJS)

cov: 
	make main
	./main
	gcov *.cpp

doxygenCreate:
	mkdir docs
	cd docs/
	doxygen -g

doxygenFiles:
	doxygen ./docs/Doxyfile

v: debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main

clean:
	rm -f *.o main *.gcda *.gcno *.gcov