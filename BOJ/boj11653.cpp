#include<iostream>
#include<algorithm>

int M, N;
int num[10000001];

int main() {
    std::cin >> M;

    N = M;

    for (int i = 2; i <= N; i++) {
        while (N % i == 0) {
            if (N == 1)
                break;

            num[i]++;
            N /= i;
        }
    }

    for (int i = 2; i <= M; i++) {
        while (num[i] != 0) {
            num[i]--;
            std::cout << i << "\n";
        }
    }
}