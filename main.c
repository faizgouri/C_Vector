#include "vector.h"
#include "data.h"
#include "stdio.h"

int main()
{

	struct vector *vec = createVector();

	/*struct data *dta = createData(f1, f2);
	struct data *dta1 = createData(33.3, 44.4);
	struct data *dta2 = createData(55.5, 66.6);
	struct data * dta3 = createData(77.7, 88.8);

	addFront(vec, dta2);
	addFront(vec, dta3);
	addFront(vec, dta);
	addBack(vec, dta1);
*/
	addFront(vec, createData(22,44));
	addFront(vec, createData(10,11));
	//removeFront(vec);

	//removeBack(vec);
	printVector(vec);

	// clone vector
	struct vector *clone = cloneVector(vec);
	printVector(clone);

	 //print result of vec and clone comparison
	printf("%d\n", compareVectors(vec, clone));

	// Reverse vec
	reverseVector(vec);

	// print sum of vec elements
	printf("%f\n", sumVector(vec));

	cleanVector(clone);
	cleanVector(vec);

	return 0;
}
