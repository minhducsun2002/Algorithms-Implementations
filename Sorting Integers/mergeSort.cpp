#include <iostream>
#include <cstdio>

void mergeArr(long long int *arr, long long int firstPos,long long int mid,long long int lastPos)
{
    long long int mirr[lastPos - firstPos + 1];
    long long int first1 = firstPos,last1 = mid,first2 = mid + 1,last2 = lastPos;
    long long int currPos = 0;
    while (first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] < arr[first2])
        {
            mirr[currPos] = arr[first1++];
            currPos++;
        }
        else
        {
            mirr[currPos] = arr[first2++];
            currPos++;
        }
    };
    while (first1 <= last1 || first2 <= last2)
    {
        if (first1 <= last1 && first2 > last2)
        {
            mirr[currPos] = arr[first1++];
            currPos++;
        };
        if (first1 > last1 && first2 <= last2)
        {
            mirr[currPos] = arr[first2++];
            currPos++;
        }
    };
    for (unsigned long long int i = firstPos ; i <= lastPos ; i++)
        arr[i] = mirr[i - firstPos];
}

void mergeSort(long long int *arr,long long int firstPos,long long int lastPos)
{
    if (lastPos > firstPos)
    {

        long long int mid = (lastPos + firstPos) >> 1;
        mergeSort(arr,firstPos,mid);
        mergeSort(arr,mid + 1,lastPos);
        mergeArr(arr,firstPos,mid,lastPos);
    }
}

int main()
{
    long long int n; std::cout << "Enter array length: "; fflush(stdin); std::cin >> n;
    long long int arr[n - 1];
    for (long long int i = 0 ; i <= n - 1 ; i++)
    {
        std::cout << "Enter element number " << i + 1 << " : "; fflush(stdin); std::cin >> arr[i];
    };
    mergeSort(arr,0,n - 1);
    for (long long int i = 0 ; i <= n - 1 ; i++)
    {
        std::cout << arr[i] << ' ';
    };
}
