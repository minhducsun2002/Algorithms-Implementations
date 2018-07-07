#include <iostream>

bool is_square(long long int i)
{
	if (i - 1 <= 0) return true;
	int last = i % 10; if (i == 2 || i == 3 || i == 7 || i == 8) return false;
	long long int sum = 0, step = 1;
	while (sum < i)
	{
		sum += step; step += 2;
	};
	return (sum == i);
}

//returns a boolean value representing whether the argument is a perfect square;

int main()
{
    int i; std::cin >> i; std::cout << (is_square(i) ? "Square" : "Not square") << std::endl;
}
