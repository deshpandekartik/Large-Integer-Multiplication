#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class LargeIntMul
{
	public:
		string number1 = "12345" , number2 = "123123";
	      
		string prod(string numb1, string numb2)	
		{
			// No of digits in numb1 and numb2
			int n = numb1.size();
			int m = numb2.size();

			if ( n == 0 || m == 0 )
			{
				// anything multiplied by 0 is 0
				return "0";
			}	

			return numb1;
		}
	
};


int main(int argc, char * argv[])
{
       	LargeIntMul m1;
	m1.prod("1231","12123123");
}

