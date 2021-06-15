#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>

int N, K;
int dp[100001];

int move(int i);

int main() {
    std::cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    dp[N] = 0;

    move(K);

    std::cout << dp[K];
}

int move(int i) {
    if (dp[i] != -1) return dp[i];
    if (i > 100000 || i < 0) return ;
    else {
        dp[i] = std::min(move(i + 1), move(i - 1)) + 1;

        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], dp[i / 2]);
        }
        
        return dp[i];
    }
}