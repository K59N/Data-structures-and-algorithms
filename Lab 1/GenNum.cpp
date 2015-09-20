/* Filename : GenNum.cpp
 * Author : Loc VU
 * Date : 7, Sep, 2015
 */

//! \brief write to DAYSO1.txt
//!         - a random number n
//!         - n number each line

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	ofstream file("DAYSO1.txt");
	int n;
	srand(time(0));
	n = rand()%100;
	file << n << endl;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;
		file << a[i] << endl;
    }
	file.close();
	return 0;
}
