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

		MATRIX first = MATRIX(0,0);
		MATRIX second = MATRIX(0,0);
		MATRIX result_normal = MATRIX(0,0);
		MATRIX result_strassen = MATRIX(0,0);
		int size_of_n; 

		/*
		** Constructor , initialize rows and columns of all matrices
		*/
		MatrixMultiply(int arg)
		{
			first.row = arg;
			first.col = arg;	
			second.row = arg;
			second.col = arg;
			result_normal.row = arg;
			result_normal.col = arg;
			result_strassen.row = arg;
			result_strassen.col = arg;
			size_of_n = arg;
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
			for (int i = 0; i < first.row; i++ ) 	
			{
				for ( int j = 0; j < second.col; j++ )
				{
					first.matrix[i][j] = generate_random_no();
					second.matrix[i][j] = generate_random_no();
				}
			}
			//initialize_matrix(&second);
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
                ** Function to perform normal multiplication
                */
                void perform_normal_multiplication()
                {
                        // initialize all elements of result matrix to 0
			initialize_matrix(&result_normal);


                        // Multiply both matrices
                        for (int i = 0; i < first.row; i++ )
                        {
                                for ( int j = 0; j < second.row; j++ )
                                {
                                        for ( int k = 0; k < first.row; k ++ )
                                        {
                                                result_normal.matrix[i][j] = result_normal.matrix[i][j] + first.matrix[i][k] * second.matrix[k][j] ;
                                        }
                                }
                        }
                        display_matrix(result_normal);
                }


		/*
                ** Perform strassens multiplication
                */
                void perform_strassens_multiplication()
                {
			MATRIX resultant = MATRIX(size_of_n,size_of_n);
			
                        resultant = stras_rec(first, second,  size_of_n);
			display_matrix(resultant);
                }

                /*
                ** Function to perform strassens multiplication, recursively
                */
                MATRIX stras_rec(MATRIX matrix1 , MATRIX matrix2 ,int n)
                {
			MATRIX result = MATRIX(matrix1.row, matrix1.row);
			if ( n == 1 )
			{
				result.matrix[0][0] = matrix1.matrix[0][0] * matrix2.matrix[0][0];
				return result;
			}

                        // break the matrix into parts
			MATRIX a11 = MATRIX(n/2,n/2);
			MATRIX a12 = MATRIX(n/2,n/2);
			MATRIX a21 = MATRIX(n/2,n/2);
			MATRIX a22 = MATRIX(n/2,n/2);

			MATRIX b11 = MATRIX(n/2,n/2);
                        MATRIX b12 = MATRIX(n/2,n/2);
                        MATRIX b21 = MATRIX(n/2,n/2);
                        MATRIX b22 = MATRIX(n/2,n/2);

			// divide first matrix into 4 parts , a11,a22,a12,a21
			divide_matrix(first, &a11, 0 , n/2, 0, n/2);
			divide_matrix(first, &a12, 0 , n/2, n/2, n);
                        divide_matrix(first, &a21, n/2 , n, 0, n/2);
                        divide_matrix(first, &a22, n/2 , n, n/2, n);

                        // divide second matrix into 4 parts , b11,b22,b12,b21
                        divide_matrix(second, &b11, 0 , n/2, 0, n/2);
                        divide_matrix(second, &b12, 0 , n/2, n/2, n);
                        divide_matrix(second, &b21, n/2 , n, 0, n/2);
                        divide_matrix(second, &b22, n/2 , n, n/2, n);

			/*
                        Computing all these
                        m1 = (a11 + a22)(b11+b22)
                        m2 = (a21 + a22) b11
                        m3 = a11 (b12 – b22)
                        m4 = a22 (b21 – b11)
                        m5 = (a11 + a12) b22
                        m6 = (a21 – a11) (b11+b12)
                        m7 = (a12 – a22)(b21 + b22)
                        */

			MATRIX m1 = MATRIX(n/2,n/2) , m2 = MATRIX(n/2,n/2), m3 = MATRIX(n/2,n/2), m4 = MATRIX(n/2,n/2) , m5 = MATRIX(n/2,n/2), m6 = MATRIX(n/2,n/2), m7 = MATRIX(n/2,n/2); 
			m1 = stras_rec(add_matrices(a11,a22),add_matrices(b11,b22), n/2);	// m1 = (a11 + a22)(b11+b22)
			m2 = stras_rec(add_matrices(a21,a22),b11, n/2);		// m2 = (a21 + a22) b11
			m3 = stras_rec(a11,sub_matrices(b12,b22), n/2);		// m3 = a11 (b12 – b22)
			m4 = stras_rec(a22,sub_matrices(b21,b11), n/2);		// m4 = a22 (b21 – b11)
			m5 = stras_rec(add_matrices(a11,a12),b22, n/2);		//  m5 = (a11 + a12) b22
			m6 = stras_rec(sub_matrices(a21,a11),add_matrices(b11,b12), n/2);	// m6 = (a21 – a11) (b11+b12)
			m7 = stras_rec(sub_matrices(a12,a22),add_matrices(b21,b22), n/2);	// m7 = (a12 – a22)(b21 + b22)

			MATRIX c11 = MATRIX(n/2,n/2), c12 = MATRIX(n/2,n/2) , c21 = MATRIX(n/2,n/2) , c22 = MATRIX(n/2,n/2);

			c11 = add_matrices(sub_matrices(add_matrices(m1, m4), m5), m7);
			c12 = add_matrices(m3, m5);
			c21 = add_matrices(m2, m4);
			c22 = add_matrices(sub_matrices(add_matrices(m1, m3), m2), m6);
				
			//display_matrix(C22);
			
			copy_matrix(&result , c11, 0, n/2 , 0, n/2);
			copy_matrix(&result , c12, 0, n/2, n/2, n);
			copy_matrix(&result , c21, n/2, n, 0, n/2);
			copy_matrix(&result , c22, n/2, n, n/2, n);

			return result;
                }
		
		/*
                ** to copy parts of matrix to resultant
                */
                void copy_matrix(MATRIX *main , MATRIX small_part, int row_start, int row_end, int col_start, int col_end )
                {
                        int smalli = 0;
                        int smallj = 0;
                        for ( int i = row_start ; i < row_end ; i++  )
                        {
                                for ( int j = col_start; j < col_end; j++ )
                                {
					main->matrix[i][j] = small_part.matrix[smalli][smallj];
                                        smallj = smallj + 1;
                                }
                                smalli = smalli + 1;
                                smallj = 0;
                        }
                }

	

                /*
                ** to divide the main matrix into parts
                */
                void divide_matrix(MATRIX main , MATRIX *divident, int row_start, int row_end, int col_start, int col_end ) 
                {
                        int smalli = 0;
                        int smallj = 0;
                        for ( int i = row_start ; i < row_end ; i++  )
                        {
                                for ( int j = col_start; j < col_end; j++ )
                                {
                                        divident->matrix[smalli][smallj] = main.matrix[i][j];
                                        smallj = smallj + 1;
                                }
                                smalli = smalli + 1;
                                smallj = 0;
                        }
                }
		
		/*
                ** Adding two matrices
                */
                MATRIX add_matrices(MATRIX mat1 , MATRIX mat2)
                {
			MATRIX result_mat = MATRIX(mat1.row , mat1.row);
                        for ( int i = 0; i < mat1.row; i++ )
                        {
                                for ( int j = 0 ; j < mat2.col; j++ )
                                {
                                        result_mat.matrix[i][j] =  mat1.matrix[i][j] + mat2.matrix[i][j];
                                }
                        }
                        return result_mat;
                }

		/*
                ** Substracting two matrices
                */
                MATRIX sub_matrices(MATRIX mat1 , MATRIX mat2)
                {
                        MATRIX result_mat = MATRIX(mat1.row , mat1.row);
                        for ( int i = 0; i < mat1.row; i++ )
                        {
                                for ( int j = 0 ; j < mat2.col; j++ )
                                {
                                        result_mat.matrix[i][j] =  mat1.matrix[i][j] - mat2.matrix[i][j];
                                }
                        }
                        return result_mat;
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
	m1.perform_normal_multiplication();
	m1.perform_strassens_multiplication();
}

