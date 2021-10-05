#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"

int defaultLenght = 16;

Node* getLastNode(Node* root){
    if (root == NULL){
        return root;
    }
    Node* point = root;

    while (point->next != NULL){
        point = point->next;
    }
    return point;
}

Node* getNodeByIndex(Node* root, int index){
    Node* point = root;

    if (root == NULL){
        return root;
    }

    for (int i = 0;point->next != NULL;i++){
        if (i == index){
            return point;
        } 
        point = point->next;
    }
    return point;
}

void add (LinkedList* list, int item){
    Node* newNode = malloc(sizeof(Node));
    newNode->val = item;
    newNode->next = NULL;

    if (list->root == NULL){
        list->root = newNode;
    }else{
        Node* last = getLastNode(list->root); 
        last->next = newNode;
    }

    list->lenght++;
}

void insert(LinkedList* list, int index, int item){
    if (list->root == NULL){
        printf("List is empty");
        return;
    }
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->val = item;

    if(index <= 0){
        newNode->next = list->root;
        list->root = newNode;
    }else{
        Node* node = getNodeByIndex(list->root,index-1);
        newNode->next = node->next;
        node->next = newNode;

        printf("Node val = %d\n", node->val);  
    }

    list->lenght++;
}

void removeItem(LinkedList* list, int index){
    if (list->root == NULL){
        printf("List is empty");
        return;
    }
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }

    Node* removedNode;
    if(index <= 0){
        removedNode = list->root;
        list->root = list->root->next;
    }else{
        Node* removedNodeParent= getNodeByIndex(list->root,index-1);
        removedNode = removedNodeParent->next;
        removedNodeParent->next = removedNode->next;
    }
    free(removedNode);
    list->lenght--;
}

void set(LinkedList* list, int index, int item){
    if (list->root == NULL){
        printf("List is empty");
        return;
    }
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return;
    }
    getNodeByIndex(list->root, index)->val = item;
}

int get(LinkedList* list, int index){
    if (list->root == NULL){
        printf("List is empty");
        return 0;
    }
    
    if (index >= list->lenght || index < 0){
        printf("ArrayIndexOutOfBoundsException: %d size: %d", index, list->lenght);
        return 0;
    }
    return getNodeByIndex(list->root, index)->val;
}

int size (LinkedList* list){
    return list->lenght;
}

LinkedList* newLinkedList(){
    LinkedList * list = malloc(sizeof(LinkedList));
    list->root = NULL;
    list->lenght = 0;

    list->add = add;
    list->size = size;
    list->insert = insert;
    list->get = get;
    list->set = set;
    list->removeItem = removeItem;

    return list;
}

