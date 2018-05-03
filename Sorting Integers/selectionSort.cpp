#include <iostream>
#include <algorithm>

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
    if (firstpos == lastpos) return;
    for (unsigned long long int i = firstpos ; i <= lastpos ; i++)
    {
        std::swap(arr[minElementPos(arr,i,lastpos)],arr[i]);
    };
}

int main()
{
    std::cout << "Enter array length: " << std::endl;
    long long int a; std::cin >> a;
    long long int arr[a - 1];
    for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
    {
        std::cout << "Enter the " << i + 1 << " element: " ;
        std::cin >> arr[i];
    };
    selectionSort(arr,0,a - 1);
    for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
    {
        std::cout << arr[i] << ' ';
    }
}
