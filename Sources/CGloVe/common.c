#include "glove.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int scmp( char *s1, char *s2 ) {
    while(*s1 != '\0' && *s1 == *s2) {s1++; s2++;}
    return(*s1 - *s2);
}

int find_arg(char *str, int argc, char **argv) {
    int i;
    for (i = 1; i < argc; i++) {
        if(!scmp(str, argv[i])) {
            if (i == argc - 1) {
                printf("No argument given for %s\n", str);
                exit(1);
            }
            return i;
        }
    }
    return -1;
}

/* Generate uniformly distributed random long ints */
long rand_long(long n) {
    long limit = LRAND_MAX - LRAND_MAX % n;
    long rnd;
    do {
        rnd = ((long)RAND_MAX + 1) * (long)rand() + (long)rand();
    } while (rnd >= limit);
    return rnd % n;
}

/* Write contents of array to binary file */
int write_chunk(CREC *array, long long size, FILE *fout) {
    long i = 0;
    for(i = 0; i < size; i++) fwrite(&array[i], sizeof(CREC), 1, fout);
    return 0;
}
