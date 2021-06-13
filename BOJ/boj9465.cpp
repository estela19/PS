#include<iostream>
#include<algorithm>
#include<string.h>

int T, n, tmp, tidx;
int sticker[100001][2];
int dp[100001];
int idx[100001];

int main() {
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> n;
        for (int k = 0; k < 2; k++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> sticker[j][k];
            }
        }

        if (sticker[1][0] < sticker[1][1]) {
            dp[1] = sticker[1][1];
            idx[1] = 1;
        }
        else {
            dp[1] = sticker[1][0];
            idx[1] = 0;
        }
        
        for (int j = 1; j < n; j++) {
            if (sticker[j + 1][0] < sticker[j + 1][1]) {
                tmp = sticker[j + 1][1];
                tidx = 1;
            }
            else {
                tmp = sticker[j + 1][0];
                tidx = 0;
            }

            if (idx[j] == 1) {
                if (dp[j] + sticker[j + 1][0] < dp[j - 1] + tmp) {
                    dp[j + 1] = dp[j - 1] + tmp;
                    idx[j + 1] = tidx;
                }
                else {
                    dp[j + 1] = dp[j] + sticker[j + 1][0];
                    idx[j + 1] = 0;
                }
            }
            else if (idx[j] == 0) {
                if (dp[j] + sticker[j + 1][1] < dp[j - 1] + tmp) {
                    dp[j + 1] = dp[j - 1] + tmp;
                    idx[j + 1] = tidx;
                }
                else {
                    dp[j + 1] = dp[j] + sticker[j + 1][1];
                    idx[j + 1] = 1;
                }
            }
        }
/*
        for (int l = 0; l <= n; l++) {
            std::cout << dp[l] << " ";
        }
        std::cout << "\n";
        for (int l = 0; l <= n; l++) {
            std::cout << idx[l] << " ";
        }
        std::cout << "\n";
*/
        std::cout << dp[n] << "\n";

        memset(dp, 0, sizeof(dp));
        memset(idx, 0, sizeof(idx));
        memset(sticker, 0, sizeof(sticker));

    }
}