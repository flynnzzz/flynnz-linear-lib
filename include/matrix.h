#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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


// Matrices

Matrix emptyMatrix(int rows, int columns); // Allocates the necessary space for a matrix

Matrix nullMatrix(); // Returns a matrix with NULL value, 0 rows and 0 colums

void freeMatrix(Matrix m); // Deallocate matrix memory from heap

int printMatrix(Matrix m); // Prints matrix data on the console

Matrix defineMatrix(mel arr[], int rows, int columns); // Return a Matrix defined using an array

void matrixChangeRow(Matrix* empty, Row rowToInsert, int rowToChange); // Substitute a row with an array 

Matrix inputMatrix(); // Create matrix from stdin

Boolean sameMatrices(Matrix m1, Matrix m2);
										
Matrix copyMatrix(Matrix m); // Returns a copy of a matrix m

Matrix identityMatrix(int rows, int columns); // Returns an identity matrix of a chosen size

Matrix zeroMatrix(int rows, int columns); // Returns a matrix of a chosen size initialized to 0 in every cell 

Boolean isZeroMatrix(Matrix m);

Matrix matrixSum(Matrix m1, Matrix m2); // Returns the sum matrix of two matrices
										
Matrix matrixSub(Matrix m1, Matrix m2); // Returns the difference matrix of two matrices

Matrix matrixProd(Matrix m1, Matrix m2); // Returns the product matrix of two matrices

Matrix baseChange(Matrix A, Matrix C); // Returns a matrix corresponding to matrix A in a new base defined by the matrix C

int rankMatrix(Matrix m); // Returns the rank of a matrix

Boolean isSorted(Matrix m);

void printKerMatrix(Matrix m); // Prints the null-space of a matrix on the console

void fillMatrix(Matrix* m, mel n); // Fills an entire matrix with a chosen value
							
Matrix subMatrix(Matrix m, int rowToElim, int colToElim); // Returns a submatrix defined by matrix m and the rows/cols to eliminate

float detMatrix(Matrix m); // Returns the determinant of a matrix using REF

float laplaceDetMatrix(Matrix m); // Returns the Reterminant recursively using the laplace expansion formula

Matrix rowEchelon(Matrix m); // Returns a copy of m in REF

Matrix reducedRowEch(Matrix m); // Returns a copy of m in normalized REF

Matrix inverseMatrix(Matrix m); //Returns the inverse of a matrix using gauss-jordan elimination

int matrixSort(Matrix* a); // Sort matrix in decreasing order

Boolean fullRank(Matrix m); 

// Vectors

Vect emptyVect(int dim); // Allocates the necessary space for a vector

Vect nullVect(); // Returns a null vector with size 0 and NULL value

Vect zeroVect(int dim);

void freeVect(Vect v); // Deallocates vector memory from heap

int defineVect(Vect empty, float arr[], int dimArr); // Uses an array to define a vector

Vect copyVect(Vect v);

Vect vectSum(Vect v1, Vect v2);

Vect scaleVect(Vect vector, mel k); // Returns a scaled vector

int printVect(Vect v); // Prints a vector's contents on the console

Vect linearApp(Vect v, Matrix m); // Returns the vector obtained by matrix-vector multiplication

mel scalarProd(Vect v1, Vect v2); // Returns the dot product between two vectors

Vect rowToVect(Matrix m, int Row); // Returns the row of a matrix as a vector
										
Vect columnToVect(Matrix m, int column); // Returns the column of a matrix as a column


// Misc
Boolean isRowEchelon(Matrix m); 

void exchangeRows(Row* a, Row* b);

Boolean isTriangular(Matrix m); // Checks whether a matrix is triangular

Boolean isZeroRow(Row r, int dim); // Checks if a row is zeros-only

int nonZeroRows(Matrix m); // Returns the number of non-zero rows

#endif
