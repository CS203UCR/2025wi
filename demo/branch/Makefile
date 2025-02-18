all: arraySort bstSearch

perfstats.o: perfstats.c perfstats.h
	gcc -g -DHAVE_LINUX_PERF_EVENT_H -O3 $(EXTRA_OPTS) -I$(PWD) $(LIBS) -o perfstats.o -c perfstats.c

calculate_sum.o: calculate_sum.c
	gcc -g -DHAVE_LINUX_PERF_EVENT_H -O0 $(EXTRA_OPTS) -I$(PWD) $(LIBS) -o calculate_sum.o -c calculate_sum.c

arraySort: arraySort.cpp calculate_sum.o perfstats.o
	g++ -O3 -DHAVE_LINUX_PERF_EVENT_H $(EXTRA_OPTS) arraySort.cpp perfstats.o calculate_sum.o -o arraySort

bst.o: bst.cpp
	g++ -g -DHAVE_LINUX_PERF_EVENT_H -O0 $(EXTRA_OPTS) -I$(PWD) $(LIBS) -o bst.o -c bst.cpp

bstSearch: bstSearch.cpp bst.o perfstats.o
	g++ -O3 -DHAVE_LINUX_PERF_EVENT_H $(EXTRA_OPTS) bstSearch.cpp perfstats.o bst.o -o bstSearch


clean:
		rm -f madd arraySort *.o
