#include<iostream>
#include<algorithm>

int N, M, K;
int Nc, C, R;

int main() {
    std::cin >> N >> M >> K;

    C = std::min(N / 2, M);

    R = N + M - K;

    std::cout << std::min(R / 3, C);
}