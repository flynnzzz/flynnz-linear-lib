#include "matrix.h"

Boolean sameMatrices(Matrix m1, Matrix m2)
{
	if (m1.rows != m2.rows || m1.cols != m2.cols)
		return false;
	else
	{
		int i, j;
		for (i = 0; i < m1.rows; i++)
		{
			for (j = 0; j < m1.cols; j++)
			{
				if (!feq(m1.data[j][i], m2.data[j][i]))
					return false;
			}
		}
		return true;
	}
}

Matrix emptyMatrix(int rows, int columns)
{
	int i;
	Matrix final;
	final.data = (rowArr)malloc(sizeof(Row) * rows);
	if (final.data == NULL || rows <= 0 || columns <= 0) { final = nullMatrix(); }
	else
	{
		final.rows = rows;
		final.cols = columns;
		for (i = 0; final.data != NULL && i < rows; i++)
		{
			final.data[i] = (Row)malloc(sizeof(mel) * columns);
			if (final.data[i] == NULL) { printf("\nRow n.%d creation error\n", i); }
		}
	}
	return final;
}

Matrix defineMatrix(mel arr[], int rows, int columns)
{
	Matrix result = emptyMatrix(rows, columns);

	int i, j, k = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			result.data[i][j] = arr[k];
			k++;
		}
	}
	return result;
}

void matrixChangeRow(Matrix* empty, Row rowToInsert, int rowToChange)
{
	int i;
	for (i = 0; i < empty->cols; i++)
		empty->data[rowToChange][i] = rowToInsert[i];
}

void clear_input(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

Matrix inputMatrix()
{
	int i = 0, j, rows = 0, cols = 0, scanned = 0;;
	printf("Creating matrix...");
	printf("\nHow many rows? ");
	while (rows <= 0 || scanned < 1)
	{
		scanned = scanf_s("%d", &rows);
		if (scanned < 1)
		{
			clear_input();
			printf("Please input an integer (> 0): ");
		}
		else
		{
			if (rows <= 0)
				printf("Please input valid number of rows (> 0): ");
		}
	}
	scanned = 0;
	printf("\nHow many columns? ");
	while (cols <= 0 || scanned < 1)
	{
		scanned = scanf_s("%d", &cols);
		if (scanned < 1)
		{
			clear_input();
			printf("Please input an integer (> 0): ");
		}
		else
		{
			if (cols <= 0)
				printf("Please input valid number of columns (> 0): ");
		}
	}

	Matrix empty = emptyMatrix(rows, cols);
	while (i < empty.rows)
	{
		printf("\nInsert row n.%d\n", i + 1);
		for (j = 0; j < empty.cols; j++)
		{
			scanned = 0;
			while (scanned < 1)
			{
				scanned = scanf_s("%f", &(empty.data[i][j]));
				if (scanned < 1)
				{
					clear_input();
					printf("Error reading values, please input float values:\n");
				}
			}
		}
		i++;
	}
	return empty;
}

int printMatrix(Matrix m)
{
	int i, j, k = 0;
	if (m.data == NULL || m.rows == 0 || m.cols == 0)
		printf("\nNULL\n");
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			printf("{");
			for (j = 0; j < m.cols; j++)
			{
				if (m.data[i][j] >= 10.0 || (m.data[i][j] < 0.0 && m.data[i][j] > -10.0))
					printf("  %.2f", m.data[i][j]);
				else
				{
					if (m.data[i][j] >= 100.0 || m.data[i][j] <= -10.0)
						printf(" %.2f", m.data[i][j]);
					else
						printf("   %.2f", m.data[i][j]);
				}
				k++;
			}
			printf("   }\n");
		}
	}
	return k;
}

void freeMatrix(Matrix m)
{
	int i;
	for (i = 0; i < m.rows; i++)
		free(m.data[i]);
	free(m.data);
}

Matrix matrixSum(Matrix m1, Matrix m2)
{
	Matrix result = nullMatrix();
	int i, j;
	if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
		printf("\n!Incompatible matrices!\n");
	else
	{
		result = emptyMatrix(m1.rows, m1.cols);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
			for (i = 0; i < m1.rows; i++)
				for (j = 0; j < m1.cols; j++)
					result.data[i][j] = m1.data[i][j] + m2.data[i][j];
	}
	return result;
}

