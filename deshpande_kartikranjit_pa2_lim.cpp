#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
using namespace std;

class LargeIntMul
{
	public:
		int threshold = 5;	// lets say
	     
		struct NUMSTRUCT 
		{
			string number = "" ;
			string sign = "+";
		};
		
		NUMSTRUCT firstnumber, secondnumber; 

		LargeIntMul(string a, string b )
		{
			firstnumber.number = a;
			secondnumber.number = b;
		}

		/*
		** All Main function, calling other defined here
		*/
		string division()
		{
			NUMSTRUCT numb = div(firstnumber, secondnumber);
                        return numb.number;
		}

		string multiplication()
		{
			NUMSTRUCT numb = mul(firstnumber, secondnumber);
                        return numb.number;
		}

		string addition()
		{
			NUMSTRUCT numb = add(firstnumber, secondnumber);
                        return numb.number;
		}
		
		string substraction()
		{
			NUMSTRUCT numb = sub(firstnumber, secondnumber);	
			return numb.number;
		}

		string modulus()
		{
                        NUMSTRUCT numb = mod(firstnumber, secondnumber);
                        return numb.number;
                }


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
               	int compare(NUMSTRUCT a, NUMSTRUCT b)
                {
			if ( a.sign != b.sign )
			{
				if ( a.sign == "-" )
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}

                        if ( a.number.size() > b.number.size() )
                        {
                                return 1;
                        }
                        else if ( a.number.size() < b.number.size() )
                        {
                                return -1;
                        }
                        else
                        {
                                // both strings are of equal length

				for ( int i = 0; i <= a.number.size(); i ++ )
				{
					if ( a.number[i] > b.number[i] )
					{
						return 1;
					}
					else if ( a.number[i] < b.number[i] ) 
					{
						return -1;
					}
				}
                        }
                }

		/*
		** Power of 10 raise to m
		** Disclaimer this function only works for 10^x , number other than of 10 won't work
		*/
		NUMSTRUCT powr(int m)
		{
			NUMSTRUCT result;
			if ( m == 0 )
			{
				// anything raise to 0 is 1
				result.number = "1";
				return result;
			}

			// append m 0's to 1
			result.number = "1";
			for ( int i = 0; i < m ; i++ )
			{
				result.number.append("0");
			}

			return result;
		}
			
		/*
		** Multiplies two numbers , the second number should be 1000... ( 1 followed by any number of zeros ) 
		*/
		NUMSTRUCT powmul(NUMSTRUCT number1, NUMSTRUCT number2)
		{
			if ( number2.number == "1" )
			{
				return number1;
			}

			for ( int i = 0 ; i < number2.number.size() - 2; i++)
			{
				number1.number.append("0");
			}
			return number1;
		}

		/*
                ** Substracting two large numnbers in string format
                */
                NUMSTRUCT add(NUMSTRUCT number1, NUMSTRUCT number2)
                {
                        NUMSTRUCT result;
			
			while( number1.number.length() < number2.number.length() )
                        {
                                number1.number.insert(0,"0");
                        }

                        while( number2.number.length() < number1.number.length() )
                        {
                                number2.number.insert(0,"0");
                        }

                        int carry = 0;
                        for ( int i = number1.number.size() - 1; i >=0 ; i-- )
                        {
                                int num1 = (int) number1.number.at(i) - '0';
                                int num2 = (int)( number2.number.at(i) - '0' ) + carry;

                            	string cary_res =  to_string(num1 + num2);
                              	result.number.insert(0,cary_res.substr(cary_res.size() - 1 , cary_res.size()));
				cary_res = cary_res.substr(0,cary_res.size() - 1);
				carry = atoi(cary_res.c_str()) ;
                        }
	
			return result;
		}

