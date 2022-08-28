#include <stdio.h>
#include "HashMap.c"

int main(int argc, char const *argv[])
{
	HashMap* map = HashMapNew(50);
	HashMapInsert(map, 0, 24);
	HashMapInsert(map, 0, 24);
	HashMapInsert(map, 0, 24);
	HashMapInsert(map, 0, 24);
	HashMapInsert(map, 0, 24);
	Pair* pair = HashMapGetPair(map, 0);
	printf("key = %d, value = %d\n", pair->key, pair->value);
	printf("Deleting status: %d\n", HashMapDelete(map, 0));

	for (size_t i = 0; i < map->size; i++) {
		SinglyLinkedList* list = map->data[i];
		printf("map %zu list: %p\n", i, list);
		
		while (list != NULL) {
			Pair* pair = list->data;
			printf("\tSinglyLinkedList{ Pair{ key = %d, value = %d }, next = %p }\n", pair->key, pair->value, list->next);
			list = list->next;
		}
	}

	free(pair);
	return 0;
}