Matrix matrixSub(Matrix m1, Matrix m2)
{
	Matrix result = nullMatrix();
	int i, j;
	if ((m1.rows != m2.rows) || (m1.cols != m2.cols))
		printf("\n!Incompatible matrices!\n");
	else
	{
		result = emptyMatrix(m1.rows, m1.cols);
		if (result.data == NULL) { printf("\nMatrix creation error\n"); }
		else
			for (i = 0; i < m1.rows; i++)
				for (j = 0; j < m1.cols; j++)
					result.data[i][j] = m1.data[i][j] - m2.data[i][j];
	}
	return result;
}

Vect emptyVect(int dim)
{
	Vect result;
	result.data = (mel*)malloc(sizeof(mel) * dim);
	if (result.data == NULL || dim <= 0) { printf("\nVector creation error\n"); result = nullVect(); }
	else
		result.dim = dim;
	return result;
}

int defineVect(Vect empty, float arr[], int dimArr)
{
	int i = 0;
	if (dimArr != empty.dim) { printf("\nArray size doesn't match vector size\n"); }
	else
		for (i; i < empty.dim; i++)
			empty.data[i] = arr[i];
	return i;
}

void freeVect(Vect v)
{
	free(v.data);
}

int printVect(Vect v)
{
	int i;
	printf("| ");
	for (i = 0; i < v.dim; i++)
	{
		printf("%.2f ", v.data[i]);
		if (i < v.dim - 1)
			printf(", ");
	}
	printf("|");
	return i;
}

Vect linearApp(Vect v, Matrix m)
{
	Vect result;
	int i, j;
	result.data = NULL;
	result.dim = 0;

	if (v.dim != m.cols) { printf("\nIncompatible application\n"); }
	else
	{
		result = emptyVect(m.rows);
		for (i = 0; i < m.rows; i++)
		{
			result.data[i] = 0;
			for (j = 0; j < m.cols; j++)
				result.data[i] += (v.data[j] * m.data[i][j]);
		}
	}
	return result;
}

Matrix matrixProd(Matrix m1, Matrix m2)
{
	Matrix product;
	int i, j, k;
	if (m1.cols != m2.rows) { printf("\n!Incompatible matrices!\n"); product = nullMatrix(); }
	else
	{
		product = emptyMatrix(m1.rows, m2.cols);
		for (i = 0; i < m1.rows; i++)
		{
			for (j = 0; j < m2.cols; j++)
			{
				product.data[i][j] = 0;
				for (k = 0; k < m1.cols; k++)
					product.data[i][j] += m1.data[i][k] * m2.data[k][j];
			}
		}
	}
	return product;
}

Vect columnToVect(Matrix m, int columnNumber)
{
	Vect result;
	result = emptyVect(m.rows);
	int i;
	for (i = 0; i < m.rows; i++)
		result.data[i] = m.data[i][columnNumber];
	return result;
}

Vect rowToVect(Matrix m, int rowNumber)
{
	Vect result;
	result = emptyVect(m.cols);
	int i;
	for (i = 0; i < m.cols; i++)
		result.data[i] = m.data[rowNumber][i];
	return result;
}

mel scalarProd(Vect v1, Vect v2)
{
	int i;
	mel result = 0;

	if (v1.dim != v2.dim) { printf("\nIncompatible vectors\n"); return -1000; }
	else
	{
		for (i = 0; i < v1.dim; i++)
			result += v1.data[i] * v2.data[i];
		return result;
	}
}

Matrix subMatrix(Matrix m, int rowToElim, int colToElim)
{
	int i, j, k = 0, t = 0;
	mel elem;
	Matrix result;
	if (m.rows != m.cols) { printf("\nSubmatrix not allowed\n"); result = nullMatrix(); }
	else
	{
		result = emptyMatrix(m.rows - 1, m.cols - 1);
		for (i = 0; i < m.rows; i++)
		{
			for (j = 0; j < m.rows; j++)
			{
				if (i != rowToElim && j != colToElim)
				{
					elem = m.data[i][j];
					sub_matrixAdd(&result, elem, &k, &t);
				}
			}
		}
	}
	return result;
}

