# CODE
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX_OP 10

/*
 * define the structure of vector
 */

typedef struct vector{
    int *data;
    int size, length;
} vector;

/*
 * init a vector:
 *
 *  you can use this function when you declare a vector type verible with a
 *  number of the vector's size, the following property that vector will have
 *
 *      - get memory of a vector 
 *      - get memory of the data in it
 *      - get the size of vector that user want to have
 *      - current vector length is 0
 *
 * @return it will return the address of the vector
 *
 */

vector *vector_init(int n) {

    printf("==> Init a vector size of %d ...\n", n);

    // allocate memory for a vector
    vector *vec = (vector *)malloc(sizeof(vector));

    // allocate memory for the data in the memory 
    vec->data = (int *)malloc(sizeof(int) * n);

    // set the size of the vector is n
    vec->size = n;

    // set the the vector's current length is 0
    vec->length = 0;

    return vec;
}

/*
 * clear the vector 
 */
void clear_vector(vector *vec) {

    // Every time we use vector as the parameter,
    // before we do anything, pls MAKE SUER the vector DO EXITE
    if (vec == NULL) return ;

    free(vec->data);
    free(vec);

    printf("==> Cleared a vector !\n");

    return ;
}

/*
 * expand the vector
 */
int expand(vector *vec) {
    int new_size = vec->size * 2;

    // relloc the memory the for data   
    int *p = (int *)realloc(vec->data, sizeof(int) * vec->size);

    // if failed
    if (p == NULL) return 0;

    vec->size = new_size;
    vec->data = p;

    return 1;
}


/*
 * Insert a element to the vector at certain position
 */

int vector_insert(vector *vec, int value, int position) {

    printf("==> Inserting value %d\t to  vector at %d \n",value, position);

    // 1. the vector don't exits
    if (vec == NULL) return 0;

    // 2. the vector is full of elements alreay, we expand our vector
    if (vec->size == vec->length) {

        // if failed to expand the vector, return 0;
        if(!expand(vec)) return 0;
        printf("==> Sccuessly expand vector size to %d \n", vec->size);
    }

    // 3. the position is illegal
    if (position < 0 ) {
        printf("==> you may want to check the position, it's illegal\n");
    }


    // move all the elements 1 step back to the position 
    // get the position from the back
    for (int i = vec->length-1; i > position; i--) {
        vec->data[i] = vec->data[i-1];
    }

    //put the value we passed in into the position
    vec->data[position] = value;

    // the length of the vector become 1 longer 
    vec->length += 1;

    // 1 means sccuessly inserted 
    return 1;
}


/*
 * erase a element from the vector 
 */
int erase(vector *vec, int position) {
    printf("==> Erasing value at %d in the vector\n", position);

    // 1. the vector don't exits
    if (vec == NULL) return 0;

    // 2. there is on elements in the vector
    if (vec->length == 0) {
        printf("==> there is no elements in the vector...");
    }

    // make all the elements after the position 1 step forward
    for (int i = position; i < vec->length; ++i) {
        vec->data[i-1] = vec->data[i];
    }

    vec->length -= 1;
    printf("==> value has been eraseed!\n");
    return 1;
}

/*
 * take a look at the vector 
 */
void output(vector *vec) {

    printf("==> Print the content in the vector...");
    printf("\n\n[");
    for (int i = 0; i < vec->length; ++i) {
        printf("%d, ", vec->data[i]);
    }
    printf("]\n\n");
}

/*
 * take a look at the front 
 */

void front(vector *vec) {
    printf("==> Print the front of the vector...");
    printf("\n\n[");
        printf("%d, ", vec->data[0]);
    printf("]\n\n");
}

/*
 * take a look at the back 
 */
void back(vector *vec) {
    printf("==> Print the back of the vector...");
    printf("\n\n[");
        printf("%d, ", vec->data[vec->length - 1]);
    printf("]\n\n");
}

/*
 * take a look at certain position
 */
void position(vector *vec, int position) {
    printf("==> Print the value at %d in the vector...", position);
    printf("\n\n[");
        printf("%d, ", vec->data[position - 1]);
    printf("]\n\n");
}

int main() {
    // vector return a pointer, so you need declare it as a pointer
    vector *v = vector_init(MX_OP);

    printf("%d \n", v->size);
    printf("%d \n", v->length);

    output(v);

//    srand(time(0));
    srand(1);

    for (int i = 0; i < MX_OP; ++i) {
        vector_insert(v, rand()%100, i);
    }
   
    // what if we insert one more than the vector's size was give before
    vector_insert(v, 6969, 10);

    output(v);

    // when you try put a value in illegal position
    //vector_insert(v, 6969, -1);

    // when you want to take a look at the front of the vector
    front(v);

    // when you want to take a look at the back of the vector
    back(v);

    // when you want to take a look at position 5 of the vector
    position(v, 5);
    output(v);

    // when you want to erase the element at position 5 of the vector
    erase(v, 5);
    output(v);

    // clear the  vector
    clear_vector(v);

    return 0;
}

```


# RES

```txt
==> Init a vector size of 10 ...
10 
0 
==> Print the content in the vector...

[]

==> Inserting value 83	 to  vector at 0 
==> Inserting value 86	 to  vector at 1 
==> Inserting value 77	 to  vector at 2 
==> Inserting value 15	 to  vector at 3 
==> Inserting value 93	 to  vector at 4 
==> Inserting value 35	 to  vector at 5 
==> Inserting value 86	 to  vector at 6 
==> Inserting value 92	 to  vector at 7 
==> Inserting value 49	 to  vector at 8 
==> Inserting value 21	 to  vector at 9 
==> Inserting value 6969	 to  vector at 10 
==> Sccuessly expand vector size to 20 
==> Print the content in the vector...

[83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 6969, ]

==> Print the front of the vector...

[83, ]

==> Print the back of the vector...

[6969, ]

==> Print the value at 5 in the vector...

[93, ]

==> Print the content in the vector...

[83, 86, 77, 15, 93, 35, 86, 92, 49, 21, 6969, ]

==> Erasing value at 5 in the vector
==> value has been eraseed!
==> Print the content in the vector...

[83, 86, 77, 15, 35, 86, 92, 49, 21, 6969, ]

==> Cleared a vector !
