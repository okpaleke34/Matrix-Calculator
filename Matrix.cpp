#include "Matrix.h"
/*
* @constructor saves the class parameter to the private std::string savefile
* @param output_file is the matrix to verify
*/
Matrix::Matrix(string output_file)
{
	this->savefile = output_file;
}

/*
* Verify and get the dimension of a matrix
* @param matrix is the matrix to work on
* @return this returns a structure of the matrix dimension 
*/
struct Dim Matrix::dimension(vector<vector<int>> matrix)
{
	struct Dim thisDim;
	if (this->verify(matrix))
	{
		thisDim.row = matrix.size();
		thisDim.column = matrix[0].size();
	}
	return thisDim;
}

/*
* Verify if all matrix rows and columns are complete
* @param matrix is the matrix to verify
* @return this returns an int 1 if it is good matrix and 0 if it is not a well structured matrix
*/
int Matrix::verify(vector<vector<int>> matrix)
{
	size_t firstRow = matrix[0].size();
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != firstRow)
		{
			cout << "matrix[i].size(): " << i << ": " << matrix[i].size() << " first row: " << firstRow;
			return 0;
		}
	}
	return 1;
}

/*
* This write the sum of two matrix into the output file
* It will first make sure both of the columns and rows are same
* It will first make sure both of the columns and rows are same
* @param matrix_a is the operand 1
* @param matrix_b is the operand 2
*/
void Matrix::add(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b)
{
	if (this->verify(matrix_a) && this->verify(matrix_b))
	{
		struct Dim dim_a = this->dimension(matrix_a);
		struct Dim dim_b = this->dimension(matrix_b);
		if (dim_a.row == dim_b.row)
		{
			if (dim_a.column == dim_b.column)
			{
				string data = "#";
				int sum;
				for (int i = 0; i < matrix_a.size(); i++)
				{
					for (int j = 0; j < matrix_a[i].size(); j++)
					{
						sum = matrix_a[i][j] + matrix_b[i][j];
						if (matrix_a[i].size() - 1 == j)
						{
							data += std::to_string(sum);
						}
						else
						{
							data += std::to_string(sum);
							data += ";";
						}
					}
					data += "\n";
				}
				this->writeFile(data);
			}
			else
			{
				std::cout << "For two matrix to be added it must have the same number of columns" << std::endl;
			}
		}
		else
		{
			std::cout << "For two matrix to be added it must have the same number of rows" << std::endl;
		}
	}
	else
	{
		std::cout << "One of the matrix file does not have complete rows and column" << std::endl;
	}
}

