#include<iostream>
#include<algorithm>
#define mod 1000000007
int t, n, m;
int dp[200001][5];
long long facto[200001];

void SetDp();
long long Facto(int n);
int Combin(int n, int r);
/*
int main() {
	SetDp();
	std::cin >> t;

	for (int i = 1; i <= t; i++) {
		std::cin >> n >> m;

		int sol = 1;
		int human = 2 * (n - m);
		int base_case = Facto(2 * (n - m));

		for (int j = 1; j <= 2 * m - 1; j += 2) {
			sol *= (Combin(human + j, 2) * 2) % mod;
		}

		sol = base_case * sol;

		std::cout << "Case #" << i << ": " << sol << "\n";
	}
}
*/

void SetDp() {
/*	for (int i = 0; i <= 200000; i++) {
		dp[i][0] = 1;
	}  // */
	for (int i = 0; i <= 200000; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 2; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
}

long long Facto(int n) {
	if (n == 1) return 1;
	else if (facto[n] != 0) return facto[n];
	else {
		facto[n] = (n * Facto(n - 1)) % mod;
		return facto[n];
	}
}

int Combin(int n, int r) {
	if (dp[n][r] != 0) return dp[n][r];
	else {
		dp[n][r] = (Combin(n - 1, r) + Combin(n - 1, r - 1)) % mod;
		return dp[n][r];
	}
}
/*
(n-m)!
n-m + 1 C 2
n-m + 3 C 2
*/