#include<iostream>
#include<algorithm>

int student[2][7];
int N, K;
int sum;

int main() {
    int s, g;

    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        std::cin >> s >> g;

        student[s][g]++;
    }

    for (int i = 1; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            if(student[j][i] != 0) sum += (student[j][i] - 1) / K + 1;
        }
    }

    std::cout << sum;

    return 0;
}