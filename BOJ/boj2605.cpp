#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

int N;
std::list<int> line;

int main() {
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		int tmp;
		std::cin >> tmp;

		std::list<int>::iterator iter = line.end();

		while (tmp--) {
			iter--;
		}

		line.insert(iter, i);
	}

	for (auto& i : line) {
		std::cout << i << " ";
	}
}