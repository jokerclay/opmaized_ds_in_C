#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * definition of the Node of the linked list 
 *
 */
typedef struct Node{

    int data;               // data in the Node
    int *next;              // the ptr point to the next Node

} Node;


/* 
 * definition of linked list 
 *
 */
typedef struct LinkedList{

    Node head;              // ptr point to the Node
    int length;             // the  length of the LinkedList

} LinkedList;


/*
 * init of the Node of the linked list 
 *
 */

Node Node_init(int value) {
    // allocate some memory for the node
    int *p  = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
}


/* 
 * init of linked list 
 *
 */

LinkedList LinkedList_init(int size) {

    // allocate some memory for the LinkedList
    LinkedList *l =  (LinkedList *)malloc(sizeof(LinkedList));
    l-head.next   = NUll;
    l->length     = 0;

}


/*
 * clear the Node of the linked list 
 *
 */
void clear_node(Node *n) {

    // when there is no  Node exits
    if (n == NUll)  return ;

    free(n);

    return ;

}


/* 
 * clear linked list 
 *
 */

void clear_list(LinkedList *l) {

    // when there is no  LinkedList exits
    if (l == NUll)  return ;

    // clear each Node ass the LinkedList going 
    Node *p  = l->head.next;
    Node *q;

    // as  head.next isn't NULL, then keep going
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }

    free(l);

    return ;
}


int main() {


    return 0;
} 