void sub_matrixAdd(Matrix* m, mel el, int* row, int* column)
{
	m->data[*row][*column] = el;
	if (*column < m->cols - 1)
		(*column)++;
	else
	{
		if (*column == m->cols - 1 && *row < m->rows - 1)
		{
			(*row)++;
			*column = 0;
		}
	}
}

float laplaceDetMatrix(Matrix m)
{
	int i = m.cols - 1;
	float determinant = 0;
	if (!fullRank(m)) { determinant = 0; }
	else
	{
		if (m.rows == 1)
			return m.data[0][0];
		else
		{
			while (i >= 0)
			{
				determinant += m.data[m.rows - 1][i] * (float)pow(-1, m.rows - 1 + i) * laplaceDetMatrix(subMatrix(m, m.rows - 1, i));
				i--;
			}
		}
	}
	return determinant;
}

float detMatrix(Matrix m)
{
	int i, mult = 1;
	float det = 1;
	if (!fullRank(m)) { det = 0; }
	else
	{
		Matrix reduced = rowEchDet(m, &mult);
		for (i = 0; i < m.cols; i++)
			det *= reduced.data[i][i];
		freeMatrix(reduced);
		if (det != 0)
			det = mult * det;
	}
	return det;
}

int rankMatrix(Matrix m)
{
	int rank;
	if (m.data == NULL || m.data == 0 || m.rows == 0 || m.cols == 0) { rank = 0; }
	else
	{
		Matrix c = emptyMatrix(m.rows, m.cols);
		c = rowEchelon(m);
		rank = nonZeroRows(c);
		freeMatrix(c);
	}
	return rank;
}

int nonZeroRows(Matrix m)
{
	int i, j = 0;
	for (i = 0; i < m.rows; i++)
		if (!isZeroRow(m.data[i], m.cols))
			j++;
	return j;
}

Boolean isRowEchelon(Matrix m)
{
	//assuming that REF also means it is sorted correctly
	Boolean itIs = true;
	int i, j, max = -1;
	if (nonZeroRows(m) == 0) { itIs = true; }
	else
	{
		for (i = 0; i < m.rows && itIs; i++)
		{
			for (j = 0; j < m.cols && m.data[i][j] == 0; j++);
			if (j > max)
				max = j;
			else if (!isZeroRow(m.data[i], m.cols))
				itIs = false;
		}
	}
	return itIs;
}

void normalizeEl(Matrix* m, int pivotR, int j, float norma)
{
	if (m->data[pivotR][j] != 0)
		m->data[pivotR][j] = m->data[pivotR][j] / norma;
}

void delZeroRowsSorted(Matrix* sorted)
{
	int i, dim;
	dim = sorted->rows;
	if (!isSorted(*sorted)) { printf("\nInput error, delZeroRowsSorted() only takes in sorted matrices\n"); }
	else
	{
		for (i = 0; i < dim; i++)
		{
			if (isZeroRow(sorted->data[i], sorted->cols))
			{
				free(sorted->data[i]);
				sorted->rows--;
			}
		}
	}
}

Boolean isSorted(Matrix m)
{
	int i, rank = rankMatrix(m);
	Boolean sorted = true;
	for (i = 0; i < m.rows && sorted; i++)
	{
		if (isZeroRow(m.data[i], m.cols) && i < rank)
			sorted = false;
	}
	return sorted;
}

Matrix rowEchelon(Matrix m)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	if (isRowEchelon(c)) { return c; }
	else
	{
		for (k = 0; k < c.rows && GJfindPivot(k, c, &pivot, &pivotR); k++)
		{
			if (pivotR != k) //if not in "top" row, exchange
				exchangeRows(&c.data[pivotR], &c.data[k]);
			pivotR = k; //now it is in "top" row
			for (i = k + 1; i < c.rows; i++)
			{
				if (c.data[i][pivot] != 0)
				{
					factor = c.data[i][pivot] / c.data[pivotR][pivot];
					for (j = pivot; j < c.cols; j++)
						c.data[i][j] -= factor * c.data[k][j];
				}
			}
		}
	}
	return c;
}

