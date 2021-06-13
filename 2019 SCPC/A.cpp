#include<iostream>
#include<algorithm>

int T;
int* sol = new int[100001];
int ans;

int main() {
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		std::cout << "Case #" << i << ":";
		int N;
	//	sol = new int[100001];
		std::cin >> N;
		
		int* ct = new int[N + 1];
		for (int j = 0; j < N; ++j) {
			std::cin >> ct[j];

			for (int k = 1; k <= ct[j]; ++k) {
				sol[k] += 1;
				if (sol[k] >= k) {
					ans = k;
				}

			}
			std::cout << " " << ans;

		}

	}
}