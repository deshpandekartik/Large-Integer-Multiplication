#include <iostream>
#include <string>
#include <ctime>
#include <math.h>
using namespace std;

class LargeIntMul
{
	public:
		int threshold = 5 , itteration = 0;	// lets say
	     
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
			NUMSTRUCT numb = mul_rec(firstnumber, secondnumber);
                        return numb.number;
		}

		string mod_multiplication()
                {
                        NUMSTRUCT numb = modified_mul_rec(firstnumber, secondnumber);
                        return numb.number;
                }


		string multiplication_verify()
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
                ** return -1 if second is bigger
                */
               	int compare(NUMSTRUCT a, NUMSTRUCT b)
                {
			if ( a.sign != b.sign )
			{
				if ( a.sign == "-" )
				{
					return -1;
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
				return 1;
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
		** Multipolication of two large numbers in string format
		*/
		NUMSTRUCT mul(NUMSTRUCT number1, NUMSTRUCT number2)
		{
			NUMSTRUCT product;
			if ( number1.number == "0" || number2.number == "0" )
                        {
                                // anything multiplied by 0 is 0
                                product.number = "0";
                                return product;
                        }

			if ( compare(number1,number2) == -1)
                        {
                                NUMSTRUCT temp;
                                temp = number1;
                                number1 = number2;
                                number2 = temp;
                        }


			int carry = 0;
			string result = "";
			string result_array[number2.number.size()];
			int result_array_index = 0;
			int itteration = 0;
			for ( int i = number2.number.size() - 1; i >=0 ; i-- )
			{
				for ( int j = number1.number.size() - 1; j >=0 ; j-- )
				{
					int num1 = (int) number2.number.at(i) - '0';
	                                int num2 = (int) (number1.number.at(j) - '0') ;
			
					string cary_res =  to_string((num1 * num2) + carry);
					result.insert(0,cary_res.substr(cary_res.size() - 1 , cary_res.size()));
                                	cary_res = cary_res.substr(0,cary_res.size() - 1);
                                	carry = atoi(cary_res.c_str()) ;
				}
				result.insert(0,to_string(carry));
				int count = itteration;
                                while ( count != 0 )
                                {
                                        result.append("0");
                                        count--;
                                }
                                itteration ++;

				result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
				result_array[result_array_index] = result;
				result = "";
				carry = 0;
				result_array_index ++ ;
			}

			NUMSTRUCT sum_res;
			sum_res.number = "0";
			for ( int i = 0; i <= result_array_index - 1; i++ )
			{
				NUMSTRUCT temp;
				temp.number = result_array[i];
				sum_res = add(sum_res , temp);
			}
			return sum_res;
			
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
			if ( divisor.number == "0" )
                        {
                                cout << "Undefined division" << endl;
                                exit(0);
                        }

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

			quotient.number = number1.number;
			
			long long size = divisor.number.size() - 1;

			while ( size != 0 )
			{
				quotient.number = quotient.number.substr(0, quotient.number.size()-1);
				//cout << size << " " << quotient.number << endl;
				size --;
			}

			return quotient;
		}


		/*
		** Modulus of two large int strings
		*/
		NUMSTRUCT mod(NUMSTRUCT a, NUMSTRUCT b)
		{
			if ( b.number == "0" )
			{
				cout << "Undefined mod" << endl;
				exit(0);
			}

			NUMSTRUCT result, temp;
			result.number = a.number;
			temp.number = "0";
		
			if ( compare(a,b) == -1)
                        {
                                NUMSTRUCT temp;
                                temp = a;
                                a = b;
                                b = temp;
                        }
	
			
			long long size = b.number.size() - 1;
			result.number = a.number.substr( a.number.length() - size );
			result.number.erase(0, min(result.number.find_first_not_of('0'), result.number.size()-1));

			if ( result.number.size() == 0 )
			{
				result.number = "0";
			}
			return result;	
		}		

		/*
		** Recursively calculate product of two large numbers
		*/
		NUMSTRUCT mul_rec(NUMSTRUCT numb1, NUMSTRUCT numb2)	
		{
			NUMSTRUCT product;
			numb1.number.erase(0, min(numb1.number.find_first_not_of('0'), numb1.number.size()-1));
			numb2.number.erase(0, min(numb2.number.find_first_not_of('0'), numb2.number.size()-1));

			// remove zeroes from left , if present


			// No of digits in numb1 and numb2
			int asize = numb1.number.size();
			int bsize = numb2.number.size();

			if ( numb1.number == "0" || numb2.number == "0" || numb1.number.size() == 0 || numb2.number.size() == 0)
			{
				// anything multiplied by 0 is 0
				product.number = "0";
				return product;
			}

			int n = max(asize,bsize);
			if ( asize = 1 || bsize == 1)
			{
				//product.number = to_string(atoi(numb1.number.c_str()) * atoi(numb2.number.c_str()));
				return mul(numb1,numb2);
			}
			itteration ++ ;

			while( numb1.number.length() < numb2.number.length() )
                        {
                                numb1.number.insert(0,"0");
                        }

                        while( numb2.number.length() < numb1.number.length() )
                        {
                                numb2.number.insert(0,"0");
                        }


			int m = floor(n/2); 	//	m = [ n/2 ]

			NUMSTRUCT x = moddiv(numb1,0,m);       //      x = numb1 divide 10^m
                        NUMSTRUCT y = moddiv(numb1,m,numb1.number.size());       //      y = numb1 rem 10^m
                        NUMSTRUCT w = moddiv(numb2,0,m);       //      w = numb2 divide 10^m
                        NUMSTRUCT z = moddiv(numb2,m,numb2.number.size());       //      z = numb2 rem 10^m


			NUMSTRUCT xw = mul_rec(x,w);
			NUMSTRUCT yz = mul_rec(y,z);

			NUMSTRUCT addxy = add(x,y);
			NUMSTRUCT addwz = add(w,z);

			NUMSTRUCT xywz = mul_rec(addxy,addwz);

			xw.number = string( m*2, '0').append(xw.number);
                        xywz.number = string( m, '0').append(xywz.number);

			product = add ( xw , xywz) ;
			product = add ( product, yz);
			product.number.erase(0, min(product.number.find_first_not_of('0'), product.number.size()-1));			
			return product;
		}

		/*
		** Modified version of large interger multiplication
		** Dividing no into 3 parts
		*/
		NUMSTRUCT modified_mul_rec(NUMSTRUCT numb1, NUMSTRUCT numb2)
		{
			NUMSTRUCT product;
                        numb1.number.erase(0, min(numb1.number.find_first_not_of('0'), numb1.number.size()-1));
                        numb2.number.erase(0, min(numb2.number.find_first_not_of('0'), numb2.number.size()-1));

                        // remove zeroes from left , if present


                        // No of digits in numb1 and numb2
                        int asize = numb1.number.size();
                        int bsize = numb2.number.size();

                        if ( numb1.number == "0" || numb2.number == "0" || numb1.number.size() == 0 || numb2.number.size() == 0)
                        {
                                // anything multiplied by 0 is 0
                                product.number = "0";
                                return product;
                        }

                        int n = max(asize,bsize);
                        if ( asize <= 2 || bsize <= 2 )
                        {
                                //product.number = to_string(atoi(numb1.number.c_str()) * atoi(numb2.number.c_str()));
                                return mul(numb1,numb2);
                        }
                        itteration ++ ;

                        while( numb1.number.length() < numb2.number.length() )
                        {
                                numb1.number.insert(0,"0");
                        }

                        while( numb2.number.length() < numb1.number.length() )
                        {
                                numb2.number.insert(0,"0");
                        }


                        int m = floor(n/3);     //      m = [ n/2 ]

                        NUMSTRUCT x2 = moddiv(numb1,0,m);       //      x = numb1 divide 10^m
			NUMSTRUCT x1 = moddiv(numb1,m,2*m);
                        NUMSTRUCT x0 = moddiv(numb1,(2*m),numb1.number.size());       //      y = numb1 rem 10^m

			NUMSTRUCT y2 = moddiv(numb2,0,m);       //      x = numb1 divide 10^m
                        NUMSTRUCT y1 = moddiv(numb2,m,2*m);
                        NUMSTRUCT y0 = moddiv(numb2,(2*m),numb2.number.size());       //      y = numb1 rem 10^m


			NUMSTRUCT term1 = padzeros(modified_mul_rec(x2,y2),(m*4))  ;		// (x2*y2) * 10 ^ 4m
			NUMSTRUCT term2 = padzeros(add(modified_mul_rec(x2,y1), modified_mul_rec(y2,x1)),3*m);	// ( ( x2*y1 ) + ( y2*x1 ) ) * 10 ^ 3m 
			
	
			cout << "mod rec " << modified_mul_rec(x2,y1).number << " " << numb2.number.substr(m,2*m) << "a" << endl;
			

			return numb2;
		}

		NUMSTRUCT padzeros(NUMSTRUCT numb , int count)
		{
			int counter = 0;
			while( counter != count )
			{
				numb.number = numb.number.insert(numb.number.size(), "0");
				counter++;
			}
			return numb;	
		}

		NUMSTRUCT moddiv( NUMSTRUCT num , int start , int end )
		{
			NUMSTRUCT result;
			result.number = num.number.substr(start,end);
			result.number.erase(0, min(result.number.find_first_not_of('0'), result.number.size()-1));
			return result;
		}	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1("111","111");
	//cout << m1.multiplication() << endl;

	cout << m1.mod_multiplication() << endl ;
	cout << "verify " << m1.multiplication_verify() << endl;
}