Matrix reducedRowEch(Matrix m)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0, norma = 1;
	for (k = 0; k < c.rows && GJfindPivot(k, c, &pivot, &pivotR); k++)
	{
		if (pivotR != k) //if not in "top" row, exchange
			exchangeRows(&c.data[pivotR], &c.data[k]);
		pivotR = k; //now it is in "top" row

		//normalize pivotR after exchanging
		norma = c.data[pivotR][pivot];
		if (norma != 0 && norma != 1)
			for (j = 0; j < c.cols; j++)
				normalizeEl(&c, pivotR, j, norma);
		for (i = k + 1; i < c.rows; i++)
		{
			factor = c.data[i][pivot];
			if (factor != 0)
			{
				for (j = 0; j < c.cols; j++)
					c.data[i][j] -= factor * c.data[k][j];
			}

		}
	}
	return c;
}

Matrix rowEchDet(Matrix m, int* exchanges)
{
	Matrix c = copyMatrix(m);
	int pivot, pivotR;
	int i, j, k;
	float factor = 0;
	*exchanges = 1;
	for (k = 0; k < c.rows - 1 && GJfindPivot(k, c, &pivot, &pivotR); k++)
	{
		if (pivotR != k)
		{
			exchangeRows(&c.data[pivotR], &c.data[k]);
			*exchanges *= -1;
		}
		pivotR = k;
		for (i = k + 1; i < c.rows; i++)
		{
			factor = (c.data[i][pivot] / c.data[pivotR][pivot]);
			if (factor != 0)
			{
				for (j = 0; j < c.cols; j++)
					c.data[i][j] -= factor * c.data[k][j];
			}
		}
	}
	return c;
}

void op_gaussJordan(Matrix* c, Matrix* inverse)
{
	int k, i, j, pivot = 0, pivotR = 0;
	float factor = 0, norma = 1;
	for (k = 0; k < c->rows && GJfindPivot(k, *c, &pivot, &pivotR); k++)
	{
		if (pivotR != k) //if not in "top" row, exchange
		{
			exchangeRows(&(c->data[pivotR]), &(c->data[k]));
			exchangeRows(&(inverse->data[pivotR]), &(inverse->data[k]));
		}
		pivotR = k; //now it is in "top" row

		norma = c->data[pivotR][pivot];
		if (norma != 0 && norma != 1)
		{
			for (j = 0; j < c->cols; j++)
			{
				normalizeEl(c, pivotR, j, norma);
				normalizeEl(inverse, pivotR, j, norma);
			}
		}

		for (i = k + 1; i < c->rows; i++)
		{
			factor = c->data[i][pivot];
			if (factor != 0)
			{
				for (j = 0; j < c->cols; j++)
				{
					c->data[i][j] -= factor * c->data[k][j];
					inverse->data[i][j] -= factor * inverse->data[k][j];
				}
			}
		}
	}
}

Matrix identityMatrix(int rows, int columns)
{
	Matrix identity = emptyMatrix(rows, columns);
	int i, j;
	if (identity.rows != identity.cols) { printf("\nInexistent identity matrix for non-square matrices\n"); identity = nullMatrix(); }
	else
	{
		for (i = 0; i < identity.rows; i++)
		{
			for (j = 0; j < identity.cols; j++)
			{
				if (i != j)
					identity.data[i][j] = 0;
				else
					identity.data[i][j] = 1;
			}
		}
	}
	return identity;
}

Matrix extra_identityMatrix(int rows, int columns)
{
	Matrix identity = emptyMatrix(rows, columns);
	int i, j;

	for (i = 0; i < identity.rows; i++)
	{
		for (j = 0; j < identity.cols; j++)
		{
			if (i != j)
				identity.data[i][j] = 0;
			else
				identity.data[i][j] = 1;
		}
	}
	return identity;
}

