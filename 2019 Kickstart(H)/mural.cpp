#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int T;
int N;
int sol[101];
int s_str[101];
int* str;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		if (N > 100) {
			str = new int[N];
			for (int k = 0; k < N; k++) {
				scanf("%1c", &str[k]);
			}
		}

		else {
			str = s_str;
			scanf("%s", s_str);
		}

		int tmp = 0;
		int term = (N + 1) / 2;

		for (int l = 0; l < term; l++) {
			sol[i] += str[l] - 48;
		}

		for (int j = 0; j < N - term; j++) {
			tmp = sol[i] - str[j] + str[j + term];
			sol[i] = std::max(tmp, sol[i]);
		}
		printf("Case #%d: %d", i + 1, sol[i]);
		delete[] str;
	}
}