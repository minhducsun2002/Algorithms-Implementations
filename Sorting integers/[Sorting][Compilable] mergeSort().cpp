/*

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

void mergeArr(long long int *arr,long long int firstPos,long long int mid,long long int lastPos)
{
	cout << "\n[Starting arrayMerger]" << endl;
	long long int mirr[lastPos - firstPos + 1];
	long long int first1 = firstPos,last1 = mid,first2 = mid + 1,last2 = lastPos;
	long long int currPos = 0;
	while (first1 <= last1 && first2 <= last2)
	{
		if (arr[first1] < arr[first2])
		{
			mirr[currPos] = arr[first1]; printf("\n[Pushing element at position %lld of array 1 with value %lld to index %lld of result]",first1,arr[first1],currPos);
			currPos++; first1++;
		}
		else
		{
			mirr[currPos] = arr[first2]; printf("\n[Pushing element at position %lld of array 2 with value %lld to index %lld of result]",first2,arr[first2],currPos);
			currPos++; first2++;
		}
	};
	while (first1 <= last1 || first2 <= last2)
	{
		if (first1 <= last1 && first2 > last2)
		{
			mirr[currPos] = arr[first1]; printf("\n[Pushing element at position %lld of array 1 with value %lld to index %lld of result]",first1,arr[first1],currPos);
			currPos++; first1++;
		};
		if (first1 > last1 && first2 <= last2)
		{
			mirr[currPos] = arr[first2]; printf("\n[Pushing element at position %lld of array 2 with value %lld to index %lld of result]",first2,arr[first2],currPos);
			currPos++; first2++;
		}
	};
	for (unsigned long long int i = firstPos ; i <= lastPos ; i++)
	{
		arr[i] = mirr[i - firstPos];
	}
}

void mergeSort(long long int *arr,long long int firstPos,long long int lastPos)
{
	if (lastPos > firstPos)
	{
		cout << "\n\n[mergeSortDivider called]";
		long long int mid = (lastPos + firstPos) / 2; printf("[The middle value was %lld]",mid);
		mergeSort(arr,firstPos,mid);
		mergeSort(arr,mid + 1,lastPos);
		mergeArr(arr,firstPos,mid,lastPos);
	}
}

int main()
{
	unsigned long long int n; cout << "Enter array length: "; fflush(stdin); cin >> n;
	long long int arr[n- 1];
	for (unsigned long long int i = 0 ; i <= n - 1 ; i++)
	{
		cout << "Enter element number " << i + 1 << " : "; fflush(stdin); cin >> arr[i];
	};
	mergeSort(arr,0,n - 1);
	for (unsigned long long int i = 0 ; i <= n - 1 ; i++)
	{
		cout << arr[i] << ' ';
	};
} 
*/


//Debugging purposes



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

void mergeArr(long long int *arr,long long int firstPos,long long int mid,long long int lastPos)
{
	long long int mirr[lastPos - firstPos + 1];
	long long int first1 = firstPos,last1 = mid,first2 = mid + 1,last2 = lastPos;
	long long int currPos = 0;
	while (first1 <= last1 && first2 <= last2)
	{
		if (arr[first1] < arr[first2])
		{
			mirr[currPos] = arr[first1]; 
			currPos++; first1++;
		}
		else
		{
			mirr[currPos] = arr[first2]; 
			currPos++; first2++;
		}
	};
	while (first1 <= last1 || first2 <= last2)
	{
		if (first1 <= last1 && first2 > last2)
		{
			mirr[currPos] = arr[first1]; 
			currPos++; first1++;
		};
		if (first1 > last1 && first2 <= last2)
		{
			mirr[currPos] = arr[first2]; 
			currPos++; first2++;
		}
	};
	for (unsigned long long int i = firstPos ; i <= lastPos ; i++)
	{
		arr[i] = mirr[i - firstPos];
	}
}

void mergeSort(long long int *arr,long long int firstPos,long long int lastPos)
{
	if (lastPos > firstPos)
	{
		
		long long int mid = (lastPos + firstPos) / 2;
		mergeSort(arr,firstPos,mid);
		mergeSort(arr,mid + 1,lastPos);
		mergeArr(arr,firstPos,mid,lastPos);
	}
}

int main()
{
	unsigned long long int n; cout << "Enter array length: "; fflush(stdin); cin >> n;
	long long int arr[n- 1];
	for (unsigned long long int i = 0 ; i <= n - 1 ; i++)
	{
		cout << "Enter element number " << i + 1 << " : "; fflush(stdin); cin >> arr[i];
	};
	mergeSort(arr,0,n - 1);
	for (unsigned long long int i = 0 ; i <= n - 1 ; i++)
	{
		cout << arr[i] << ' ';
	};
} 
