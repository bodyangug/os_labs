#include <stdlib.h>
#include <stdio.h>
#include "lib/arrayList.h"

void printList(ArrayList* list);

int main(int argc, char const *argv[]){
    ArrayList* list = newArrayList();

    printf("Add operation\n");
    for (size_t i = 0; i < 10; i++){
        list->add(list,i);
        printList(list);
    }

    printf("Insert operation\n");
    list->insert(list,5,9999);
    printList(list);
    
    printf("Remove operation\n");
    list->removeItem(list,5);
    printList(list);
    
    printf("Set operation\n");
    list->set(list,5,500);
    printList(list);
    
    return 0;
}

void printList(ArrayList* list){
    for (size_t i = 0; i < list->size(list); i++){
        printf("%d  ", list->get(list,i));
    }
    printf("\n");
}