Matrix inverseMatrix(Matrix m)
{
	Matrix c, inverse;
	if (m.cols != m.rows || !fullRank(m)) { printf("\nInverse not allowed (this function only takes in full rank square matrices)\n"); inverse = nullMatrix(); }
	else
	{
		c = copyMatrix(m);
		inverse = identityMatrix(m.rows, m.cols);
		int k, i, j;
		float multi;

		//Reduces "c" to RREF while repeating the operations on "inverse" (identity matrix)
		op_gaussJordan(&c, &inverse);

		//reduce c to Identity matrix to obtain inverse 
		for (k = c.cols - 1; k > 0; k--)
		{
			for (i = k; i > 0; i--)
			{
				multi = c.data[i - 1][k];
				if (multi != 0)
				{
					c.data[i - 1][k] -= c.data[k][k] * multi;
					for (j = 0; j < inverse.cols; j++)
						inverse.data[i - 1][j] -= inverse.data[k][j] * multi;
				}
			}
		}
		freeMatrix(c);
	}
	return inverse;
}

Boolean GJfindPivot(int start, Matrix c, int* pivot, int* pivotR)
{
	int i, j;
	Boolean found = 0;
	for (j = start; j < c.cols; j++)
	{
		for (i = start; i < c.rows && !found; i++)
		{
			if (c.data[i][j] != 0) //pivot found
			{
				*pivot = j;
				*pivotR = i;
				found = 1;
			}
		}
	}
	return found;
}

Boolean isZeroRow(Row r, int dim)
{
	int j;
	Boolean zero = true;
	for (j = 0; j < dim && zero; j++)
		if (r[j] != 0)
			zero = false;
	return zero;
}

void fillMatrix(Matrix* m, mel n)
{
	int i, j;
	for (i = 0; i < m->rows; i++)
	{
		for (j = 0; j < m->cols; j++)
			m->data[i][j] = n;
	}
}

Matrix copyMatrix(Matrix m)
{
	Matrix r = emptyMatrix(m.rows, m.cols);
	int i, j;
	if (m.rows == 0 || m.cols == 0) { r = nullMatrix(); }
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			for (j = 0; j < m.cols; j++)
				r.data[i][j] = m.data[i][j];
		}
	}
	return r;
}

int MbubbleSort(Matrix v[])
{
	int i, sorted = 0, n, exchanged = 1;;
	n = v->rows;
	while (n > 1 && !sorted) {
		sorted = 1;
		for (i = 0; i < n - 1; i++)
			if (compareRow(v->data[i], v->data[i + 1], v->cols) > 0)
			{
				exchangeRows(&v->data[i], &v->data[i + 1]);
				sorted = 0;
				exchanged *= -1;
			}
		n--;
	}
	return exchanged;
}

int matrixSort(Matrix a[])
{
	int exchanged = MbubbleSort(a);
	return exchanged;
}

void exchangeRows(Row* a, Row* b)
{
	Row tmp = *a;
	*a = *b;
	*b = tmp;
}

int compareRow(Row e1, Row e2, int dim)
{
	int result = 0, i, j;

	for (i = 0; i < dim && e1[i] == 0; i++);
	for (j = 0; j < dim && e2[j] == 0; j++);

	result = i - j;
	return result;
}

Boolean isTriangular(Matrix m)
{
	Boolean notUpper = false;
	Boolean notLower = false;

	if (m.rows != m.cols)
		return false;
	else
	{
		// Check upper triangular
		for (int i = 1; i < m.rows && !notUpper; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (m.data[i][j] != 0)
					notUpper = true;
			}
		}

		if (!notUpper)
			return true;

		// Check lower triangular
		for (int i = 0; i < m.rows - 1 && !notLower; i++)
		{
			for (int j = i + 1; j < m.cols; j++)
			{
				if (m.data[i][j] != 0)
					notLower = true;
			}
		}
	}
	return !notLower;
}

Matrix baseChange(Matrix A, Matrix C)
{
	//C: baseC -> baseA
	//C^-1: baseA -> baseC
	Matrix B;
	if (!fullRank(A) || !fullRank(C))
	{
		printf("\nBase change not allowed\n");
		B = nullMatrix();
	}
	else
	{
		Matrix C_inv = inverseMatrix(C);
		B = matrixProd(A, C);
		B = matrixProd(C_inv, B);
		freeMatrix(C_inv);
	}
	return B;
}

