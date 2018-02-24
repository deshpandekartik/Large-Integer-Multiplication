#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class MatrixMultiply
{
	public:
		int first_matrix[111][111], second_matrix[111][111], result_matrix_normal[111][111], result_matrix_strassen[111][111];
		static const int MAX_ARR_SIZE = 111;
		int size_of_n = 4;

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
			for (int i = 0; i < size_of_n; i++ ) 	
			{
				for ( int j = 0; j < size_of_n; j++ )
				{
					first_matrix[i][j] = generate_random_no();
					result_matrix_strassen[i][j] = 0;
				}
			}

			// Second matrix
                        for (int i = 0; i < size_of_n; i++ )
                        {
                                for ( int j = 0; j < size_of_n; j++ )
                                {
                                        second_matrix[i][j] = generate_random_no();
                                }
                        }
			//display_matrix();
		}

		/*
		** Display a matrix
		*/	
		void display_matrix(int arg_matrix[MAX_ARR_SIZE][MAX_ARR_SIZE])
		{
			for (int i = 0; i < size_of_n; i++ )
                        {
                                for ( int j = 0; j < size_of_n; j++ )
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
			for (int i = 0; i < size_of_n; i++ )
                        {
                                for ( int j = 0; j < size_of_n; j++ )
                                {
                                        result_matrix_normal[i][j] = 0 ;
                                }
                        }

			// Multiply both matrices
			for (int i = 0; i < size_of_n; i++ )
                        {
                                for ( int j = 0; j < size_of_n; j++ )
                                {
					for ( int k = 0; k < size_of_n; k ++ )
					{
                                        	result_matrix_normal[i][j] = result_matrix_normal[i][j] + first_matrix[i][j] * second_matrix[i][j] ;
					}
                                }
                        }
			display_matrix(result_matrix_normal);
		}
	
		/*	
		** Perform strassens multiplication
		*/
		void perform_strassens_multiplication()
		{
			// initialize resultant matrix 
			initialize_matrix(result_matrix_strassen, size_of_n);

			stras_rec(first_matrix, second_matrix, result_matrix_strassen, size_of_n);
		}

		/*
		** Function to perform strassens multiplication, recursively
		*/
		void stras_rec(int matrix1[MAX_ARR_SIZE][MAX_ARR_SIZE] , int matrix2[MAX_ARR_SIZE][MAX_ARR_SIZE] , int resultmatrix[MAX_ARR_SIZE][MAX_ARR_SIZE] ,int n)
		{
			// break the matrix into parts
			int a11[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int a12[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int a21[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int a22[MAX_ARR_SIZE][MAX_ARR_SIZE];

			int b11[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int b12[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int b21[MAX_ARR_SIZE][MAX_ARR_SIZE];
			int b22[MAX_ARR_SIZE][MAX_ARR_SIZE];	


			// initialize all the matrices
			initialize_matrix(a11,n/2);
			initialize_matrix(a12,n/2);
			initialize_matrix(a21,n/2);
			initialize_matrix(a22,n/2);

			initialize_matrix(b11,n/2);
			initialize_matrix(b12,n/2);
			initialize_matrix(b21,n/2);
			initialize_matrix(b22,n/2);
		}

		/*
		** Initializes all elements in a matrix to 0
		*/
		void initialize_matrix(int matrix[MAX_ARR_SIZE][MAX_ARR_SIZE] , int n)
		{
			for (int i = 0; i < n; i++ )
                        {
                                for ( int j = 0; j < n; j++ )
                                {
                              		matrix[i][j] = 0;
                                }
                        }
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
	m1.perform_strassens_multiplication();
}

