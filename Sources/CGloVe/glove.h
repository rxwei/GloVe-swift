#ifndef _GLOVE_H_
#define _GLOVE_H_

#include <stdio.h>
#include <stdlib.h>

typedef double real;

static const long LRAND_MAX = ((long) RAND_MAX + 2) * (long)RAND_MAX;

typedef struct vocabulary {
    char *word;
    long long count;
} VOCAB;

typedef struct hashrec {
    char *word;
    long long count;
    struct hashrec *next;
} HASHREC;

typedef struct cooccur_rec {
    int word1;
    int word2;
    real val;
} CREC;

typedef struct cooccur_rec_id {
    int word1;
    int word2;
    real val;
    int id;
} CRECID;

int scmp(char *s1, char *s2);
int find_arg(char *str, int argc, char **argv);
unsigned int bitwisehash(char *word, int tsize, unsigned int seed);
HASHREC ** inithashtable();
void hashinsert(HASHREC **ht, char *w);
void hashinsert_id(HASHREC **ht, char *w, long long id);
HASHREC *hashsearch(HASHREC **ht, char *w);
long rand_long(long n);
int write_chunk(CREC *array, long long size, FILE *fout);
int compare_crec(const void *a, const void *b);

#endif // _GLOVE_H_
