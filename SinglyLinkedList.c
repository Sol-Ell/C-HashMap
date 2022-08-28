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

SinglyLinkedList* SinglyLinkedListFree(SinglyLinkedList* list, void (freeData)(void*)) {
    /**
     * @return next value of SinglyLinkedList
     * */
    SinglyLinkedList* next = list->next;
    freeData(list->data);
    free(list);
    return next;
}