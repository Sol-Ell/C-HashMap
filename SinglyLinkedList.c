#include <stdlib.h>

typedef struct SinglyLinkedList {
	void* data;
	struct SinglyLinkedList* next;
} SinglyLinkedList;

SinglyLinkedList* SinglyLinkedListNew(void* data, SinglyLinkedList* next) {
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    list->data = data;
    list->next = next;
    return list;
}

SinglyLinkedList* SinglyLinkedListGetLast(SinglyLinkedList* list) {
	while (list->next != NULL) {
		list = list->next;
	}
	
	return list;
}

void SinglyLinkedListFree(SinglyLinkedList* list, void (freeData)(void*)) {
    SinglyLinkedList* tmp = list;
    while (list) {
        tmp = list->next;
        freeData(list->data);
        free(list);
        list = tmp;
    }
}