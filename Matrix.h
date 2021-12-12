#ifndef MATRIX_H
#define MATRIX_H
const int msize=100;
using namespace std;

class Matrix
{
	public:
		Matrix();
		Matrix(string n);
		
		void iiport(string n);
		
		void printmatrix();
		void randomize();
		int sum();
		int get_size();
		int get_entry(int y, int x);
		int get_indexzerozero();
		string xxport();
		string minor(int k);
	private:
		int s;
		int m[msize][msize];
};

#endif
