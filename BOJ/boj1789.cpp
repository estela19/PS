#include<iostream>
#include<algorithm>

long long S;

int main() {
	std::cin >> S;

	long long i = 1;
	while (i * (i + 1) <= 2 * S) {
		i++;
	}

	std::cout << i - 1;
}