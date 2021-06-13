#include<iostream>
#include<algorithm>
#include<vector>

int N, K;
int cnt, sum;
int money[11];

int main() {
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        std::cin >> money[i];
    }

    for (int i = N; i > 0; i--) {
        while (sum + money[i] <= K) {
            sum += money[i];
            cnt++;
        }
    }

    std::cout << cnt;
}