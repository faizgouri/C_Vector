#include "vector.h"

struct vector* createVector()
{

	struct vector *v = malloc(sizeof(struct vector));
	v -> size = 0;
	v -> array = NULL;

	return v;

}

void addFront(struct vector *vec, struct data *dta)
{

	int i = 0;
	// increment size of array
	vec -> size++;

	// create a temporary data pointer
	struct data **temp;

	// copy old array to temp
	temp = vec -> array;

	// allocate new space for array
	vec -> array = malloc(vec -> size * sizeof(struct data *));

	// assign data to 0th poistion of array
	vec -> array[0] = dta;

	// copy old array elements to next position
	for(i = 1; i < vec -> size; ++i)
	{

		vec -> array[i] = temp[i - 1];

	}

	// free temp
	free(temp);

}

void printVector(struct vector *vec)
{

	int i = 0;

	for(i = 0; i < vec -> size; ++i)
	{

		printData(vec -> array[i]);

	}
	printf("\n");
}


void removeBack(struct vector *vec)
{

	int i = 0;

	// create a temp array and copy the array to temp
	struct data **temp = vec -> array;

	// free space occupied by the last element of array
	free(vec -> array[vec -> size -1]);

	// decrement size by 1
	vec -> size--;

	// allocate new memory for modified size 
	vec-> array = malloc((vec -> size) * sizeof(struct data *));

	// copy contents from temp to array
	for(i = 0; i < vec -> size; ++i)
	{

		vec -> array[i] = temp[i];

	}

	// free temp
	free(temp);

/*
	// Alternate approach
	free(vec -> array[vec -> size -1]);
	vec -> size--;
*/
}

void addBack(struct vector *vec,struct data *dta)
{

	 int i = 0;

        // increment size of array
        vec -> size++;

        // create a temporary data pointer
        struct data **temp;

        // copy old array to temp
        temp = vec -> array;

        // allocate new space for array
        vec -> array = malloc(vec -> size * sizeof(struct data *));

        // copy old array elements to next position
        for(i = 0; i < (vec -> size - 1); ++i)
        {

                vec -> array[i] = temp[i];

        }

	// assign data to the last poistion of array
        vec -> array[vec -> size - 1] = dta;

	free(temp);

}

void removeFront(struct vector *vec)
{


	int i = 0;

        // create a temp array and copy the array to temp
        struct data **temp = vec -> array;

        // decrement size by 1
        vec -> size--;

	// free space occupied by the front element of array
        free(vec -> array[0]);

        // allocate new memory for modified size
        vec-> array = malloc((vec -> size) * sizeof(struct data *));

        // copy contents from temp to array
        for(i = 0; i < vec -> size; ++i)
        {

                vec -> array[i] = temp[i + 1];

        }

        // free temp
        free(temp);


}

float sumVector(struct vector *vec)
{

	int i = 0;
	float sum = 0.0;

	for(i = 0; i < vec -> size; ++i)
	{

		sum = sum + sumData(vec -> array[i]);

	}

	return sum;

}

struct vector* cloneVector(struct vector *vec)
{

	int i = 0;

	// create a vector pointer and allocate memory equals to input vector
	struct vector *clone = createVector();

	// allocate memory to the array variable of newly created vector
	clone -> array = malloc(vec -> size * sizeof(struct data*));

	// allocate memory to each data in arrar and copy the contents from vec.
	for(i = 0; i < vec -> size; ++i)
	{

		clone -> array[i] = createData(vec -> array[i] -> v1, vec -> array[i] -> v2);

	}

	// copy size
	clone -> size = vec -> size;

	return clone;

}

int compareVectors(struct vector *vec1,struct vector *vec2)
{


	int i = 0;

	// procees further only if both vectors size is equal
	if(vec1 -> size == vec2 -> size)
	{

		// iterate through each element in array
		for(i = 0; i < vec1 -> size; ++i)
		{

			// if there is a mismatch, return 0
			if(!compareData(vec1 -> array[i],vec2 -> array[i]))
			{

				return 0;

			}

		}

		// check if we have iterated all the elements and there was no mismatch, this assures the values are same. So, return 1.
		if(i == vec1 -> size)
		{

			return 1;

		}

	}
	// return 0 otherwise
	return 0;

}

void reverseVector(struct vector *vec)
{

	int i = 0;

	// take one temp data pointer to use while swapping the elements
	struct data *tempData = NULL;

	// reverse only if there is more than 1 element in array
	if(vec -> size > 1)
	{
		for(i = 0; i <= ((vec -> size - 1) / 2); ++i)
		{

			tempData = vec -> array[i];
			vec -> array[i] = vec -> array[vec -> size - 1 - i];
			vec -> array[vec -> size - 1 - i] = tempData;

		}
	}


}

void cleanVector(struct vector *vec)
{

	int i = 0;

	// first free memory occupied by elements if array
	for(i = 0; i < vec -> size; ++i)
	{

		free(vec -> array[i]);
	}

	// free memory occupied by array
	free(vec -> array);

	// free memory occupied by vec
	free(vec);
}
