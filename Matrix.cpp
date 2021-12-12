#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <iomanip>
#include "Matrix.h"
#include <cassert>

using namespace std;
Matrix::Matrix()
{
	s=3;
	for(int y=0;y<msize;y++)
	{
		for(int x=0;x<msize;x++)
			m[y][x]=0;
	}
}

Matrix::Matrix(string n)
{
stringstream matrixstream(n);
matrixstream>>s;
for (int i=0;i<s*s;i++)
	matrixstream>>m[i/s][i%s];
}

void Matrix::iiport(string n)
{
	stringstream matrixstream(n);
matrixstream>>s;
for (int i=0;i<s*s;i++)
	matrixstream>>m[i/s][i%s];
}

void Matrix::printmatrix()
{
	for(int y=0;y<s;y++)
	{
		for(int x=0;x<s;x++)
			cout<<setw(2)<<m[y][x]<<" ";
		cout<<'\n';
	}
	cout<<'\n';
}

void Matrix::randomize()
{
	for (int i=0;i<s*s;i++)
	m[i/s][i%s]=i%10;
}

int Matrix::sum()
{
	int sum=0;
	for (int i=0;i<s*s;i++)
	sum+=m[i/s][i%s];
	return sum;
}

int Matrix::get_size()
{
	return s;
}

int Matrix::get_entry(int y, int x)
{
	return m[y][x];
}

int Matrix::get_indexzerozero()
{
	return m[0][0];
}

string Matrix::xxport()
{
	string matrixstring;
	stringstream matrixstream;	
	matrixstream<<s<<' ';
	for (int i=0;i<s*s;i++)
	matrixstream<<m[i/s][i%s]<<' ';
	matrixstream<<endl;
	getline(matrixstream,matrixstring);
	return matrixstring;
}

string Matrix::minor(int k)  //k for skip  0 1 2 3 4   k =2
{
	if (k >= s) {cout<<"ERROR k>=size";assert(0);return "";}
	if (s == 1) {cout<<"ERROR 1x1 does not have minor";assert(0);return "";}
	string matrixstring;
	stringstream matrixstream;
	matrixstream<<s-1<<' ';
	for (int y=1;y<s;y++)
	for (int x=0;x<s-1;x++)
	{
		//if (x==k) x++;		//I'll come back and obscufate this later.
		// !!!!! I fixed my program by obsfuscating my code!
		// Lesson learned. ALWAYS USE LEET CODE.
		matrixstream<<m[y][x+(x>=k)]<<' ';
	}
	matrixstream<<endl;
	getline(matrixstream,matrixstring);
	return matrixstring;
}

