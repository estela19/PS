#include<iostream>
#include<algorithm>

int N;
int inp[20][3];
int dp[20];

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> inp[i][0] >> inp[i][1];
    }

    for (int i = N; i > 0; i--) {
        if (i + inp[i][0] <= N + 1) {
            dp[i] = std::max(inp[i][1] + dp[i + inp[i][0]], dp[i + 1]);
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    std::cout << dp[1];
}