#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <math.h>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> MATRIX;

class MatrixMultiply
{
        public:

		MATRIX first;
                MATRIX second ;
                MATRIX result_normal ;
                MATRIX result_strassen ;
		int size_of_n;

                /*
                ** Constructor , initialize rows and columns of all matrices
                */
		MatrixMultiply(MATRIX a1, MATRIX a2, MATRIX normal, MATRIX strassens, int arg)
                {
			first = a1;
			second = a2;
			result_normal = normal;
			result_strassen = strassens;
                        size_of_n = arg;
		}

		/*
                ** Returns a randomly generated number
                */
                int generate_random_no()
                {
                        int max_random_no_limit = sqrt(INT_MAX / first.size() ) ; // create random no from 0 to max_random_no_limit variable value

                        int random = rand() % 100;
                        return random;
                }


                /*
                ** Populates two matrices with randomly generated numbers
                */
                void input_matrix()
                {
                        // first matrix
                        for (int i = 0; i < first.size(); i++ )
                        {
                                for ( int j = 0; j < first.size(); j++ )
                                {
                                        first[i][j] = generate_random_no();
                                        second[i][j] = generate_random_no();
                                }
                        }
                        //initialize_matrix(&second);
                        display_matrix(first,"Randomly generated Matrix 1 ");
                        display_matrix(second,"Randomly generated Matrix 2 ");
                }

