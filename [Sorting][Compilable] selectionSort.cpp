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
long long int min, pos;
void swapElement(long long int *a,long long int *b)
{
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

long long int minElementPos(long long int arr[],long long int firstpos,long long int lastpos)
{
	long long int min = 10000000000; long long int pos;
	for (long long int i = firstpos ; i <= lastpos ; i++)
	{
		if (min >= arr[i]) 
		{
			pos = i;
			min = arr[i];
			
		};
	};
	return pos;
}

void selectionSort(long long int arr[], long long int firstpos,long long int lastpos)
{
	/*
	
	Implementation:
	- Get the minimum element. Swap with first element.
	- Move the "first" pointer incrementally each step.
	- Repeat. 
	
	*/
	if (firstpos == lastpos) return;
	for (unsigned long long int i = firstpos ; i <= lastpos ; i++)
	{
		swapElement(&arr[minElementPos(arr,i,lastpos)],&arr[i]);
	};
}

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
	selectionSort(arr,0,a - 1);
	for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
	{
		cout << arr[i] << ' ';
	}
}
