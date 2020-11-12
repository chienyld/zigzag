#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <memory>		
#include <iomanip>
using namespace std;

int ** RandomMatrix(int size, int range)
{
	int ** matrix;
	
	matrix = new(int * [size]);
	for(int i=0; i<size; i++)
		matrix[i] = new(int [size]);
	
	srand(time(NULL));
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			matrix[i][j] = rand() % range;
	
	return matrix;
}

int * ColumnSum(int **matrix, int size)
{
	int *sum;
	
	return sum;
}

int * RowSum(int **matrix, int size)
{
	int *sum;
	
	return sum;
}

typedef vector< int > IntRow;
typedef vector< IntRow > IntTable;
 
auto_ptr< IntTable > getZigZagArray( int dimension )
{
	auto_ptr< IntTable > zigZagArrayPtr( new IntTable(
		dimension, IntRow( dimension ) ) );
 
	// fill along diagonal stripes (oriented as "/")
	int lastValue = dimension * dimension - 1;
	int currNum = 1;
	int currDiag = 0;
	int loopFrom;
	int loopTo;
	int i;
	int row;
	int col;
	do
	{
		if ( currDiag < dimension ) // if doing the upper-left triangular half
		{
			loopFrom = 0;
			loopTo = currDiag;
		}
		else // doing the bottom-right triangular half
		{
			loopFrom = currDiag - dimension + 1;
			loopTo = dimension - 1;
		}
 
		for ( i = loopFrom; i <= loopTo; i++ )
		{
			if ( currDiag % 2 == 0 ) // want to fill upwards
			{
				row = loopTo - i + loopFrom;
				col = i;
			}
			else // want to fill downwards
			{
				row = i;
				col = loopTo - i + loopFrom;
			}
 
			( *zigZagArrayPtr )[ row ][ col ] = currNum++;
		}
 
		currDiag++;
	}
	while ( currDiag <= lastValue );
 
	return zigZagArrayPtr;
}
auto_ptr< IntTable > getInverseZigZagArray( int dimension )
{
	auto_ptr< IntTable > zigZagArrayPtr( new IntTable(
		dimension, IntRow( dimension ) ) );
 
	// fill along diagonal stripes (oriented as "/")
	int lastValue = dimension * dimension - 1;
	int currNum = 1;
	int currDiag = 0;
	int loopFrom;
	int loopTo;
	int i;
	int row;
	int col;
	do
	{
		if ( currDiag < dimension ) // if doing the upper-left triangular half
		{
			loopFrom = 0;
			loopTo = currDiag;
		}
		else // doing the bottom-right triangular half
		{
			loopFrom = currDiag - dimension + 1;
			loopTo = dimension - 1;
		}
 
		for ( i = loopFrom; i <= loopTo; i++ )
		{
			if ( currDiag % 2 == 0 ) // want to fill upwards
			{
				row = loopTo - i + loopFrom;
				col = i;
			}
			else // want to fill downwards
			{
				row = i;
				col = loopTo - i + loopFrom;
			}
 
			( *zigZagArrayPtr )[ col ][ row ] = currNum++;
		}
 
		currDiag++;
	}
	while ( currDiag <= lastValue );
 
	return zigZagArrayPtr;
}
void printZigZagArray( const auto_ptr< IntTable >& zigZagArrayPtr )
{
	size_t dimension = zigZagArrayPtr->size();
 
	int fieldWidth = static_cast< int >( floor( log10(
		static_cast< double >( dimension * dimension - 1 ) ) ) ) + 2;
 
	size_t col;
	for ( size_t row = 0; row < dimension; row++ )
	{
		for ( col = 0; col < dimension; col++ )
			cout << setw( fieldWidth ) << ( *zigZagArrayPtr )[ row ][ col ]<< "\t";
		cout << endl;
	}
}
void printZigZagLine( const auto_ptr< IntTable >& zigZagArrayPtr )
{
	size_t dimension = zigZagArrayPtr->size();
 
	int fieldWidth = static_cast< int >( floor( log10(
		static_cast< double >( dimension * dimension - 1 ) ) ) ) + 2;
 
	size_t col;
	for ( size_t row = 0; row < dimension; row++ )
	{
		for ( col = 0; col < dimension; col++ )
			cout << setw( fieldWidth ) << ( *zigZagArrayPtr )[ row ][ col ]<< " ";
		//cout << endl;
	}
}

int **ZigZagMatrix(int size, int order)
{
	if(order==1){
	printZigZagArray( getZigZagArray(size) );
	}
	else if(order==2){
	printZigZagArray( getInverseZigZagArray(size) );	
	}
	else{
	cout << "you entered a wrong order" << endl;
	}
}
int **ZigZagLine(int size, int order)
{
	if(order==1){
	printZigZagLine( getZigZagArray(size) );
	}
	else if(order==2){
	printZigZagLine( getInverseZigZagArray(size) );	
	}
	else{
	cout << endl;
	}
}
int main(int argc, char** argv) 
{
	int s, r;
	int **data;
	int *t;
	int order;
	cout << "Input the matrix size: ";
	cin >> s;
	cout << "Input the range of every matrix element: ";
	cin >> r;
	cout << "Input the zigzag matrix order(1 or 2): ";
	cin >> order;
	
	cout << "The Zigzag matrix is " << endl;
	int **zz = ZigZagMatrix(s,order);
	cout << endl;
	cout << "The Zigzag matrix in line is " << endl;
	int **zzline = ZigZagLine(s,order);
	cout << endl;

	// Got a matrix
	data = RandomMatrix(s, r);
	
	// Show the matrix
	cout << "The matrix is " << endl;
	for(int i=0; i<s; i++)
	{
		for(int j=0; j<s; j++)
			cout << data[i][j] << "\t";			
		cout << endl;
	}
	int total = 0;
	for(int i=0; i<s; i++)
	{
		for(int j=0; j<s; j++)
			total += data[i][j];
	}
	cout << "The sum of the matrix is" << endl;
	cout << total << endl;
	int colsum = 0;
	//t = ColumnSum(data, s);
	cout << "The sum of each column is" << endl;
	for (int i = 0; i < s; ++i) {
      for (int j= 0; j < s; ++j) {
         colsum = colsum + data[j][i];
      }
	  cout << colsum << "\t";
	  colsum = 0;
	}
	cout << endl;


	int sumrow = 0;
	//t = RowSum(data, s);
	cout << "The sum of each row is"<< endl;
	for (int i = 0; i < s; ++i) {
      for (int j= 0; j < s; ++j) {
         sumrow = sumrow + data[i][j];
      }
	  cout << sumrow << "\t";
	  sumrow = 0;
	}
		
	return 0;
}
