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
Matrix a("4 1 4 2 3 0 1 4 4 -1 0 1 0 2 0 4 1");
a.printmatrix();
cout<<determinant(a);
}
	
