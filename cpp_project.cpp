#include <iostream>
#include <vector>
#include <string>
#include "Matrix.cpp"

using std::string;
using std::vector;

int main(int argc, char **argv)
{

	if (argc == 5)
	{
		string input_a = argv[1];
		string input_b = argv[2];
		string output = argv[3];
		string flag = argv[4];
		Matrix M(output);
		vector<vector<int>> matrix_a;
		vector<vector<int>> matrix_b;
		matrix_a = M.readFile(input_a);
		matrix_b = M.readFile(input_b);

		if (flag == "add")
		{
			M.add(matrix_a, matrix_b);
		}
		else if (flag == "subtract")
		{
			M.subtract(matrix_a, matrix_b);
		}
		else if (flag == "multiply")
		{
			M.multiply(matrix_a, matrix_b);
		}
		else
		{
			cout << "argv[4] should be either add, subtract, multiply but " << argv[4] << " found.";
		}
	}
	else if (argc == 4)
	{
		string input = argv[1];
		string output = argv[2];
		string flag = argv[3];
		Matrix M(output);
		vector<vector<int>> matrix;
		matrix = M.readFile(input);
		if (flag == "inverse")
		{
			M.inverse(matrix);
		}
		else if (flag == "transform")
		{
			M.transpose(matrix, 1);
		}
		else if (flag == "determinant")
		{
			M.determinant(matrix,1);
		}
		else
		{
			cout << "argv[3] should be either transform, inverse, determinant but " << argv[3] << " found.";
		}
	}
	else
	{
		cout << "Command line switches not accepted";
	}
	//g++ cpp_project.cpp -o main
	//./main ./input_a.txt ./input_b.txt  ./output.txt multiply
	return 0;
}