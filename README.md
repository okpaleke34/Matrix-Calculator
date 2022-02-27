# Matrix-Calculator
Matrix calculator (loading from file and saving to file) Add, subtract, multiply, transform, determinant, inverse of the matrix operations needs to be implemented. Matrix in files can have



## 1. Project’s Topic
Matrix calculator (loading from file and saving to file) Add, subtract, multiply, transform, determinant, inverse of the matrix operations needs to be implemented. Matrices in files can have different sizes. The format of matrix file is size (2 numbers divided by semicolon, lines start with #) in the first line and then matrix data divided by semicolons example: <br />
`#2;2`<br/> 
`1;1`<br /> 
`2;2` <br />
Program should get following switches from console: 
-a input file for A matrix
-b input file for B matrix 
-o output file with results of calculation or error message if calculations cannot be performed
-operation 'name' – name of operation to be performed, example „operation add”
2. Analysis of the task
To perform this task a comprehensive knowledge of matrices should be known. The task focuses on adding, subtracting and multiplying two matrices and also finding the determinant, inverse and transpose of the matrix.

## 2.1 Data Structures
The structure used to save data inside the program is vector<vector<int>>

## 2.2 Algorithms

## 3. External Specifications

This program runs in the command line and requires the path to the input, output files and the command to execute. Eg

For command that need two input files like Addition, Subtraction and Multiplication of matrix

Program `-a input-file-a -a input-file-b -o output-file` operation command

For command that need one input files like Transform, Inverse and determinant of matrix

Program `-a input-file -o output-file operation command`

 Both files are text files. The switches may be provided in any order. The program is called with no parameters or with -h prints help manual.
Program call:<br/>
	`program`<br/>
	`program -h`<br/>
This prints the program manual.
A program called with incorrect parameters or wrong input file prints an error.

## 4. Internal Specifications

The program is implemented with a structural paradigm. Most of the matrix operation is stored in the Matrix module and the cpp_project.cpp contains the switch processing.

## 4.1. Program overview

The main function calls the permutation() which takes the command line parameters of the program and assigns it to the respective value and returns the value in the Switches struct. If there is wrong input or incomplete parameter it will notify the user. Finally the program saves the command in the output file.
 

## 5. Testing 

The program was tested with readable file types(non binary) as input but it is advisable to use .txt file as an input. The program can perform addition and subtraction of any well structured Matrix but in other operations the matrix will be required to have a minimum of 10 rows or columns but this can be changed by increasing the MAX macro definition.

## 6. Conclusion
The program performs all matrix operations like add, subtract, multiply, transform, determinant, inverse of a matrix. The input and output will be stored in text files and there is possibility of command line permutation. 
