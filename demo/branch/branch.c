#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int __attribute__((noinline)) call_when_true(uint64_t *data)
{
    *data = *data*2;
    return 0;
};
int __attribute__((noinline)) call_when_false(uint64_t *data)
{
    *data += 2;
    return 0;
};

int __attribute__((noinline,O0)) loop(uint64_t *data, int size)
{
    int i = 0;
    do {
        if( data[i] % 2 != 0)
            data[i] *= 2;
        data[i] += i;
    } while(++i < size);
};

int main(int argc, char **argv)
{
    FILE *fin;
    int size,i;
    uint64_t *data;
    uint64_t threshold;
    fin = fopen(argv[1],"r");
    size = atoi(argv[2]);
    threshold = atoi(argv[3]);
    data = (uint64_t *)malloc(sizeof(uint64_t)*size);
    fread(data, sizeof(uint64_t),size,fin);
    for(i=0;i<size;i++)
    {
        if (data[i] % 2 != 0)
            call_when_true(&data[i]);
        else
            call_when_false(&data[i]);
    }
    return 0;
}