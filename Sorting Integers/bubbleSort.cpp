#include <iostream>
#include <algorithm>

void bubbleSort(long long int arr[], long long int firstpos, long long int lastpos)
{
    for (long long int i = firstpos ; i <= lastpos ; i++)
    {
        for (long long int n = i ; n <= lastpos ; n++)
        {
            if (arr[n] > arr[n + 1]) std::swap(arr[n], arr[n + 1]);
        }
    }
}


int main()
{
    std::cout << "Enter array length: ";
    long long int a; std::cin >> a;
    long long int arr[a - 1];
    for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
    {
        std::cout << "Enter the " << i + 1 << " element: " ;
        std::cin >> arr[i];
    };
    bubbleSort(arr,0,a - 1);
    for (unsigned long long int i = 0 ; i <= a - 1 ; i++)
    {
        std::cout << arr[i] << ' ';
    }
    //usage: bubbleSort(array, first_position, last_position)
}