Matrix nullMatrix()
{
	Matrix null;
	null.data = NULL;
	null.rows = 0;
	null.cols = 0;
	return null;
}

Matrix zeroMatrix(int rows, int columns)
{
	Matrix zero = emptyMatrix(rows, columns);
	if (rows == 0 && rows == columns) { zero = nullMatrix(); }
	else
		fillMatrix(&zero, 0);
	return zero;
}

Vect nullVect()
{
	Vect null;
	null.dim = 0;
	null.data = NULL;
	return null;
}

Vect copyVect(Vect v)
{
	Vect copy;
	int i;
	if (v.dim == 0 || v.data == NULL) { printf("\nCopy failed\n"); copy = nullVect(); }
	else
	{
		copy = emptyVect(v.dim);
		for (i = 0; i < v.dim; i++)
			copy.data[i] = v.data[i];
	}
	return copy;
}

Vect scaleVect(Vect vector, mel k)
{
	int i;
	Vect scaled = copyVect(vector);
	if (scaled.data == NULL) { printf("\nImpossible to scale null vector\n"); }
	else
	{
		for (i = 0; i < vector.dim; i++)
			if (scaled.data[i] != 0)
				scaled.data[i] *= k;
	}
	return scaled;
}

Vect vectSum(Vect v1, Vect v2)
{
	Vect sum;
	int i;
	if (v1.dim != v2.dim) { printf("\nIncompatible vectors\n"); sum = nullVect(); }
	else
	{
		sum = emptyVect(v1.dim);
		for (i = 0; i < v1.dim; i++)
			sum.data[i] = v1.data[i] + v2.data[i];
	}
	return sum;
}

Boolean isZeroMatrix(Matrix m)
{
	int i;
	Boolean ex = false;
	for (i = 0; i < m.rows && !ex; i++)
		ex = !isZeroRow(m.data[i], m.rows);
	return !ex;
}

void printKerMatrix(Matrix m)
{
	int i;
	if (fullRank(m) || isZeroMatrix(m)) { printf("\nTrivial kernel\n"); }
	else
	{
		Matrix RREF = reducedRowEch(m);
		delZeroRowsSorted(&RREF);
		if (fullRank(RREF) && RREF.rows == RREF.cols) { printf("\nTrivial kernel\n"); }
		else
		{
			L_EQ* equations = NULL;
			equations = (L_EQ*)malloc(sizeof(L_EQ) * RREF.rows);
			if (equations == NULL) { printf("\nmalloc error\n"); }
			else
			{
				rowsToEquationsEX(RREF, equations);
				for (i = RREF.rows - 1; i >= 0; i--) //for every saved equation
					delRedundancyEq(&equations[i], equations, i, RREF.rows);

				printL_EqsEX(equations, RREF.rows);

				for (i = 0; i < RREF.rows; i++) //DOUBLE check and free every vector correctly
					freeVect(equations[i].value);
				free(equations);
			}
			freeMatrix(RREF);
			//doesn't find free and null variables, i'll leave them to the user to find as an exercise
		}
	}
}

void printL_EqsEX(L_EQ* eqs, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		printf("%d: [ ", i + 1);
		printL_EqEX(eqs[i]);
		printf(" ]\n");
	}
}

void printL_EqEX(L_EQ eq)
{
	int j;
	if (isZeroRow(eq.value.data, eq.value.dim))
	{
		printf("%c = 0", (char)(eq.id + 97));
	}
	else
	{
		for (j = eq.id; j < eq.value.dim; j++)
		{
			if (j == eq.id)
				printf("%c = ", (char)(eq.id + 97));
			if (eq.value.data[j] < 0)
			{
				if (j < eq.value.dim)
					printf(" - ");
				printf("%.3f%c", -eq.value.data[j], (char)(j + 97));
			}
			if (eq.value.data[j] > 0)
			{
				if (j < eq.value.dim)
					printf(" + ");
				printf("%.3f%c", eq.value.data[j], (char)(j + 97));
			}

		}
	}
}

