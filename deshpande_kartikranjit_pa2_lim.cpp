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
                ** Compare two int strings
                ** return 1 if first is bigger
                ** return 0 if second is bigger
                */
                int compare(string a, string b)
                {
                        if ( a.size() > b.size() )
                        {
                                return 1;
                        }
                        else if ( a.size() < b.size() )
                        {
                                return -1;
                        }
                        else
                        {
                                // both strings are of equal length

				for ( int i = 0; i <= a.size(); i ++ )
				{
					if ( a[i] > b[i] )
					{
						return 1;
					}
					else if ( a[i] < b[i] ) {
						return -1;
					}
				}
                        }
                }

		string division(string number, string divisor)
		{
			while ( compare(number , divisor) == 1 )
			{
	
			}
		}


		/*
		** Modulus of two large int strings
		*/
		string modulus(string number, string divisor )
		{
			// if in case both number and divisor are equal
			if ( number == divisor )
			{
				return "1";
			}

			// if divisor > number
			if ( divisor.size() > number.size() )
			{
				return "0";
			}

			int number_end_index = divisor.size();
			bool flag = true;
			string remainder = "";
			string quotient;

			while ( compare(number , divisor) == 1 )  
			{
				// if number is gt then or equal to divisor proceed with divison else add one more digit
				if ( compare(number.substr(0,number_end_index) , divisor) != 1 )
				{
					number_end_index = number_end_index + 1;
					// divisor does not go into quotient , append a 0 to quotient
					quotient.append("0");
				}
				remainder = to_string(atoi(number.substr(0,number_end_index).c_str()) % atoi(divisor.c_str()));
				quotient.append(to_string(atoi(number.substr(0,number_end_index).c_str()) / atoi(divisor.c_str())));
				number.erase(0,number_end_index);
				number.insert(0,remainder);
			}

			// remove all first '0' occurances from quotient
			for(char& c : quotient) 
			{
				if ( c == '0' )
				{
					quotient.erase(0,1);
				}
				else
				{
					break;
				}
			} 	
			
			return remainder;
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
			modulus(numb1,numb2);

			return numb1;
		}
	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1;
	cout << m1.modulus("756812","12") << "\n";
}

