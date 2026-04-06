# [ S I M P L E | L I N E A R | L I B ]  

> Just a learning experience, not intended for use.

---

## Example of use 

```c

#include "matrix.h"

int main(void)
{
    // allocate heap memory
    Matrix m1 = emptyMatrix(1, 3);

    // use array of matrix elements `mel` to change a specified row
    mel arr1[] = {1, 0, -1};
    matrixChangeRow(&m1, arr1, 0);

    // or

    // Create a `Matrix` from a flat array defined on the stack.
    mel arr2[] = {2, 0, -3, 5, 6, 0, 1, 2, 0};
    Matrix m2 = defineMatrix(arr2, 3, 3);

    printMatrix(m1);
    printf("\n");
    printMatrix(m2);

    // deallocate
    freeMatrix(m1);
    freeMatrix(m2);

    return 0;
}

```

> Expected print output:

```c
  │  1.00   0.00  -1.00  │

  ┌  2.00   0.00  -3.00  ┐
  │  5.00   6.00   0.00  │
  └  1.00   2.00   0.00  ┘
```

---

## Documentation

### Memory allocation

| Function | Description |
|---|---|
| `Matrix emptyMatrix(int rows, int columns)` | Allocate the necessary space for a matrix. |
| `Matrix nullMatrix()` | Return a matrix with `NULL` data, `0` rows and `0` columns. |
| `void freeMatrix(Matrix m)` | Deallocate matrix memory from the heap. |
| `int printMatrix(Matrix m)` | Print the contents of a matrix. |
| `Matrix defineMatrix(mel arr[], int rows, int columns)` | Create a `Matrix` from a flat array defined on the stack. |
| `void matrixChangeRow(Matrix* m, Row rowToInsert, int rowToChange)` | Use arrays to add or modify rows of a matrix. |
| `Matrix inputMatrix()` | Interactively create a matrix from `stdin`. |

---

### Construction

| Function | Description |
|---|---|
| `Matrix identityMatrix(int rows, int columns)` | Return an identity matrix of chosen size. |
| `Matrix zeroMatrix(int rows, int columns)` | Return a zero matrix of chosen size. |
| `void fillMatrix(Matrix* m, mel n)` | Fill an entire matrix with a single chosen element. |
| `Matrix copyMatrix(Matrix m)` | Return a deep copy of matrix `m`. |

---

### Predicates

| Function | Description |
|---|---|
| `Boolean sameMatrices(Matrix m1, Matrix m2)` | Check whether two matrices are element-wise equal. |
| `Boolean isZeroMatrix(Matrix m)` | Check whether a matrix contains only zeros. |
| `Boolean fullRank(Matrix m)` | Check whether a matrix has full rank. |
| `Boolean isSorted(Matrix m)` | Check whether a matrix is sorted. |

---

### Arithmetic

| Function | Description |
|---|---|
| `Matrix matrixSum(Matrix m1, Matrix m2)` | Return `m1 + m2`. |
| `Matrix matrixSub(Matrix m1, Matrix m2)` | Return `m1 - m2`. |
| `Matrix matrixProd(Matrix m1, Matrix m2)` | Return the matrix product `m1 × m2`. |

---

### Advanced Operations

| Function | Description |
|---|---|
| `int rankMatrix(Matrix m)` | Determine the rank of a matrix. |
| `float detMatrix(Matrix m)` | Return the determinant using Row Echelon Form. |
| `float laplaceDetMatrix(Matrix m)` | Return the determinant via recursive Laplace expansion *(less efficient)*. |
| `Matrix rowEchelon(Matrix m)` | Return a copy of `m` in Row Echelon Form (REF). |
| `Matrix reducedRowEch(Matrix m)` | Return a copy of `m` in Reduced Row Echelon Form (RREF). |
| `Matrix inverseMatrix(Matrix m)` | Compute the inverse of `m` using Gauss–Jordan elimination. |
| `Matrix subMatrix(Matrix m, int rowToElim, int colToElim)` | Return the submatrix obtained by removing a given row and column. |
| `Matrix baseChange(Matrix A, Matrix C)` | Perform a change of basis from basis `A` to basis `C`. |
| `void printKerMatrix(Matrix m)` | Compute and print the equations defining the kernel of `m`. |
| `int matrixSort(Matrix a[])` | Sort a matrix's rows in decreasing order. |

---

## Vectors

### Memory allocation

| Function | Description |
|---|---|
| `Vect emptyVect(int dim)` | Allocate the necessary space for a vector. |
| `Vect nullVect()` | Return a null vector with `dim = 0` and `data = NULL`. |
| `Vect zeroVect(int dim)` | Return a zero vector of given dimension. |
| `void freeVect(Vect v)` | Deallocate vector memory from the heap. |
| `int defineVect(Vect empty, float arr[], int dimArr)` | Populate a vector using a float array. |
| `Vect copyVect(Vect v)` | Return a deep copy of vector `v`. |
| `int printVect(Vect v)` | Print the contents of a vector. |

---

### Arithmetic

| Function | Description |
|---|---|
| `Vect vectSum(Vect v1, Vect v2)` | Return `v1 + v2`. |
| `Vect scaleVect(Vect vector, mel k)` | Return `v` multiplied by scalar `k`. |
| `mel scalarProd(Vect v1, Vect v2)` | Return the dot product `v1 · v2`. |
| `Vect linearApp(Vect v, Matrix m)` | Return the matrix–vector product `m × v`. |

---

## Misc / Utilities

| Function | Description |
|---|---|
| `Boolean isRowEchelon(Matrix m)` | Check whether `m` is in Row Echelon Form. |
| `Boolean isTriangular(Matrix m)` | Check whether `m` is triangular (upper or lower). |
| `Boolean isZeroRow(Row r, int dim)` | Check whether a row contains only zeros. |
| `int nonZeroRows(Matrix m)` | Return the number of non-zero rows in `m`. |
| `void exchangeRows(Row* a, Row* b)` | Swap two rows in-place. |
