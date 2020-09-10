#include<iostream>
#include<algorithm>

int N, M, K;
int a[101][101];
int b[101][101];
int c[101][101];

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            std::cin >> tmp;
            a[i][j] = tmp;
        }
    }

    std::cin >> M >> K;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int tmp;
            std::cin >> tmp;
            b[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int l = 0; l < M; l++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }
}