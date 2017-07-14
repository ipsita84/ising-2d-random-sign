// g++ -Wall -O3 disorder-equal-plus-minus.cc -o testo
//disorder for equal no. of plus minus bonds

#include <iostream>
#include <fstream>
#include <ctime>
#include <boost/multi_array.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>

// gen is a variable name
// Its data-type is boost::random::mt19937
boost::random::mt19937 gen(std::time(0)); // time(0) changes seed every time you run
//not to change seed: use 
//boost::random::mt19937 gen;
using namespace std;

typedef
boost::multi_array < int, 2 > array_2d;
// typedef keyword allows you to create an alias fo a data type

const unsigned int axis1 = 8 ; // choose axxes to have even no. of sites
const unsigned int axis2 = axis1 ;
// above assigns length along each dimension of the 2d configuration

//Function templates
int roll_coin(int a, int b);
double random_real(int a, int b);

int main()
{
	array_2d J_x(boost::extents[axis1][axis2]);
	array_2d J_y(boost::extents[axis1][axis2]);

	unsigned int sys_size = axis1 * axis2 ;
	//Assign random sign to each NN bond & store in an array
	ofstream fout("Jx.dat");	// Opens a file for output
	ofstream gout("Jy.dat");
 	

// first set all the J_x and J_y to +1

	for (unsigned int i = 0; i < axis1; ++i)
	{
		for (unsigned int j = 0; j < axis2; ++j)
		{
			J_x[i][j] = 1;
			J_y[i][j] = 1;
		}
	}


//Randomly pick half of J_x and set them to -1
	for (unsigned int i = 1 ; i <= sys_size / 2; ++i)
	{
		unsigned int row = roll_coin(0,axis1-1);
                unsigned int col = roll_coin(0,axis2-1);
		J_x[row][col] = -1;
	}

//Randomly pick half of J_y and set them to -1
	for (unsigned int i = 1 ; i <= sys_size / 2; ++i)
	{
		unsigned int row = roll_coin(0,axis1-1);
                unsigned int col = roll_coin(0,axis2-1);
		J_y[row][col] = -1;
	}


// now print all the J_x and J_y values in 2 files

       for (unsigned int i = 0; i < axis1; ++i)
	{
		for (unsigned int j = 0; j < axis2; ++j)
		{
			fout << J_x[i][j] << endl;
			gout << J_y[i][j] << endl;
		}
	}

	fout.close();
	gout.close();
	return 0;
}



//function to generate random integer
// between 2 integers a & b, including a & b
int roll_coin(int a, int b)
{
	boost::random::uniform_int_distribution <> dist(a, b);
	return dist(gen);
}

//function to generate random real no.
// between 2 integers a & b, including a & excluding b

double random_real(int a, int b)
{
	boost::random::uniform_real_distribution <> dist(a, b);
	// uniform_real_distribution: continuous uniform distribution
	//on some range [min, max) of real number
	return dist(gen);
}
