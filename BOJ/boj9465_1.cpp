#include<iostream>
#include<algorithm>
#include<string.h>

int T, n;
int dp[100001][2];
int sticker[100001][2];

int main() {
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> n;

        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < n; j++) {
                std::cin >> sticker[j][k];
            }
        }
        
        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[0][1];
        dp[1][0] = sticker[1][0] + dp[0][1];
        dp[1][1] = sticker[1][1] + dp[0][0];

        for (int j = 2; j < n; j++) {
            int maxtmp = std::max(dp[j - 2][0], dp[j - 2][1]);

            if (dp[j - 1][1] > maxtmp) {
                dp[j][0] = dp[j - 1][1] + sticker[j][0];
            }
            else {
                dp[j][0] = maxtmp + sticker[j][0];
            }

            if (dp[j - 1][0] > maxtmp) {
                dp[j][1] = dp[j - 1][0] + sticker[j][1];
            }
            else {
                dp[j][1] = maxtmp + sticker[j][1];
            }
        }

        /*
        for (int k = 0; k < 2; k++) {
            for (int l = 0; l < n; l++) {
                std::cout << dp[l][k] << " ";
            }
            std::cout << "\n";
        }
      */

        if (dp[n - 1][0] > dp[n - 1][1]) {
            std::cout << dp[n - 1][0] << "\n";
        }
        else {
            std::cout << dp[n - 1][1] << "\n";
        }

        memset(sticker, 0, sizeof(sticker));
        memset(dp, 0, sizeof(dp));
    }
}