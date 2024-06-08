#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node_t;

//
//  Traversal
void traversal(Node_t *ptr) {
    while(ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

//
//  Insertion at i
Node_t * insertionAt(Node_t *ptr, int position, int data) {
    Node_t *head = ptr;
    Node_t *new;
    new = (Node_t *) malloc(sizeof(Node_t));
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
void insertionAfter(Node_t *ptr, int position, int data) {
    Node_t *new;
    new = (Node_t *) malloc(sizeof(Node_t));
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
Node_t * Deletion(Node_t *ptr, int position) {
    if(position) {

        //case 1 & 3 -> Deletion in between and last
        Node_t *prev, *curr;
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
    Node_t *head;
    Node_t *second;
    Node_t *third;

    //  Allocate memory for the Nodes in linked list in Heap
    head = (Node_t *) malloc(sizeof(Node_t));
    second = (Node_t *) malloc(sizeof(Node_t));
    third = (Node_t *) malloc(sizeof(Node_t));

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