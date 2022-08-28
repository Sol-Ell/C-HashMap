#include <stdlib.h>

typedef struct Pair {
    int key;
    int value;
} Pair;

Pair* PairNew(int key, int value) {
    Pair* pair = malloc(sizeof(Pair));
    pair->key   = key;
    pair->value = value;
    
    return pair;
}

void PairFree(Pair* pair) {
    return free(pair);
}