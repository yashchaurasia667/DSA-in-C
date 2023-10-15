#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

//
//  Traversal
void traversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

//
//  Insertion at i
struct Node * insertionAt(struct Node *ptr, int position, int data) {
    struct Node *head = ptr;
    struct Node *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = data;

    if(position-1) {

        while(position-2) {
            ptr = ptr->next;
            position--;
        }

        new->next = ptr->next;
        ptr->next = new;

        return head;
    }
    
    else {
        new->next = ptr;
        return new;
    }
}

//
//  Insertion after i
void insertionAfter(struct Node *ptr, int position, int data) {
    struct Node *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = data;

    while(position-1) {
        ptr = ptr->next;
        position--;
    }

    new->next = ptr->next;
    ptr->next = new;
}

//
//  Deletion
struct Node * Deletion(struct Node *ptr, int position) {
    if(position) {

        //case 1 & 3 -> Deletion in between and last
        struct Node *prev, *curr;
        prev = ptr;
        curr = ptr->next;

        while(position-1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        prev->next = curr->next;
        return ptr;
    }

    //  case 2 -> Deletion of the head
    else
        return ptr->next;
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //  Allocate memory for the Nodes in linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;        // Linking head to the second node


    second->data = 8;
    second->next = third;        // Linking head to the second node


    third->data = 9;
    third->next = NULL;        // Linking head to the second node

    head = insertionAt(head, 3, 41);

    head = Deletion(head, 2);
    traversal(head);

    return 0;
}