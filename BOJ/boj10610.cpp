#include<iostream>
#include<algorithm>

long long N;
long long sum;
int num[10];

int main() {
	std::cin >> N;

	while (N) {
		num[N % 10]++;
		sum += N % 10;
		N /= 10;
	}

	if (num[0] == 0 || sum % 3 != 0) {
		std::cout << -1;
	}

	else {
		for (int i = 9; i >= 0; i--) {
			while (num[i] != 0) {
				std::cout << i;
				num[i]--;
			}
		}
	}
}