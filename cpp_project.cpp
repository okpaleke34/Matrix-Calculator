#include <iostream>
#include <vector>
#include <string>
#include "Matrix.cpp"

using std::string;
using std::vector;

struct Switches
{
	string input_a;
	string input_b;
	string output;
	string operation;
	bool help = false;
};
struct Switches permuation(int, char **);

int main(int argc, char **argv)
{
	struct Switches mySwitch;
	mySwitch = permuation(argc, argv);
	std::cout << "\n-Output File: " << mySwitch.output << "\n-Input File A: " << mySwitch.input_a << "\n-Input File B: " << mySwitch.input_b << "\n-Operation: " << mySwitch.operation << std::endl;

	if (argc == 8)
	{
		Matrix M(mySwitch.output);
		vector<vector<int>> matrix_a;
		vector<vector<int>> matrix_b;
		matrix_a = M.readFile(mySwitch.input_a);
		matrix_b = M.readFile(mySwitch.input_b);

		if (mySwitch.operation == "add")
		{
			M.add(matrix_a, matrix_b);
		}
		else if (mySwitch.operation == "subtract")
		{
			M.subtract(matrix_a, matrix_b);
		}
		else if (mySwitch.operation == "multiply")
		{
			M.multiply(matrix_a, matrix_b);
		}
		else
		{
			cout << "argv[7] should be either add, subtract, multiply but " << argv[7] << " found.";
		}
	}
	else if (argc == 7)
	{
		Matrix M(mySwitch.output);
		vector<vector<int>> matrix;
		matrix = M.readFile(mySwitch.input_a);
		if (mySwitch.operation == "inverse")
		{
			M.inverse(matrix);
		}
		else if (mySwitch.operation == "transform")
		{
			M.transpose(matrix, 1);
		}
		else if (mySwitch.operation == "determinant")
		{
			M.determinant(matrix, 1);
		}
		else
		{
			cout << "argv[6] should be either transform, inverse, determinant but " << argv[6] << " found.";
		}
	}
	else
	{

		if (!mySwitch.help)
		{
			cout << "Command line switches not accepted";
		}
	}
	return 0;
}
/*
* This function loop through all the switch and assign it to the Switch struct according to the previous value.
* This helps in permutation of the switch which means any switch can be added any place without following strict position.
*@param argv is the array of all the switches
*@param argc is the total number of the switch seperated by space entered
*@return It returns a struct that contains all the switches
*/
struct Switches permuation(int argc, char **argv)
{
	Switches mySwitch;
	if (argc == 1)
	{
		mySwitch.help = true;
	}
	for (int i = 0; i < argc; i++)
	{

		if (i != 0)
		{
			string prevSwitch = argv[i - 1];
			string currSwitch = argv[i];
			if (currSwitch == "-h")
			{
				mySwitch.help = true;
			}
			else if (prevSwitch == "-a")
			{
				mySwitch.input_a = argv[i];
			}
			else if (prevSwitch == "-b")
			{
				mySwitch.input_b = argv[i];
			}
			else if (prevSwitch == "-o")
			{
				mySwitch.output = argv[i];
			}
			else if (prevSwitch == "operation")
			{
				mySwitch.operation = argv[i];
			}
		}
	}
	if (mySwitch.help)
	{
		cout << "Welcome to this Matrix Calculator program. "
			 << "\nThis program handles all the matrix operation such as  addition, subtraction, multiplication, inverse, determinant and transform(transpose)."
			 << "\nTo handle this operation you need to create an input file and make use of the correct commandline switch."
			 << "Analogy of an input file is that the first character is going to be '#' without apostrophe then each number will be seperated by ';'"
			 << "\nExample of an input file is a .txt file that contains this \n\n#3;4;23\n2;3;1\n"
			 << "\nThis is an example of a 2x3 matrix. Put this in a file and save it as input_a.txt then create a similar one with another integer value and save with input_b.txt"
			 << "\n\nThen on the command type  \n\n./main -a ./input_a.txt -b ./input_b.txt -o ./output.txt operation add"
			 << "\n\nThis will add the two matrix and put it in the new created file output.txt You can also perfom similar operation by changing the operation name from add to multiply or subtract. Remember to follow matrix rules."
			 << "\n\nThen to perform opertaion like determinant, inverse and transform that requires only one matrix file you have to use the command"
			 << "\n\n./main -a ./input_a.txt -o ./output.txt operation inverse"
			 << "\n\nThis will get the inverse of the input matrix and put it in the new created file output.txt You can also perfom similar operation by changing the operation name from inverse to transform or determinant. Remember to follow matrix rules.";
	}
	else
	{
		if (mySwitch.output == "")
		{
			cout << "\nThis program requires an output file and none was find in the switch provided.\n\n";
			exit(10);
		}
		if (mySwitch.input_a == "")
		{
			cout << "\nThis program requires atleast 1 input file and none was find in the switch provided.\n\n";
			exit(10);
		}
	}
	return mySwitch;
}