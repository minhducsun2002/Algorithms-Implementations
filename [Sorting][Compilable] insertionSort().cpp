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

void insertionSort(long long int arr[],long long int firstpos,long long int lastpos)
{
	
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
	insertionSort(arr,0,a - 1);
	for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
	{
		cout << arr[i] << ' ';
	}
}
