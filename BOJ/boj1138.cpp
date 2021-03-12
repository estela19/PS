#include<iostream>
#include<algorithm>

int N;
int a[11];
int b[11];
int blank;

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (a[i] == blank && b[j] == 0) {
                b[j] = i;
                break;
            }

            if (b[j] == 0) {
                blank++;
            }
        }
        blank = 0;
    }

    for (int i = 1; i <= N; i++) {
        std::cout << b[i] << " ";
    }
}