#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class MatrixMultiply
{
	public:
		int first_matrix[111][111], second_matrix[111][111], result_matrix_normal[111][111], result_matrix_strassen[111][111];
		const int MAX_ARR_SIZE = 111;
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
			for (int i = 0; i < 4; i++ ) 	
			{
				for ( int j = 0; j < 4; j++ )
				{
					first_matrix[i][j] = generate_random_no();
				}
			}

			// Second matrix
                        for (int i = 0; i < 4; i++ )
                        {
                                for ( int j = 0; j < 4; j++ )
                                {
                                        second_matrix[i][j] = generate_random_no();
                                }
                        }
			//display_matrix();
		}

		/*
		** Display a matrix
		*/	
		void display_matrix(int arg_matrix[111][111])
		{
			for (int i = 0; i < 4; i++ )
                        {
                                for ( int j = 0; j < 4; j++ )
                                {
                              		cout << arg_matrix[i][j] << " ";
                                }
				cout << "\n";
                	}
			cout << "\n";
		}

		/*
		** Function to perform normal multiplication
		*/
		void perform_normal_multiplication()
		{
			// initialize all elements of result matrix to 0 
			for (int i = 0; i < 4; i++ )
                        {
                                for ( int j = 0; j < 4; j++ )
                                {
                                        result_matrix_normal[i][j] = 0 ;
                                }
                        }

			// Multiply both matrices
			for (int i = 0; i < 4; i++ )
                        {
                                for ( int j = 0; j < 4; j++ )
                                {
					for ( int k = 0; k < 4; k ++ )
					{
                                        	result_matrix_normal[i][j] = result_matrix_normal[i][j] + first_matrix[i][j] * second_matrix[i][j] ;
					}
                                }
                        }
			display_matrix(first_matrix);
			display_matrix(second_matrix);
			display_matrix(result_matrix_normal);
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
	m1.perform_normal_multiplication();
}

