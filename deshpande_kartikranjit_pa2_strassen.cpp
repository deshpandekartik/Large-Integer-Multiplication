#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class MatrixMultiply
{
	public:
		struct MATRIX {
			int matrix[111][111];
			int row = 4;
			int col = 4;
		};

		MATRIX first, second, result_normal, result_strassen;
		
		/*
		** Returns a randomly generated number
		*/
		int generate_random_no()
		{
			int max_random_no_limit = 100 ; // create random no from 0 to max_random_no_limit variable value 
			
			int random = rand() % max_random_no_limit;
			return random;
		}


		/*
		** Populates two matrices with randomly generated numbers
		*/
		void input_matrix()
		{
			// first matrix
			for (int i = 0; i < first.row; i++ ) 	
			{
				for ( int j = 0; j < second.col; j++ )
				{
					first.matrix[i][j] = generate_random_no();
					second.matrix[i][j] = generate_random_no();
				}
			}
			display_matrix(second);
		}

                /*
                ** Display a matrix
                */
                void display_matrix(MATRIX arg_matrix)
                {
                        for (int i = 0; i < arg_matrix.row; i++ )
                        {
                                for ( int j = 0; j < arg_matrix.col; j++ )
                                {
                                        cout << arg_matrix.matrix[i][j] << " ";
                                }
                                cout << "\n";
                        }
                        cout << "\n";
                }

};

int validate_input_data_n(int n)
{
	if ( n < 1 || n > 1000 )
	{
		// invalid value , n should be between 1 and 1000
		cout << "Invalid value for n, please enter a valid value \n";
		return -1;
	}
	else
	{
		// valid value for N
		return 0;
	}
}

int main(int argc, char * argv[])
{
	std::string userinput;
	int input_data_n ;
	MatrixMultiply m1; 
	m1.input_matrix();	
}

