all: array_swap 

perfstats.o: perfstats.c perfstats.h
	gcc -g -DHAVE_LINUX_PERF_EVENT_H -O3 $(EXTRA_OPTS) $(LIBS) -o perfstats.o -c perfstats.c

array_swap: swap.c perfstats.o
	gcc -DHAVE_LINUX_PERF_EVENT_H -O3 $(EXTRA_OPTS) perfstats.o -o array_swap swap.c

clean:
		rm -f array_swap *.o
