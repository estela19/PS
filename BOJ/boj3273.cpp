#include<iostream>
#include<algorithm>

#define max 2000000

int n, x;
int num[max + 1];
int cnt;

int main() {
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        num[tmp]++;
    }

    std::cin >> x;

    for (int i = 1; i < x/2; i++) {
        if (num[i] == 1 && num[x - i] == 1) {
            cnt++;
        }
    }

    std::cout << cnt;
}