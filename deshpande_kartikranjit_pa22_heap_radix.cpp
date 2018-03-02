#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class SimulationAlgos
{
	public:
		int N , random_input_array[1000], itteration_no; 
		bool gui_status ; // gui_status used to determine whether GUI (**) has to be displayed, only true when N <= 20

		/*
		** Initialize everything
		*/
		SimulationAlgos(int input_size_n)
		{
			if ( input_size_n > 20 )
			{	
				gui_status = false;
			}
			else
			{
				gui_status = true;
			}
			N = input_size_n;
			itteration_no = 0;
		}		

		/*
		** Generate an array of size N ( specified by user ), using random numbers
		*/
		void generate_random_array()
		{
			int max_random_no_limit; // create random no from 0 to max_random_no_limit variable value 

			if ( N > 20 )
			{
				max_random_no_limit = 100;
			}
			else
			{
				max_random_no_limit = 15;
			}

			srand((unsigned)time(NULL));
			for ( int i = 0; i < N; i ++ )
			{
				random_input_array[i] = 1 + rand() % max_random_no_limit;
			}

			if ( gui_status == true )
			{
				print_gui_input_array(random_input_array, "Initial array",N);
			}
			else
			{
				cout << "Initial array" << " " ;
				cout << "[ ";
                        	for ( int i = 0; i < N; i ++ )
                        	{
                        	        cout << random_input_array[i] << ",";
                        	}
	                        cout << " ] \n";
			}
		}

		/*
		** To print the input array in terms of * , some GUI
		*/
		void print_gui_input_array(int input[], std::string comments, int array_size)
		{
			if ( gui_status == true )
			{
				cout << comments << " " ;
                    		cout << "[ "; 
                     		for ( int i = 0; i < array_size; i ++ )
                     		{
                       			cout << input[i] << ",";
                  		}
				cout << " ] \n"; 


				for ( int i = 0; i < array_size; i ++ )
                        	{
					for ( int j = 0; j < input[i]; j++)
					{
						cout << "*";
					}
					cout << "\n";
				}
			}
		}

		/*
		* print the sorted array
		*/
		void print_sorted_array(int input[], std::string comments, int array_size)
		{
                     	cout << comments << " " ;
                    	cout << "[ "; 
                    	for ( int i = 0; i < array_size; i ++ )
                     	{
                      		cout << input[i] << ",";
                    	}
                    	cout << " ] \n";

			if ( gui_status == true )
                        {
                                for ( int i = 0; i < array_size; i ++ )
                                {       
                                        for ( int j = 0; j < input[i]; j++)
                                        {
                                                cout << "*";
                                        }
                                        cout << "\n";
                                }
                        }


		}

		/*
		** To swap elements in an array
		*/
		void swap_in_array(int i, int j)
		{
			int temp;
			temp = random_input_array[i];
			random_input_array[i] = random_input_array[j];
			random_input_array[j] = temp;
		}

                /*
                ** Heap sort
                */
                void heapsort()
                {
			// Custom test cases
			random_input_array[0] = 12;
			random_input_array[1] = 11;
			random_input_array[2] = 13;
			random_input_array[3] = 5;
			random_input_array[4] = 6;
			random_input_array[5] = 7;
			//max_heapify(1);
			buid_max_heap(N);
                }

		/*
		** Max Heapiy
		*/
		void max_heapify(int i, int n)
		{
			int largest = i;
			int left = 2*i + 1;
			int right = 2*i + 2;

			if ( left < n && random_input_array[left] > random_input_array[largest])
			{
				largest = left;
			}
			if ( right < n && random_input_array[right] > random_input_array[largest] )
			{
				largest = right;
			}

			if ( largest != i )
			{
				swap_in_array(i,largest);		
				max_heapify(largest,n);
			}
		}

		/*
		** Calling max heapify
		*/
		void buid_max_heap(int n)
		{
			for ( int i = n/2 - 1; i >= 0; i -- )
			{
				max_heapify(i,n);
			}

			for ( int i = n - 1; i >= 0; i-- )
			{
				swap_in_array(0,i);
				max_heapify(0,i);
				print_sorted_array(random_input_array, "IT ", N );
			}
		}

		/*
		** Radix sort
		*/
		void radixsort()
		{

		}
};

/*
** Simulate a sorting algorithm based on user input
*/
void simulate_algo ( std::string choice , int N_size)
{
	//SimulationAlgos S(N_size);	
	SimulationAlgos S(6);
	//S.generate_random_array();

        if ( choice == "1" )
        {
                // Heap Sort
		S.heapsort();
        }
        else if ( choice == "2" )
        {
                // Radix Sort
		S.radixsort();
        }
        else if ( choice == "3" )
        {
		exit(0);
        }
        else
        {
                cout << "EXCEPTION ! This shouldnt have occured, simulate_algo function failed, user entered " << choice << " as his input";
        }

	// after sorting, print the result
	S.print_sorted_array(S.random_input_array, "Sorted array", S.N );
}

/*
** Validate value of N ( input parameter, if it meets requirements
** Returns 0 for valid and -1 for invalid
*/
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

        cout << "1. Heap Sort \n" ;
	cout << "2. Radix Sort \n";
	cout << "3. Exit : To terminate  \n \n" ;

	while ( true )
	{
   		while ( std::getline(std::cin, userinput) && userinput != "" )
		{
			if ( userinput == "1" || userinput == "2" || userinput == "3" || userinput == "4" )
			{
				cout << "Enter number of input data (n) , should be between 1 and 1000 \n" ;
				do
				{
					cin >> input_data_n;
				}
				while ( validate_input_data_n(input_data_n) == -1 );
				simulate_algo(userinput,input_data_n);
			}
			else if ( userinput == "Exit" || userinput == "exit" || userinput == "5" )
			{
				cout << "Program terminated normally \n";
				exit(0);
			}
			else
			{
				cout << "Invalid command entered \n";
			}
			cout << "1. Heap Sort \n" ;
		        cout << "2. Radix Sort \n";
        		cout << "3. Exit : To terminate  \n \n"; 
		}        
	}
}
