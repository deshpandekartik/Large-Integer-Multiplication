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
					else if ( a[i] < b[i] ) 
					{
						return -1;
					}
				}
                        }
                }

		/*
		** Substracting two large numnbers in string format
		*/
		string sub(string number1, string number2)
		{
			while( number1.length() < number2.length() )
			{
				number1.insert(0,"0");
			}

			while( number2.length() < number1.length() )
                        {
                                number2.insert(0,"0");
                        }

			string result, sub_res ;
			int carry = 0;
			for ( int i = number1.size() - 1; i >=0 ; i-- )
			{
				int num1 = number1.at(i);
				int num2 = number2.at(i) + carry;
				if ( num1 == num2 )
				{
					result.insert(0,"0");	
					carry = 0;
				}
				else if ( num1 > num2 )
				{
					result.insert(0,to_string(num1 - num2));
					carry = 0;
				}
				else if ( num1 < num2 )
				{
					string cary_res =  to_string((num1 + 10) - num2);
					result.insert(0,cary_res.substr(cary_res.size() - 1 , cary_res.size()));
					cary_res = cary_res.substr(0,cary_res.size() - 1);
					carry = atoi(cary_res.c_str()) ;
					carry = carry + 1;
				}
			}
			// remove leading zeros
			result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
			return result;
		}

		/*
		** Divsion of two large numbers in string
		*/
		string div(string number, string divisor)
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

			string quotient = "0";
			while ( compare(number , divisor) == 1 )
			{
				number = sub(number, divisor);
				int quo = atoi(quotient.c_str());
				quo = quo + 1;
				quotient = to_string(quo);
			}

			return quotient;
		}


		/*
		** Modulus of two large int strings
		*/
		string modulus(string number, string divisor )
		{
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
			div(numb1,numb2);

			return numb1;
		}
	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1;
	cout << m1.div("25478962145544","546105749") << "\n";
}

