//include guard
#ifndef __SORT_HPP_INCLUDED_
#define __SORT_HPP_INCLUDED_

//prototypes

void swapElement(long long int *a,long long int *b);

void selectionSort(long long int arr[], long long int firstpos,long long int lastpos);
long long int minElementPos(long long int arr[],long long int firstpos,long long int lastpos);

void mergeSort(long long int *arr,long long int firstPos,long long int lastPos);
void mergeArr(long long int *arr,long long int firstPos,long long int mid,long long int lastPos);

void bubbleSort(long long int arr[],long long int firstpos,long long int lastpos);
void bubbleSortCore(long long int arr[],long long int firstpos,long long int lastpos);


//implementations
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


void bubbleSort(long long int arr[],long long int firstpos,long long int lastpos)
{
	for (unsigned long long int i = 0 ; i <= staticlength ; i++)
	{
		bubbleSortCore(arr,firstpos,lastpos);
	};
	
	// repeat n times - with n as the length of the array of input values
}




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