/*
* This write the difference of two matrix into the output file
* It will first make sure both of the columns and rows are same
* @param matrix_a is the matrix that will be removed from
* @param matrix_b is the matrix subtract
*/
void Matrix::subtract(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b)
{
	if (this->verify(matrix_a) && this->verify(matrix_b))
	{
		struct Dim dim_a = this->dimension(matrix_a);
		struct Dim dim_b = this->dimension(matrix_b);
		if (dim_a.row == dim_b.row)
		{
			if (dim_a.column == dim_b.column)
			{
				string data = "#";
				int difference;
				for (int i = 0; i < matrix_a.size(); i++)
				{
					for (int j = 0; j < matrix_a[i].size(); j++)
					{
						difference = matrix_a[i][j] - matrix_b[i][j];
						if (matrix_a[i].size() - 1 == j)
						{
							data += std::to_string(difference);
						}
						else
						{
							data += std::to_string(difference);
							data += ";";
						}
					}
					data += "\n";
				}
				this->writeFile(data);
			}
			else
			{
				std::cout << "For a matrix to be subtracted from another they must have the same column" << std::endl;
			}
		}
		else
		{
			std::cout << "For a matrix to be subtracted from another they must have the same row" << std::endl;
		}
	}
	else
	{
		std::cout << "One of the matrix file does not have complete rows and column" << std::endl;
	}
}
/*
* if Matrix A is a {m} x {n} matrix and matrix B is {n} x {p} matrix
* The product of AB will be a {m} x {p} Matrix, given that {n} == {n}
* @param matrix_a is the matrix that will be in the left hand side
* @param matrix_b is the matrix that will be in the right hand side
* Note: matrix_a X matrix_b != matrix_b X matrix_a
*/
void Matrix::multiply(vector<vector<int>> matrix_a, vector<vector<int>> matrix_b)
{
	if (this->verify(matrix_a) && this->verify(matrix_b))
	{
		struct Dim dim_a = this->dimension(matrix_a);
		struct Dim dim_b = this->dimension(matrix_b);
		if (dim_a.column == dim_b.row)
		{
			int i, j, k;
			string data = "#";
			for (i = 0; i < dim_a.row; ++i)
			{
				for (j = 0; j < dim_b.column; ++j)
				{
					int product = 0;
					for (k = 0; k < dim_a.column; ++k)
					{
						product += matrix_a[i][k] * matrix_b[k][j];
					}

					if (dim_b.column - 1 == j)
					{
						data += std::to_string(product);
					}
					else
					{
						data += std::to_string(product);
						data += ";";
					}
				}
				data += "\n";
			}
			this->writeFile(data);
		}
		else
		{
			std::cout << "For matrix 'a' to be multiplied by another matrix 'b' the column of matrix 'a' must be same with row of matrix 'b'" << std::endl;
		}
	}
	else
	{
		std::cout << "One of the matrix file does not have complete rows and column" << std::endl;
	}
}
/*
* This transfers the column to row and row to column
* @param matrix the matrix to be transformed
* @param type if this is set to 1 it means it should write the transpose to a file else it should just return it 
*/
vector<vector<int>> Matrix::transpose(vector<vector<int>> matrix, int type)
{
	vector<vector<int>> transpose;
	if (this->verify(matrix))
	{
		struct Dim dim = this->dimension(matrix);
		double tran[10][10];
		for (int i = 0; i < dim.row; ++i)
		{
			for (int j = 0; j < dim.column; ++j)
			{
				tran[j][i] = matrix[i][j];
			}
		}

		for (int i = 0; i < dim.column; ++i)
		{
			vector<int> subMatrix;
			for (int j = 0; j < dim.row; ++j)
			{
				subMatrix.push_back(tran[i][j]);
			}
			transpose.push_back(subMatrix);
		}
	}
	else
	{
		std::cout << "One of the matrix file does not have complete rows and column" << std::endl;
	}
	if (type == 1)
	{
		this->writeFile(transpose);
	}
	return transpose;
}
/*
 * 
 * @param matrix is the square matrix to get its cofactor
 * @param p is the row minor
 * @param q is the column minor
*/
vector<vector<int>> Matrix::cofactor(vector<vector<int>> matrix, int p, int q)
{
	vector<vector<int>> cofactor;
	if (this->verify(matrix))
	{
		struct Dim dim = this->dimension(matrix);
		if (dim.column == dim.row)
		{
			int i = 0, j = 0;
			struct Dim dim = this->dimension(matrix);
			size_t n = dim.row;
			int temp[10][10];
			// Looping for each element of the matrix
			for (int row = 0; row < n; row++)
			{
				for (int col = 0; col < n; col++)
				{
					// Copying into temporary matrix only those element
					// which are not in given row and column
					if (row != p && col != q)
					{
						temp[i][j++] = matrix[row][col];
						// Row is filled, so increase row index and
						// reset col index
						if (j == n - 1)
						{
							j = 0;
							i++;
						}
					}
				}
			}
			for (size_t i = 0; i < n - 1; i++)
			{
				vector<int> matrixRow;
				for (size_t j = 0; j < n - 1; j++)
				{
					matrixRow.push_back(temp[i][j]);
				}
				cofactor.push_back(matrixRow);
			}
		}
		else
		{
			std::cout << "You can only get a cofactor of a square matrix." << std::endl;
		}
	}
	else
	{
		std::cout << "The matrix file does not have complete rows and column" << std::endl;
	}
	return cofactor;
}
/*
* The adjoint returns the transpose of the cofactor of the matrix
* @param matrix is a multidimensional matrix array that will be worked on
* @return it will return a adjoint[matrix] of the input matrix
*/
vector<vector<int>> Matrix::adjoint(vector<vector<int>> matrix)
{
	vector<vector<int>> adjoint;
	if (this->verify(matrix))
	{
		struct Dim dim = this->dimension(matrix);
		if (dim.column == dim.row)
		{
			int n = dim.row;
			if (n == 1)
			{
				vector<int> innerMatrix;
				innerMatrix.push_back(1);
				adjoint.push_back(innerMatrix);
				return adjoint;
			}

			int sign = 1;
			// temp is used to store cofactors of A[][]
			vector<vector<int>> temp;
			for (int i = 0; i < n; i++)
			{
				vector<int> matrixRow;
				for (int j = 0; j < n; j++)
				{
					// Get cofactor of A[i][j]
					temp = this->cofactor(matrix, i, j);
					// sign of adj[j][i] positive if sum of row
					// and column indexes is even.
					sign = ((i + j) % 2 == 0) ? 1 : -1;

					// Interchanging rows and columns to get the
					// transpose of the cofactor matrix
					matrixRow.push_back((sign) * (this->determinant(temp, 0)));
				}
				adjoint.push_back(matrixRow);
			}
		}
		else
		{
			std::cout << "You can only get an adjoint of a square matrix." << std::endl;
		}
	}
	else
	{
		std::cout << "The matrix file does not have complete rows and column" << std::endl;
	}
	return adjoint;
}

