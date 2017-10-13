//HSGS 2017-2020 - 10A1[A0] - #16
#include <iostream> 
#include <ios>      
#include <regex>    
#include <array>    
#include <string>   
#include <cstdio>  
#include <algorithm>
#include <iterator> 
#include <cmath>    
#include <iomanip>  
#include <cstring>  
#include <string>   
#include <cstdlib>  

using namespace std;

// =====================================================
// Copiable code

void swapElement(long long int *a,long long int *b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

// this part to swap ^ 
// elements			 |

void bubbleSortCore(long long int arr[],long long int firstpos,long long int lastpos)
{
	if (firstpos == lastpos) return;
	for (unsigned long long int i = firstpos ; i <= lastpos - 1 ; i++)
	{
		if (arr[i] >= arr[i + 1])
		{
			swapElement(&arr[i],&arr[i + 1]);
		};
	};
	
	// for each position
	// if disordered, swap the elements
}

void bubbleSort(long long int arr[],long long int firstpos,long long int lastpos)
{
	for (unsigned long long int i = 0 ; i <= staticlength ; i++)
	{
		bubbleSortCore(arr,firstpos,lastpos);
	};
	
	// repeat n times - with n as the length of the array of input values
}

// ==============================================
// Copiable code



int main()
{
	cout << "Enter array length: " << endl;
	long long int a; cin >> a;
	long long int arr[a - 1];
	for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
	{
		cout << "Enter the " << i + 1 << " element: " ;
		cin >> arr[i];
	};
	bubbleSort(arr,0,a - 1);
	for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
	{
		cout << arr[i] << ' ';
	}
}
