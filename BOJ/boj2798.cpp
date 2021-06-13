#include<iostream>
#include<algorithm>

int N, M;
int card[101];
int sol;

int main() {
    std::cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        std::cin >> card[i];
    }

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                int tmp = card[i] + card[j] + card[k];

                if (tmp <= M && sol < tmp) {
                    sol = tmp;
                }
            }
        }
    }

    std::cout << sol;
}