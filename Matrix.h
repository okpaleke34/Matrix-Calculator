#ifndef MATRIX_H
#define MATRIX_H

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#define MAX 10

//using namespace std;
using std::cout;
using std::fstream;
using std::ios;
using std::pow;
using std::string;
using std::stringstream;
using std::vector;

/**
 * This is a structure of dimension of a matrix row and column
*/
struct Dim
{
	size_t row = 0;
	size_t column = 0;
};

class Matrix
{
private:
	string savefile;

public:
	Matrix(string);
	struct Dim dimension(vector<vector<int>>);
	int verify(vector<vector<int>>);
	void add(vector<vector<int>>, vector<vector<int>>);
	void subtract(vector<vector<int>>, vector<vector<int>>);
	void multiply(vector<vector<int>>, vector<vector<int>>);
	int determinant(vector<vector<int>>, int);
	void inverse(vector<vector<int>>);
	vector<vector<int>> transpose(vector<vector<int>>, int);
	vector<vector<int>> adjoint(vector<vector<int>>);
	vector<vector<int>> cofactor(vector<vector<int>>, int, int);
	vector<vector<double>> multiplyByConstant(vector<vector<int>>, double);
	template <class T>
	void printMatrix(vector<vector<T>>);

	vector<vector<int>> readFile(string);
	template <class T>
	void writeFile(vector<vector<T>>);

	void writeFile(string data);
};

#endif