/*
* This multiple each cell of the matrix by a given constant
* @param matrix is a multidimensional matrix array that will be worked on
* @param k is the contant to multiple the whole matrix cell with
*/
vector<vector<double>> Matrix::multiplyByConstant(vector<vector<int>> matrix, double k)
{
	vector<vector<double>> productMatrix;
	struct Dim dim = this->dimension(matrix);
	for (int i = 0; i < dim.row; i++)
	{
		vector<double> matrixRow;
		for (int j = 0; j < dim.column; j++)
		{
			matrixRow.push_back(matrix[i][j] * float(k));
		}
		productMatrix.push_back(matrixRow);
	}
	return productMatrix;
}
/*
* Get the inverse of a matrix A^-1
* Note that AA^-1 = E
* @param matrix is a multidimensional matrix array that will be worked on
* It will save the inverse to a file
*/
void Matrix::inverse(vector<vector<int>> matrix)
{
	struct Dim dim = this->dimension(matrix);
	int n = dim.row;
	int det = this->determinant(matrix, 0);
	if (det == 0)
	{
		cout << "Singular matrix, can't find its inverse\n";
	}

	// Find adjoint
	vector<vector<int>> adjoint;
	adjoint = this->adjoint(matrix);
	//get the transpose of the adjoint
	vector<vector<int>> transposeOfAdjoint;
	transposeOfAdjoint = transpose(adjoint, 0);
	//multiple the inverse of the determinant with the transpose of the adjoint to get the inverse
	vector<vector<double>> inverseMatrix;
	inverseMatrix = multiplyByConstant(transposeOfAdjoint, 1 / float(det));
	this->writeFile(inverseMatrix);
}

/*
* Get the determinant of a matrix
* if it is a 2x2 matrix it will multiply the main diagonal and subtract the product of the other diagonal from it
* @param matrix is a multidimensional array that will be worked on
* @param type if this is set to 1 it means it should write the determinant to a file else it should just return it 
* @return the calculated determinant of the matrix
*/
int Matrix::determinant(vector<vector<int>> matrix, int type)
{
	if (this->verify(matrix))
	{
		struct Dim dim = this->dimension(matrix);
		if (dim.row == dim.column)
		{
			size_t n = dim.column;
			double submat[MAX][MAX];
			double d = 0;
			if (n == 2)
				return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
			else
			{
				for (int c = 0; c < n; c++)
				{
					vector<vector<int>> subMatrix;
					int subi = 0; //submatrix's i value
					for (int i = 1; i < n; i++)
					{
						int subj = 0;
						vector<int> matrixRow;
						for (int j = 0; j < n; j++)
						{
							if (j == c)
								continue;
							submat[subi][subj] = matrix[i][j];
							matrixRow.push_back(matrix[i][j]);
							subj++;
						}
						subMatrix.push_back(matrixRow);
						subi++;
					}
					d = d + (pow(-1, c) * matrix[0][c] * this->determinant(subMatrix, 0));
				}
			}

			if (type == 1)
			{
				this->writeFile(std::to_string(d));
			}
			return d;
		}
		else
		{
			std::cout << "You can only find a determinant of a square matrix" << std::endl;
		}
	}
	else
	{
		std::cout << "The matrix file does not have complete rows and column" << std::endl;
	}
	return 0;
}

/*
* This reads a matrix file and set the matrix row and column to a
* {row} X {column} matrix
*/
vector<vector<int>> Matrix::readFile(string file_path)
{
	vector<vector<int>> content;
	vector<int> row;
	string line, word, file_text;
	int digit;

	fstream file(file_path, ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();
			stringstream str(line);
			while (getline(str, word, ';'))
			{
				//remove the # in the first
				if (word[0] == '#')
				{
					word.erase(0, 1);
				}
				std::stringstream ss(word);
				ss >> digit;
				row.push_back(digit);
			}
			content.push_back(row);
		}
		file.close();
	}
	else
	{
		cout << "Could not open the file\n";
	}
	return content;
}

/*
* Print a matrix data
* @param matrix is a multidimensional array that will be printed to the console
*/
template <class T>
void Matrix::printMatrix(vector<vector<T>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i].size() - 1 == j)
			{
				cout << matrix[i][j];
			}
			else
			{
				cout << matrix[i][j] << ";";
			}
		}
		cout << "\n";
	}
}

/*
* This save a vector of vector to a file
* @param matrix is a multidimensional array that will be written to the file
*/
template <class T>
void Matrix::writeFile(vector<vector<T>> matrix)
{

	fstream file(this->savefile, ios::out);
	if (file.is_open())
	{
		file << "#";
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i].size() - 1 == j)
				{
					file << std::to_string(matrix[i][j]);
				}
				else
				{
					file << std::to_string(matrix[i][j]) << ";";
				}
			}
			file << "\n";
		}

		file.close();
		cout << "Write to file successfully.\n";
	}
	else
	{
		cout << "Failed to write to file.\n";
	}
}
/*
* This save a data to a file
* @param data is the string that will be written to the file
*/
void Matrix::writeFile(string data)
{
	fstream file(this->savefile, ios::out);
	if (file.is_open())
	{
		file << data;
		file.close();
		cout << "Write to file successfully.\n";
	}
	else
	{
		cout << "Failed to write to file.\n";
	}
}