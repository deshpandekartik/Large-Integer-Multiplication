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
		void generate_random_array(string choice)
		{
			int max_random_no_limit; // create random no from 0 to max_random_no_limit variable value 

			if ( N > 20 )
			{
				if ( choice != "2" )
				{
					max_random_no_limit = 10000;
				}
				else
				{
					max_random_no_limit = 999;
				}
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
			/*
			// Custom test cases
			random_input_array[0] = 12;
			random_input_array[1] = 11;
			random_input_array[2] = 13;
			random_input_array[3] = 5;
			random_input_array[4] = 6;
			random_input_array[5] = 7;
			*/
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

			// call function to display max heap
                      	std::string comment = "Max heap ";
                    	
			if ( gui_status == true )
                     	{
                          	print_gui_input_array(random_input_array, comment,N);
                     	}


			int itteration = 1;
			for ( int i = n - 1; i >= 0; i-- )
			{
				swap_in_array(0,i);
				max_heapify(0,i);

				// after each itteration call gui function to display
                             	comment = "Itteration " + std::to_string(itteration);

                                if ( gui_status == true )
                                {
                                        print_gui_input_array(random_input_array, comment,N);
                                }
				itteration ++;
			}
		}



		/*
		** Radix sort
		*/
		void radixsort()
		{
			/*
			Custom test cases
			random_input_array[0] = 311;
                        random_input_array[1] = 1;
                        random_input_array[2] = 133;
                        random_input_array[3] = 50;
                        random_input_array[4] = 60;
                        random_input_array[5] = 7;
			*/

			// find max no in array
			int maximum = random_input_array[0];
			for ( int i = 1 ; i < N ; i ++ )
			{
				if (random_input_array[i] > maximum )
				{
					maximum = random_input_array[i];
				}
			}
		
			int my_bucket[10][10], C[10] ;	
			int digit_length = 0;

			// Get length of a maximum number
			while( maximum > 0 )
			{
				digit_length ++ ;
				maximum = maximum / 10;
			}	

			int getmsd = 1;
			for( int pass = 0; pass < digit_length; pass++)
			{
				int C[10];	// 10 because 0 to 9 digits only
				// used to maintain count of each digit at a bit position
				for( int i = 0; i < 10; i++)
				{
					C[i] = 0;
				}

				// Maintain count of all numnbers based on a bit int in semibucket array	
				for( int i = 0; i < N; i++)
				{
					int offset = ( random_input_array[i] / getmsd ) % 10;
					my_bucket[offset][C[offset]] = random_input_array[i];
					C[offset]++;
				}

				int index = 0;
				for(int k = 0; k < 10; k++)
				{
					for(int j = 0; j < C[k]; j++)
					{
						random_input_array[index] = my_bucket[k][j];
						index = index + 1;
					}
				}
				// for next pass
				getmsd = getmsd * 10;

				for( int i = 0; i < 10; i++)
                                {
                                        C[i] = 0;
                                }
	
				// after each pass call gui function to display
                                std::string comment = "Itteration " + std::to_string(pass + 1);

                                if ( gui_status == true )
                                {
                                        print_gui_input_array(random_input_array, comment,N);
                                }
	
			}
		}
};

/*
** Simulate a sorting algorithm based on user input
*/
void simulate_algo ( std::string choice , int N_size)
{
	SimulationAlgos S(N_size);	
	S.generate_random_array(choice);

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