void delRedundancyEq(L_EQ* equation, L_EQ* equations, int i, int dim)
{
	float scale;
	int j;
	Vect to_sum, scaled, modified;
	for (j = equation->value.dim - 1; j > equation->id; j--) //for every entry of the equation
	{
		if (equation->value.data[j] != 0 && isInEquations_byID(j, equations, dim))
		{
			scale = equation->value.data[j];
			to_sum = vectValue_byID(j, equations, dim);
			if (scale != 0 && scale != 1)
			{
				scaled = scaleVect(to_sum, scale);
				modified = vectSum(scaled, equation->value);
				freeVect(scaled);
			}
			else
				modified = vectSum(to_sum, equation->value);
			equation->value = modified;
			equation->value.data[j] = 0;
			freeVect(to_sum);
		}
	}
}

Vect vectValue_byID(int id, L_EQ* eqs, int dim)
{
	int i;
	Boolean found = false;
	Vect result;
	result = emptyVect(eqs->value.dim);
	for (i = 0; i < dim && !found; i++)
		if (id == eqs[i].id)
		{
			found = true;
			result = copyVect(eqs[i].value);
		}
	return result;
}

Boolean isInEquations_byID(int id, L_EQ* eqs, int dim)
{
	int i;
	Boolean need = false;
	for (i = 0; i < dim && !need; i++)
		if (id == eqs[i].id)
			need = true;
	return need;
}

int explicitVariable(L_EQ* eq)
{
	int code;
	if (eq->id < 0 || isZeroRow(eq->value.data, eq->value.dim)) { code = 0; }
	else
	{
		Vect value = copyVect(eq->value), trueValue;
		float factor = -1;
		value.data[eq->id] = 0;
		if (eq->value.data[eq->id] != 0 && eq->value.data[eq->id] != 1)
			factor *= (1 / eq->value.data[eq->id]);
		trueValue = scaleVect(value, factor);
		freeVect(value);
		freeVect(eq->value);
		eq->value = trueValue;
		eq->varIsolated = true;
		code = 1;
	}
	return code;
}

Vect zeroVect(int dim)
{
	Vect zero = emptyVect(dim);
	int i;
	if (dim < 0) { zero = nullVect(); }
	else
	{
		for (i = 0; i < dim; i++)
			zero.data[i] = 0;
	}
	return zero;
}

int rowsToEquations(Matrix m, L_EQ* equations)
{
	int i = 0, j;
	if (m.data == NULL || m.rows == 0 || m.cols == 0
		|| equations->value.dim == 0)
		printf("\nInvalid inputs\n");
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			Vect eqValue = rowToVect(m, i);
			L_EQ equation;
			//find pivot == L_EQ -> int id;
			for (j = 0; j < eqValue.dim && eqValue.data[j] == 0; j++);
			equation.id = j;
			equation.value = eqValue;
			equation.varIsolated = false;
			equations[i] = equation;
		}
	}
	return i;
}

void rowsToEquationsEX(Matrix m, L_EQ* equations)
{
	int i, j;
	if (m.data == NULL || m.rows == 0 || m.cols == 0
		|| equations->value.dim == 0)
		printf("\nInvalid inputs\n");
	else
	{
		for (i = 0; i < m.rows; i++)
		{
			Vect eqValue = rowToVect(m, i);
			L_EQ equation;
			//find pivot == L_EQ -> int id;
			for (j = 0; j < eqValue.dim && eqValue.data[j] == 0; j++);
			equation.id = j;
			equation.value = eqValue;
			equation.varIsolated = false;
			explicitVariable(&equation);
			equations[i] = equation;
		}
	}
}

Boolean fullRank(Matrix m)
{
	Boolean fullR = false;
	if (m.data == NULL || m.rows == 0 || m.cols == 0) { printf("\nNull matrix has no rank\n"); }
	else
	{
		Matrix reduced = rowEchelon(m);
		delZeroRowsSorted(&reduced);
		if ((rankMatrix(reduced) == reduced.rows) && reduced.rows == reduced.cols)
			fullR = true;
		freeMatrix(reduced);
	}
	return fullR;
}