#ifndef MATRIX_H
#define MATRIX_H
#define EPSILON 1e-4f

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef enum {
	false, true
}Boolean;

typedef float mel; //matrix element

typedef mel* Row;

typedef mel* Column;

typedef struct vector
{
	int dim;
	mel* data;
}Vect;

typedef Row* rowArr;

typedef struct matrix
{
	int rows, cols;
	rowArr data;
}Matrix;

typedef struct linear_equation
{
	int id;
	Vect value;
	Boolean varIsolated;
}L_EQ;

/* Float equality with tolerance */
static int feq(float a, float b) { return fabsf(a - b) < EPSILON; }

//--------------------------------------------------------------------------------------------------------------------------------
//														 FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------MATRICES-----------------------------------------------------------------

Matrix emptyMatrix(int rows, int columns); //allocate the necessary space for a matrix

Matrix nullMatrix(); //matrix with NULL value, 0 rows and 0 colums

void freeMatrix(Matrix m); //deallocate matrix memory from heap

int printMatrix(Matrix m); //yeah

Matrix defineMatrix(mel arr[], int rows, int columns); //create a Matrix using an array defined on the stack

void matrixChangeRow(Matrix* empty, Row rowToInsert, int rowToChange); //use arrays to add/modify rows of a matrix

Matrix inputMatrix(); //allows user to create matrix from stdin

Boolean sameMatrices(Matrix m1, Matrix m2);
										
Matrix copyMatrix(Matrix m); //returns a copy of a matrix m

Matrix identityMatrix(int rows, int columns); //returns an identity matrix of a chosen size

Matrix zeroMatrix(int rows, int columns); //0 matrix of chosen size

Boolean isZeroMatrix(Matrix m); //is it a zero matrix?

Matrix matrixSum(Matrix m1, Matrix m2); 
										//matrix sum
Matrix matrixSub(Matrix m1, Matrix m2);

Matrix matrixProd(Matrix m1, Matrix m2); //matrix-matrix multiplication

Matrix baseChange(Matrix A, Matrix C); //change base

int rankMatrix(Matrix m); //determines the rank of a matrix

Boolean isSorted(Matrix m);

void printKerMatrix(Matrix m); //raw doggin' it, im too lazy to search up the fastest algorithm, this should find all the equations that
							   //define the kernel and print them

void fillMatrix(Matrix* m, mel n); //fill an entire matrix with a chosen element
							
Matrix subMatrix(Matrix m, int rowToElim, int colToElim); //create a submatrix

float detMatrix(Matrix m); //returns the determinant of a matrix using REF

float laplaceDetMatrix(Matrix m); //determinant using recursion (less efficient)

Matrix rowEchelon(Matrix m); //returns a copy of m in REF

Matrix reducedRowEch(Matrix m); //fives a copy of m in normalized REF

Matrix inverseMatrix(Matrix m); //uses gauss-jordan elimination to find the inverse of a matrix

int matrixSort(Matrix a[]); //sort in decreasing order

Boolean fullRank(Matrix m); 

//---------------------------------------------------------VECTORS----------------------------------------------------------------

Vect emptyVect(int dim); //allocate the necessary space for a vector

Vect nullVect(); //null vector with size 0 and NULL value

Vect zeroVect(int dim);

void freeVect(Vect v); //deallocate vector memory from heap

int defineVect(Vect empty, float arr[], int dimArr); //use an array to define a vector

Vect copyVect(Vect v);

Vect vectSum(Vect v1, Vect v2);

Vect scaleVect(Vect vector, mel k); //multply a vector by a scalar value

int printVect(Vect v); //yup

Vect linearApp(Vect v, Matrix m); //matrix-vector multiplication

mel scalarProd(Vect v1, Vect v2); //scalar product between two vectors

Vect rowToVect(Matrix m, int Row);
										//converts a row/column of a matrix into a vector
Vect columnToVect(Matrix m, int column);

//-----------------------------------------------------------MISC-----------------------------------------------------------------
Boolean isRowEchelon(Matrix m); //yup

void exchangeRows(Row* a, Row* b); //exchange two rows

Boolean isTriangular(Matrix m); //check if m is triangular

Boolean isZeroRow(Row r, int dim); //check if a row is zeros-only

int nonZeroRows(Matrix m); //finds the number of non-zero rows

//--------------------------------------------------------------------------------------------------------------------------------
//													Not intended for use
//--------------------------------------------------------------------------------------------------------------------------------

Matrix rowEchDet(Matrix m, int* exchanges); //the same as rowEchelon() but it counts how many exchanges were made (for detMatrix())
											
Boolean GJfindPivot(int start, Matrix c, int* pivot, int* pivotR); //used in REF functions to find pivot 
																 
void sub_matrixAdd(Matrix* m, mel el, int* row, int* column); //adds into a matrix an element and moves forward into the matrix

int MbubbleSort(Matrix v[]); 

int compareRow(Row e1, Row e2, int dim); //for sorting, rows with smaller pivot indexes are "bigger"

void normalizeEl(Matrix* m, int pivotR, int j, float norma); //normalize a sigle element

void op_gaussJordan(Matrix* c, Matrix* inverse); //performs reducedRowEch() the first, performs the same operations on the second
												 //used for inverseMatrix()
void clear_input(void); //clear the buffer

void delZeroRowsSorted(Matrix* sorted); //deletes zero rows (sorted matrices)

int explicitVariable(L_EQ* eq); //for linear equations, makes the chosen variable (inside *eq) explicit 
							 //e.g. id = 'a' , value =  a + 2b+ 3c , varIsolated = false -> returns id = 'a', value = -2b - 3c, varIsolated = true

int rowsToEquations(Matrix m, L_EQ* equations); //converts a matrix's rows into "unexplicited" equations

void rowsToEquationsEX(Matrix m, L_EQ* equations); //converts a matrix's rows into "explicited" equations

Boolean isInEquations_byID(int id, L_EQ* eqs, int dim); //checks if an equation of id "j" is present in the arrary "eqs"

Vect vectValue_byID(int id, L_EQ* eqs, int dim); //finds the corresponding equation by id

void delRedundancyEq(L_EQ* equation, L_EQ* equations, int i, int dim); //support function to make code look prettier, not intended for user

void printL_EqEX(L_EQ eq); //print a linear equation (explicited)

void printL_EqsEX(L_EQ* eqs, int rows); //same as above but an array of equations

Matrix extra_identityMatrix(int rows, int columns); //identityMatrix algorythm but allows any number of rows and columns

#endif
