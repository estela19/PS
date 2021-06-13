#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int N, T;
long long sol[101];
std::vector <int> v;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		v.reserve(N);
		int tmp = 0;
		int term = (N + 1) / 2;
		for (int j = 0; j < N; j++) {
			scanf("%1d", &tmp);
			v.push_back(tmp);
		}

		long long sum = 0;
		for (int l = 0; l < term; l++) {
			sum += v[l];
		}
		sol[i] = sum;

		int len = v.size();
		for (int k = 0; k < len - term; k++) {
			sum = sum - v[k] + v[k + term];
			sol[i] = std::max(sol[i], sum);
		}
		printf("Case #%d: %lld\n", i + 1, sol[i]);
		v.clear();
	}
}