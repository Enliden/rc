#include <iostream>
#include <math.h>
using namespace std;


#define L intervalcount_L
#define n datasize_n
#define K intervalsize_K
#define m maxval_m

int main(void)
{
	unsigned int intervalcount_L = 1;
	unsigned int datasize_n = 1;
	unsigned int intervalsize_K = 1;
	unsigned int maxval_m = 0;
	unsigned int * data = NULL;
	unsigned int * histogram = NULL;
	
	//Read in number of intervals
	cin >> L;

	//Read in number of data
	cin >> n;

	// initialize data-array
	data = new unsigned int[n];
	

	//Read in the data
	for(unsigned int i = 0; i<n; i++)
		cin >> data[i];


	for(unsigned int i = 1; i <= n; i++)
	{
		if(data[i-1] > m)
		{
			m = data[i-1];
		}
	}

	//Calculate interval size
	K = ceil( m / (double)L);

	if (K == 0) K = 1;

	//initialize histogram
	histogram = new unsigned int[L];

	for(unsigned int i = 0; i<L ; i++)
		histogram[i] = 0;

	for(unsigned int i = 0; i<L ; i++)
	{
		//int entry = min(data[i]/K,L-1);
		histogram[min(data[i]/K,L-1)]++;

	}
	
	// Result is output
	for(unsigned int i = 0; i<L; i++)
	{
	cout << i*K << ": " << histogram[i] << endl;
	}
	
	delete [] data;
	delete [] histogram;
	
return 0;
}
