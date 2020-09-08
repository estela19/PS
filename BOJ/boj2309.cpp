#include<iostream>
#include<algorithm>
#include<numeric>

int num[10];
int sum;
int a, b;

int main() {
    for (int i = 0; i < 9; i++) {
        std::cin >> num[i];
    }

    sum = std::accumulate(num, num + 10, 0);

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - (num[i] + num[j]) == 100) {
                num[i] = 101;
                num[j] = 101;
                std::sort(num, num + 9);
                for (int k = 0; k < 7; k++) {
                    std::cout << num[k] << "\n";
                }
            }
        }
    }
}