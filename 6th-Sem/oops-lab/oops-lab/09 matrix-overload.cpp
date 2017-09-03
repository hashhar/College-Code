#include <iostream>
#include <cstdlib>

class Matrix
{
public:
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	Matrix operator=(const Matrix&);
	Matrix operator+(const Matrix&);

	void print();
	void getMatrix();

private:
	int row;
	int col;
	int **array;

	void allocate();
	void release();
};

Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;
	allocate();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			array[i][j] = rand() % 10;
}

Matrix::Matrix(const Matrix& m)
{
	row = m.row;
	col = m.col;
	allocate();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			array[i][j] = m.array[i][j];
}

Matrix::~Matrix()
{ release(); }

void Matrix::allocate()
{
	array = new int*[static_cast<unsigned long>(row)];
	for (int i = 0; i < row; i++)
		array[i] = new int[static_cast<unsigned long>(col)];
}

void Matrix::release()
{
	for (int i = 0; i < row; i++)
		delete [] array[i];
	delete [] array;
}

void Matrix::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << array[i][j] << "\t";
		std::cout << std::endl;
	}
}

void Matrix::getMatrix()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << "array[" << i << "][" << j << "]: ";
			std::cin >> array[i][j];
		}
	}
}

Matrix Matrix::operator+(const Matrix &m)
{
	if (row != m.row || col != m.col)
	{
		std::cerr << "Invalid Matrix addition!";
		return *this;
	}
	Matrix temp(row,col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.array[i][j] = array[i][j] + m.array[i][j];

	return temp;
}

Matrix Matrix::operator=(const Matrix &m)
{
	for (int i = 0; i < m.row; i++)
		for (int j = 0; j < m.col; j++)
			array[i][j] = m.array[i][j];

	return *this;
}

int main()
{
	int row, col;
	std::cout << "Enter the number of rows and columns in the matrices: ";
	std::cin >> row >> col;

	Matrix a(row, col), b(row, col), c(row, col);
	a.getMatrix();
	std::cout << std::endl;
	a.print();
	std::cout << std::endl;
	b.getMatrix();
	std::cout << std::endl;
	b.print();
	std::cout << std::endl;

	c = a + b;
	std::cout << "The matrix sum is:" << std::endl;
	c.print();
	std::cout << std::endl;

	return 0;
}
