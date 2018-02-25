#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
using namespace std;

class LargeIntMul
{
	public:
		string number1 = "12345" , number2 = "123123";
		int threshold = 5;	// lets say
	      
		/*
		** Computes max of 2 numbers	
		*/
		int find_max(int a , int b)
		{
			if ( a > b )
			{
				return a;
			}
			else
			{
				return b;
			}
		}


		/*
		** Dividing two large int strings
		*/
		string division(string number, string divisor)
		{
			// for division to happen make number and divisior of same length
			// if no is 8999 divisor is 99 make it 8999/0099
			// make strings of same length
			while ( number.size() < divisor.size() )
			{
				number = '0' + number;
			}

			while ( divisor.size() < number.size() )
                        {
                                divisor = '0' + divisor;
                        }		

			cout << number << "/" << divisor << "\n";
			return "empty";
		}		

		/*
		** Recursively calculate product of two large numbers
		*/
		string prod(string numb1, string numb2)	
		{
			// No of digits in numb1 and numb2
			int a = numb1.size();
			int b = numb2.size();

			if ( a == 0 || b == 0 )
			{
				// anything multiplied by 0 is 0
				return "0";
			}	
				
			int n = max(a,b);	
			if ( n <= threshold )
			{
				return to_string(atoi(numb1.c_str()) * atoi(numb2.c_str()));
			}

			int m = floor(n/2); 	//	m = [ n/2 ]
			division(numb1,numb2);

			return numb1;
		}
	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1;
	cout << m1.prod("1231","12123123") << "\n";
}

