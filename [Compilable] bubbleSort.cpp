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

long long int staticcount = 0;
void swapElement(long long int *a,long long int *b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSortCore(long long int arr[],long long int length)
{
	/*
	
	Implementation:
	- Find smallest
	- Put it up the sorted array
	- Recurse
	
	*/
	
	for (unsigned long long int i = 0 ; i <= length - 1 ; i++)
	{
		if (arr[i] < arr[i + 1]) swapElement(&arr[i],&arr[i + 1]);
	};
	
	staticcount++;
	if (staticcount > length - 1) return;
	bubbleSortCore(arr,length - 1);
}

void bubbleSort(long long int arr[],long long int firstpos,long long int lastpos)
{
	if (firstpos == lastpos) return;
	long long int arrlength = lastpos - firstpos;
	long long int array[arrlength];		// now copy array
	for (unsigned long long int i = 0 ; i <= arrlength ; i++)
	{
		array[i] = arr[firstpos + i];
	}
	bubbleSortCore(array,arrlength);
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