		/*
		** Substracting two large numnbers in string format
		*/
		NUMSTRUCT sub(NUMSTRUCT number1, NUMSTRUCT number2)
		{
			NUMSTRUCT result;
			while( number1.number.length() < number2.number.length() )
			{
				number1.number.insert(0,"0");
			}

			while( number2.number.length() < number1.number.length() )
                        {
                                number2.number.insert(0,"0");
                        }

			if ( compare(number1,number2) == -1)
			{
				NUMSTRUCT temp;
				temp = number1;
				number1 = number2;
				number2 = temp;
				result.sign = "-";
			}

			int carry = 0;
			for ( int i = number1.number.size() - 1; i >=0 ; i-- )
			{
				int num1 = (int) ( number1.number.at(i) - '0' );
				int num2 = (int) (number2.number.at(i) - '0' ) + carry;
				if ( num1 == num2 )
				{
					result.number.insert(0,"0");	
					carry = 0;
				}
				else if ( num1 > num2 )
				{
					result.number.insert(0,to_string(num1 - num2));
					carry = 0;
				}
				else if ( num1 < num2 )
				{
					string cary_res =  to_string((num1 + 10) - num2);
					result.number.insert(0,cary_res.substr(cary_res.size() - 1 , cary_res.size()));
					cary_res = cary_res.substr(0,cary_res.size() - 1);
					carry = atoi(cary_res.c_str()) ;
					carry = carry + 1;
				}
			}
			// remove leading zeros
			result.number.erase(0, min(result.number.find_first_not_of('0'), result.number.size()-1));
			return result;
		}

		/*
		** Divsion of two large numbers in string
		*/
		NUMSTRUCT div(NUMSTRUCT number1, NUMSTRUCT divisor)
		{
			NUMSTRUCT quotient ;
			// if in case both number and divisor are equal
                        if ( number1.number == divisor.number )
                        {
				quotient.number = "1";
                                return quotient;
                        }

			// if divisor is 1 , return the number itsef
			if ( divisor.number == "1" )
			{
				return number1;
			}

                        // if divisor > number
                        if ( divisor.number.size() > number1.number.size() )
                        {
				quotient.number = "0";
                                return quotient;
                        }

			quotient.number = "0";
			while ( compare(number1 , divisor) == 1 )
			{
				number1 = sub(number1, divisor);
				int quo = atoi(quotient.number.c_str());
				quo = quo + 1;
				quotient.number = to_string(quo);
			}

			return quotient;
		}


		/*
		** Modulus of two large int strings
		*/
		NUMSTRUCT mod(NUMSTRUCT a, NUMSTRUCT b)
		{
			NUMSTRUCT result, temp;
			result.number = a.number;
			temp.number = "0";
			
			while(compare(sub(result,b),temp) != 0 )
			{
				result = sub(result,b);
			}
			return result;	
		}		

		/*
		** Recursively calculate product of two large numbers
		*/
		NUMSTRUCT mul(NUMSTRUCT numb1, NUMSTRUCT numb2)	
		{
			NUMSTRUCT product;

			// No of digits in numb1 and numb2
			int a = numb1.number.size();
			int b = numb2.number.size();

			if ( numb1.number == "0" || numb2.number == "0" )
			{
				// anything multiplied by 0 is 0
				product.number = "0";
				return product;
			}

			int n = max(a,b);
			if ( n <= threshold )
			{
				product.number = to_string(atoi(numb1.number.c_str()) * atoi(numb2.number.c_str()));
				return product;
			}

			int m = floor(n/2); 	//	m = [ n/2 ]
			NUMSTRUCT x = div(numb1,powr(m));	//	x = numb1 divide 10^m
			NUMSTRUCT y = mod(numb1,powr(m));	// 	y = numb1 rem 10^m
			NUMSTRUCT w = div(numb2,powr(m));	//	w = numb2 divide 10^m
			NUMSTRUCT z = mod(numb2,powr(m));	// 	z = numb2 rem 10^m

			// ( prod(x,w) * 10^2m ) + ( prod(x,z) + prod(w,y) * 10^m) + prod(y,z)
			product = add ( mul(mul(x,w),powr(2*m)) , add( mul( add( mul(x,z) , mul(w,y) ) , powr(m)) , mul(y,z) )) ;
		}
	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1("123456","91");
	cout << m1.multiplication() << "\n";
}

