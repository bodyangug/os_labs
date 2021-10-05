#include <stdio.h>
#include <stdlib.h>
#include "../arrayList.h"

int defaultLenght = 16;

void resizeList(ArrayList* list){
    size_t newLen = (list->realSize * 1.5);
    list->arr = (int*)realloc(list->arr,newLen * sizeof(int));
    list->realSize = newLen;
}

void add (ArrayList* list, int item){        
    if (list->realSize <= list->lenght){
        resizeList(list);
    }
    
    list->arr[list->lenght] = item;
    list->lenght++;
}

void insert(ArrayList* list, int index, int item){
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }
    if (list->realSize <= list->lenght){
        resizeList(list);
    }

    for (size_t i = list->lenght; i > index; i--){
        list->arr[i] = list->arr[i-1];
    }
    list->arr[index] = item;
    list->lenght++;
}

void removeItem(ArrayList* list, int index){
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }

    for (size_t i = index; i < list->lenght; i++){
        list->arr[i] = list->arr[i+1];
    }
    list->lenght--;
}

void set(ArrayList* list, int index, int item){
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }
    list->arr[index] = item;
}

int get(ArrayList* list, int index){
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return 0;
    }
    return list->arr[index];
}

int size (ArrayList* list){
    return list->lenght;
}

ArrayList* newArrayList(){
    ArrayList * list = malloc(sizeof(ArrayList));
    list->arr = malloc(sizeof(int)* defaultLenght);
    list->lenght = 0;
    list->realSize = defaultLenght;

    list->add = add;
    list->size = size;
    list->insert = insert;
    list->get = get;
    list->set = set;
    list->removeItem = removeItem;

    return list;
}
