#include<iostream>
#include<algorithm>

int N;
int dp[31];

int func(int N);

int main() {
    dp[0] = 1;
    dp[2] = 3;

    std::cin >> N;

    std::cout << func(N);
}

int func(int N) {
    if (N % 2 == 1) return 0;
    else if (dp[N] != 0) return dp[N];
    else {
        int tmp = 0;
        for (int i = 0; i < N - 2; i += 2) {
            tmp += func(i) * 2;
        }
        dp[N] = func(N - 2) * 3 + tmp;
        return dp[N];
    }
}