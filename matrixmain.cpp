#include <iostream>
#include <math.h>
#include <string>
#include "Matrix.cpp"


using namespace std;
int determinant(Matrix n)
{
	if (n.get_size() == 1) return n.get_indexzerozero();
	int sum=0;
	Matrix m;
	for (int i=0;i<n.get_size();i++)
	{
		m.iiport(n.minor(i));
		sum+=pow((-1),i)*n.get_entry(0,i)*determinant(m);
	}
	return sum;
}

int main()
{
cout<<
"This is a recursive determinant calculator."<<endl<<
"Would you believe it's probably harder to "<<endl<<
"code a calculator to find the determinant"<<endl<<
"via row reduction? Anyway, enter '1' for"<<endl<<
"an example, or '2' to enter you own matrix"<<endl;

int i;
cin >>i;
if (i==1)
{
Matrix a("4 1 4 2 3 0 1 4 4 -1 0 1 0 2 0 4 1");
a.printmatrix();
cout<<determinant(a);
}
else
{
cout<<
"To enter the matrix, enter a string with the"<<endl<<
"first entry the size of the matrix, then"<<endl<<
"followed by the matrix values, row by row."<<endl<<
"Example: '2 5 10 9 18' yeilds a zero determinant."<<endl;

string input;
//getline(cin,input);
cin>>input;
//cout<<input;
Matrix b;
b.iiport(input);
cout<<endl;
b.printmatrix();
cout<<determinant(b);
}
}
	
	
