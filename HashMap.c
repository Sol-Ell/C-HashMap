#include <stdlib.h>
#include "Pair.c"
#include "SinglyLinkedList.c"

typedef struct HashMap {
    size_t size;
    SinglyLinkedList** data;
} HashMap;

size_t HashMapHashFunc(int key, int map_size) {
    return (size_t)key % map_size;
}

HashMap* HashMapNew(size_t size) {
    HashMap* map = malloc(sizeof(HashMap));
    
    map->size = size;
    map->data = malloc(sizeof(SinglyLinkedList*) * map->size);
    for (size_t i = 0; i < size; i++) {
        map->data[i] = NULL;
    }
    
    return map;
}

Pair* HashMapGetPairPointer(HashMap* map, int key) {
    /**
     * @return pointer to Pair or NULL if key not found
     * */
    size_t hash = HashMapHashFunc(key, map->size);

    SinglyLinkedList* list = map->data[hash];
    while (list != NULL) {
        Pair* pair = list->data;
        if (pair->key == key) {
            return pair;
        }
        list = list->next;
    }

    return NULL;
}

void HashMapInsert(HashMap* map, int key, int value) {
    size_t hash = HashMapHashFunc(key, map->size);
    SinglyLinkedList* list = SinglyLinkedListNew(PairNew(key, value), NULL);
    
    if (map->data[hash] == NULL) {
        map->data[hash] = list;
        return;
    }
    // check: if key exists change value, otherwise add
    Pair* pair = HashMapGetPairPointer(map, key);
    if (pair != NULL) {
        printf("Pair {key = %d, value = %d} found\n", pair->key, pair->value);
        pair->value = value;
    }

    SinglyLinkedListGetLast(map->data[hash])->next = list;

}

Pair* HashMapGetPair(HashMap* map, int key) {
    /**
     * @return Pair if key exists or NULL otherwise
     * */
    Pair* pair = HashMapGetPairPointer(map, key);
    return (pair == NULL) ? NULL : PairNew(pair->key, pair->value);
}

_Bool HashMapDelete(HashMap* map, int key) {
    /**
     * @return 1 if pair deleted 0 otherwise
     * */
    size_t hash = HashMapHashFunc(key, map->size);

    SinglyLinkedList* last_list = NULL;
    SinglyLinkedList* this_list = map->data[hash];

    while (this_list != NULL) {
        Pair* pair = this_list->data;
        if (pair->key == key) {
            break;
        }
        last_list = this_list;
        this_list = this_list->next;
    }

    if (this_list == NULL) {
        return 0;
    }

    if (last_list == NULL) {
        printf("last_list == NULL\n");
        map->data[hash] = this_list->next;
    } else {
        last_list->next = this_list->next;
    }
    SinglyLinkedListFree(this_list, free);

    return 1;
}