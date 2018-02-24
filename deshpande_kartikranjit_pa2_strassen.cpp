#include <iostream>
#include <string>
#include <ctime>
using namespace std;



class MatrixMultiply
{
	public:

		struct MATRIX {
                        int matrix[111][111];
                        int row ;
                        int col ;

                        MATRIX(int rowu, int colu) : row(rowu), col(colu) { }
                };

		MATRIX *first = new MATRIX(0,0);
		MATRIX *second = new MATRIX(0,0);
		MATRIX *result_normal = new MATRIX(0,0);
		MATRIX *result_strassen = new MATRIX(0,0);

		/*
		** Constructor , initialize rows and columns of all matrices
		*/
		MatrixMultiply(int arg)
		{
			first->row = arg;
			first->col = arg;	
			second->row = arg;
			second->col = arg;
			result_normal->row = arg;
			result_normal->col = arg;
			result_strassen->row = arg;
			result_strassen->col = arg;
		}
	
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
			for (int i = 0; i < first->row; i++ ) 	
			{
				for ( int j = 0; j < second->col; j++ )
				{
					first->matrix[i][j] = generate_random_no();
					second->matrix[i][j] = generate_random_no();
				}
			}
			initialize_matrix(second);
			display_matrix(second);
		}

                /*
                ** Display a matrix
                */
                void display_matrix(MATRIX *arg_matrix)
                {
                        for (int i = 0; i < arg_matrix->row; i++ )
                        {
                                for ( int j = 0; j < arg_matrix->col; j++ )
                                {
                                        cout << arg_matrix->matrix[i][j] << " ";
                                }
                                cout << "\n";
                        }
                        cout << "\n";
                }

                /*
                ** Initializes all elements in a matrix to 0
                */
                void initialize_matrix(MATRIX *arg_matrix)
                {
                        for (int i = 0; i < arg_matrix->row; i++ )
                        {
                                for ( int j = 0; j < arg_matrix->col; j++ )
                                {
                                        arg_matrix->matrix[i][j] = 0;
                                }
                        }
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
                void stras_rec(MATRIX matrix1 , MATRIX matrix2 , MATRIX resultmatrix ,int n)
                {
                        // break the matrix into parts
			MATRIX a11 = MATRIX(n/2,n/2);
			MATRIX a12 = MATRIX(n/2,n/2);
			MATRIX a21 = MATRIX(n/2,n/2);
			MATRIX a22 = MATRIX(n/2,n/2);

			MATRIX b11 = MATRIX(n/2,n/2);
                        MATRIX b12 = MATRIX(n/2,n/2);
                        MATRIX b21 = MATRIX(n/2,n/2);
                        MATRIX b22 = MATRIX(n/2,n/2);

			cout << a11.row;

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
	MatrixMultiply m1(4); 
	m1.input_matrix();	
}

