#ifndef VECTOR_H_
#define VECTOR_H_

#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct vector
{
  int size;
  struct data **array;
};

// This function will create a pointer to struct vector, initialize its size with 0 and array with NULL and return the pointer
struct vector* createVector();

// This function will add a new data element to the front of array
void addFront(struct vector *vec,struct data *dta);

// This function will remove an element on the last position of array 
void removeBack(struct vector *vec);

// Function to print the values of array in vector
void printVector(struct vector *vec);

// Function to add a new element to the back of array
void addBack(struct vector *vec,struct data *dta);

// Function to remove the first element from the array
void removeFront(struct vector *vec);

// This function will get the sum of all of the the data structs in the vector.
float sumVector(struct vector *vec);

/* This function will create a copy (deep copy)of the input vector. 
The new vector will have it's own independent data elements and will not share pointers with the input vector. 
*/
struct vector* cloneVector(struct vector *vec);

/* This function will compare two vectors and return 1 if they are the same and 0 if they are not.
Two vectors are said to be equal if they have the same size and the data elements at each position in the array are the same.
So for example vec1->array[0] = vec2->array[0], vec1->array[1] = vec2->array[1], ...,vec1->array[n] = vec2->array[n].
*/
int compareVectors(struct vector *vec1,struct vector *vec2);

// This function will reverse the elements in the vector's array
void reverseVector(struct vector *vec);

// This function will free all memory associated with the vector.
void cleanVector(struct vector *vec);

#endif
