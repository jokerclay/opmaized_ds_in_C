# CODE
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX_OP 10

/*
 * definition of the Node of the linked list 
 *
 */
typedef struct Node{

    int data;               // data in the Node
    Node *next;              // the ptr point to the next Node

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

Node *Node_init(int value) {
    // allocate some memory for the node
    Node *p  = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->next = NULL;
    // return the node after initialization
    return p;
}


/* 
 * init of linked list 
 *
 */

LinkedList *LinkedList_init() {
    // allocate some memory for the LinkedList
    LinkedList *l =  (LinkedList *)malloc(sizeof(LinkedList));

    l->head.next   = NULL;
    l->length     = 0;

    // return the LinkedList after initialization
    return l;

}

/*
 * clear the Node of the linked list 
 *
 */

void clear_node(Node *n) {

    // when there is no  Node exits
    if (n == NULL)  return ;

    free(n);

    return ;

}

/* 
 * clear linked list 
 *
 */

void clear_list(LinkedList *l) {

    // when there is no  LinkedList exits
    if (l == NULL)  return ;

    // clear each Node as the LinkedList going 
    Node *p  = l->head.next;
    Node *q;

    // as long as head.next isn't NULL,it'means it's not the end,then keep going
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }

    free(l);

    printf("==> Cleared  LinkedList ! \n");

    return ;
}


/* 
 * insert value to a linked list 
 *
 */

int insert(LinkedList *l, int value, int position) {
    printf("==> Inserting %d to LinkedList... \n", value);

    // make sure the list does exits   
    if (l == NULL) return 0;

    // the position is illegal
    if (position < 0 || position > l->length) return 0;

    // insert
    // TODO fingure is frindly code out
    
    // get the address at the start point
    Node *p = &(l->head);

    // turn the value into a node with that value  
    Node *n = Node_init(value);

    // goto the position you are going put the value
    while (position--) {
        p = p->next;
    }

    //  make the new created node's next ptr point to the node which next to
    //  the position you are going to put
    n->next = p ->next;

    // cut off the orginal position's node point to his's old next node
    // insead, make the position's node point to the new created node
    // then, the node will be insert into the list
    p->next = n;


    // make the length 1 longer
    l->length += 1;

    // 1 means it's worked
    return 1;
}

/* 
 * erase a node from LinkedList at certain position
 *
 */

// just point over the position's node 

int erase(LinkedList *l, int position) {
    printf("==> Ereasing the value at %d \n",position);
    if (l == NULL) return 0;

    if (l->length == 0) return 0;

    Node *p = &(l->head);

    Node *q;

    while(position--) {
        p = p->next;
    }

    q = p->next->next;

    clear_node(p->next);

    p->next = q;

    l->length += 1;

    return 1;
}



/* 
 * print out the  LinkedList
 *
 */

void output (LinkedList *l) {
    printf("\n==> Printing a LinkedList ... \n");
    printf("LinkedList(%d):\n", l->length);

    // for loop, there is something you need to know :

    /*
     *  for (expression_1; expression_2; expression_3) {
     *
     *      loop body expression
     *  }
     *
     */
    
    /* here is how it execuse:
     *
     * first -> execuse expression_1;
     * then  -> execuse expression_2;
     * if expression_2 is TRUE => execuse loop body, FALSE end the loop
     * ->execuse expression_3,
     * -> execuse expression_2, until expression_2 is FALSE
     *
     */

    // as long as p's next is not NULL, then keep going down
    for (Node *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
        printf("NULL\n\n");

    return ;
}

int main() {

    // get random seed
    srand(time(0));

    LinkedList *l = LinkedList_init();

    printf("==> Initializing a LinkedList ... \n");

    printf("list's length is %d\n", l->length);
    printf("list's Virual Node data is %d\n", l->head.data);

    for (int i = 0; i < MX_OP; ++i) {
        insert(l, rand() % 100, i);
    }

    output(l);

    erase(l, 3);

    output(l);



    clear_list(l);

    return 0;
} 
```



# RES

```txt
==> Initializing a LinkedList ... 
list's length is 0
list's Virual Node data is 0
==> Inserting 86 to LinkedList... 
==> Inserting 11 to LinkedList... 
==> Inserting 27 to LinkedList... 
==> Inserting 96 to LinkedList... 
==> Inserting 24 to LinkedList... 
==> Inserting 80 to LinkedList... 
==> Inserting 75 to LinkedList... 
==> Inserting 95 to LinkedList... 
==> Inserting 8 to LinkedList... 
==> Inserting 36 to LinkedList... 

==> Printing a LinkedList ... 
LinkedList(10):
86 -> 11 -> 27 -> 96 -> 24 -> 80 -> 75 -> 95 -> 8 -> 36 -> NULL

==> Ereasing the value at 3 

==> Printing a LinkedList ... 
LinkedList(11):
86 -> 11 -> 27 -> 24 -> 80 -> 75 -> 95 -> 8 -> 36 -> NULL

==> Cleared  LinkedList ! 
```
