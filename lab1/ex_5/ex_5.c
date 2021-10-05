#include <stdlib.h>
#include <stdio.h>
#include "lib/linkedList.h"

void printList(LinkedList* list);

int main(int argc, char const *argv[]){
    LinkedList* list = newLinkedList();

    printf("Add operation\n");
    for (size_t i = 0; i < 10; i++){
        list->add(list,i);
        printList(list);
    }

    printf("Insert operation\n");
    list->insert(list,0,9999);
    printList(list);
    
    printf("Remove operation\n");
    list->removeItem(list,0);
    printList(list);
    
    printf("Set operation\n");
    list->set(list,5,500);
    printList(list);
    
    printf("Remove operation\n");
    list->removeItem(list,5);
    printList(list);

    return 0;
}

void printList(LinkedList* list){
    Node* tmp = list->root; 
    for (size_t i = 0; i < list->size(list); i++){
        printf("%d  ", list->get(list,i));
    }
    printf("\n");
  
}
