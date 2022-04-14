#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX_OP  10  

/*
 * definition of stack
 *
 */
typedef struct stack{

    int *data;

    int top, size;

} stack;


/*
 * initialization of stack
 */

stack *stack_init(int size) {

    stack *s = (stack *)malloc(sizeof(stack));

    s->data = (int *)malloc(sizeof(int) * size);


    s->top = -1;

    s->size = size;

    return s;
}

/*
 * clear  stack
 */
void clear(stack *s) {

    if (s == NULL) return ;

    // because this stack we are implementing is base on arry
    // you can free the data one time

    free(s->data);

    free(s);

    return ;
}

/*
 * take a look at  the stack to see if is's empty
 */

int empty(stack *s) {

    if (s->top == -1) return 1;

    return 0;
}


/*
 * push value to stack
 */

// just move to one more that the top, and put your value there
int push(stack *s, int value) {

    printf("==> pushing %d\t to the stack ...\n", value);

    if (s == NULL) return 0;

    if (s->top + 1 == s->size) return 0;
    
    s->top += 1;

    s->data[s->top] = value;

    return 1;

}

/*
 * pop value from stack
 *
 */

int pop(stack *s) {

    printf("==> poping %d  from the  stack...\n", s->data[s->top]);
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

/*
 *  take a peek at the stack
 */

int peek(stack *s) {

    if(empty(s)) return 0;
     
    return s->data[s->top];
}

int main() {
    srand(time(0));

    printf("==> initializing stack...\n");
    stack *s = stack_init(MX_OP);

    printf("stack's size is %d\n", s->size);
    printf("stack is empty %d\n", empty(s));

    for (int i = 0; i < MX_OP; ++i) {
        push(s, rand() % 100);
    }

    printf("stack is empty %d\n", empty(s));

    printf("top of the stack is  %d\n", peek(s));

    for (int i = 0; i < MX_OP; ++i) {
        pop(s);
    }


    printf("stack is empty %d\n", empty(s));

    printf("==> cleared stack...\n");
    clear(s);

    return 0;
}