                /*
                ** Display a matrix
                */
                void display_matrix(MATRIX arg_matrix, string comment)
                {
                        cout << comment << endl;
                        for (int i = 0; i < arg_matrix.size(); i++ )
                        {
                                for ( int j = 0; j < arg_matrix.size(); j++ )
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
                        // Multiply both matrices
                        for (int i = 0; i < first.size(); i++ )
                        {
                                for ( int j = 0; j < second.size(); j++ )
                                {
                                        for ( int k = 0; k < first.size(); k ++ )
                                        {
                                                result_normal[i][j] = result_normal[i][j] + first[i][k] * second[k][j] ;
                                        }
                                }
                        }
			display_matrix(result_normal,"Normal Matrix multiplication Result ");
		}

                /*
                ** Perform strassens multiplication
                */
                void perform_strassens_multiplication()
                {
                        result_strassen = stras_rec(first, second,  size_of_n);
                        display_matrix(result_strassen,"Strassen's Matrix multiplication Result ");
                }


                /*
                ** Function to perform strassens multiplication, recursively
                */
                MATRIX stras_rec(MATRIX matrix1 , MATRIX matrix2 ,int n)
                {

			MATRIX result(matrix1.size(), vector<int> (matrix1.size(), 0));
                        n = matrix1.size();
                        if ( n == 1 )
                        {
                                // base case
                                for ( int i = 0 ; i < n; i ++ )
                                {
                                        for ( int j = 0; j <n; j++ )
                                        {
                                                for ( int k = 0; k <n; k++)
                                                {
                                                        result[i][j] = matrix1[i][k] * matrix2[k][j];
                                                }
                                        }
                                }
                                return result;
                        }

			// break the matrix into parts
			MATRIX a11(n/2, vector<int> (n/2, 0)), a12(n/2, vector<int> (n/2, 0)), a21(n/2, vector<int> (n/2, 0)), a22(n/2, vector<int> (n/2, 0));
		
			MATRIX b11(n/2, vector<int> (n/2, 0)), b12(n/2, vector<int> (n/2, 0)), b21(n/2, vector<int> (n/2, 0)), b22(n/2, vector<int> (n/2, 0));

                        // divide first matrix into 4 parts , a11,a22,a12,a21
                        divide_matrix(matrix1, a11, 0 , n/2, 0, n/2);
                        divide_matrix(matrix1, a12, 0 , n/2, n/2, n);
                        divide_matrix(matrix1, a21, n/2 , n, 0, n/2);
                        divide_matrix(matrix1, a22, n/2 , n, n/2, n);


                        // divide second matrix into 4 parts , b11,b22,b12,b21
                        divide_matrix(matrix2, b11, 0 , n/2, 0, n/2);
                        divide_matrix(matrix2, b12, 0 , n/2, n/2, n);
                        divide_matrix(matrix2, b21, n/2 , n, 0, n/2);
                        divide_matrix(matrix2, b22, n/2 , n, n/2, n);

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

			MATRIX m1(n/2, vector<int> (n/2, 0)), m2(n/2, vector<int> (n/2, 0)), m3(n/2, vector<int> (n/2, 0)), m4(n/2, vector<int> (n/2, 0)), m5(n/2, vector<int> (n/2, 0)), m6(n/2, vector<int> (n/2, 0)), m7(n/2, vector<int> (n/2, 0));
	
                        m1 = stras_rec(add_matrices(a11,a22),add_matrices(b11,b22), n/2);       // m1 = (a11 + a22)(b11+b22)
                        m2 = stras_rec(add_matrices(a21,a22),b11, n/2);         // m2 = (a21 + a22) b11
                        m3 = stras_rec(a11,sub_matrices(b12,b22), n/2);         // m3 = a11 (b12 – b22)
                        m4 = stras_rec(a22,sub_matrices(b21,b11), n/2);         // m4 = a22 (b21 – b11)
                        m5 = stras_rec(add_matrices(a11,a12),b22, n/2);         //  m5 = (a11 + a12) b22
                        m6 = stras_rec(sub_matrices(a21,a11),add_matrices(b11,b12), n/2);       // m6 = (a21 – a11) (b11+b12)
                        m7 = stras_rec(sub_matrices(a12,a22),add_matrices(b21,b22), n/2);       // m7 = (a12 – a22)(b21 + b22)

                        //display_matrix(add_matrices(b11,b22));

			MATRIX c11(n/2, vector<int> (n/2, 0)), c12(n/2, vector<int> (n/2, 0)), c21(n/2, vector<int> (n/2, 0)), c22(n/2, vector<int> (n/2, 0));

                        c11 = add_matrices(sub_matrices(add_matrices(m1, m4), m5), m7);         // m1 + m4 - m5 + m7
                        c12 = add_matrices(m3, m5);     // m3 + m5
                        c21 = add_matrices(m2, m4);     // m2 + m4
                        c22 = add_matrices(sub_matrices(add_matrices(m1, m3), m2), m6); // m1 + m3 - m2 + m6


                        merge(result , c11, 0, n/2 , 0, n/2);
                        merge(result , c12, 0, n/2, n/2, n);
                        merge(result , c21, n/2, n, 0, n/2);
                        merge(result , c22, n/2, n, n/2, n);

                        return result;
                }

                /*
                ** to copy parts of matrix to resultant
                */
                void merge(MATRIX &main , MATRIX small_part, int row_start, int row_end, int col_start, int col_end )
                {
                        int smalli = 0;
                        int smallj = 0;
                        for ( int i = row_start ; i < row_end ; i++  )
                        {       
                                for ( int j = col_start; j < col_end; j++ )
                                {       
                                        main[i][j] = small_part[smalli][smallj];
                                        smallj = smallj + 1;
                                }
                                smalli = smalli + 1;
                                smallj = 0;
                        }
                }
                /*
                ** to divide the main matrix into parts
                */
                void divide_matrix(MATRIX main , MATRIX &divident, int row_start, int row_end, int col_start, int col_end ) 
                {
                        int smalli = 0;
                        int smallj = 0;

                        for ( int i = row_start ; i < row_end ; i++  )
                        {
                                for ( int j = col_start; j < col_end; j++ )
                                {
                                        divident[smalli][smallj] = main[i][j];
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
                        MATRIX result_mat(mat1.size(), vector<int> (mat1.size(), 0));
                        for ( int i = 0; i < mat1.size(); i++ )
                        {
                                for ( int j = 0 ; j < mat1.size(); j++ )
                                {
                                        result_mat[i][j] =  mat1[i][j] + mat2[i][j];
                                }
                        }
                        return result_mat;
                }

                /*
                ** Substracting two matrices
                */
                MATRIX sub_matrices(MATRIX mat1 , MATRIX mat2)
                {
			MATRIX result_mat(mat1.size(), vector<int> (mat1.size(), 0));
                        for ( int i = 0; i < mat1.size(); i++ )
                        {
                                for ( int j = 0 ; j < mat2.size(); j++ )
                                {
                                        result_mat[i][j] =  mat1[i][j] - mat2[i][j];
                                }
                        }
                        return result_mat;
                }
};

int validate_input_data_n(long int n)
{
        if ( n < 1 || n > 1024 )
        {
                // invalid value , n should be between 1 and 1000
                cout << "Invalid value for n, please enter a valid value, n = 2^k , k is positive\n";
                exit(0);
        }


        // Repeatedly comput power of x
        long int pow = 1;
        while (pow < n)
                pow *= 2;

        // Check if power of x becomes y
        if (pow == n)
        {
                return 0;
        }
        else
        {
                cout << "Invalid value for n, please enter a valid value, n = 2^k , k is positive\n";
                exit(0);
        }
}


int main(int argc, char * argv[])
{
        /*
        validate_input_data_n(16);
        std::string userinput;
        int input_data_n ;
        MatrixMultiply m1(4);
        m1.input_matrix();
        m1.perform_normal_multiplication();
        m1.perform_strassens_multiplication();
        */

        int n;
        if ( argc!= 2)
        {
                cout << "Please enter a value as a command line argument";
                exit(0);
        }

        istringstream input(argv[1]);
        if(!(input >> n && input.eof()))
        {
                cout<<"\nPlease enter the argument for n correctly. Enter an integer = 2 ^k.\n \n";
                exit(0);
        }
        else
        {
                n = atoi(argv[1]);
                if(n <= 0 || validate_input_data_n(n) != 0 )
                {
                        cout<<"\nPlease enter the argument for n correctly. Enter a positive integer = 2^k.\n \n";
                        exit(0);
                }
        }

	MATRIX matrix1(n, vector<int> (n, 0)), matrix2(n, vector<int> (n, 0)), strassenMResult(n, vector<int> (n, 0)), normal(n, vector<int> (n, 0));
	MatrixMultiply m1(matrix1,matrix2,normal,strassenMResult,n);
	m1.input_matrix();
	m1.perform_normal_multiplication();
	m1.perform_strassens_multiplication();
}
