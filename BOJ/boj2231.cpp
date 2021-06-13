#include<iostream>
#include<algorithm>

int N;
int sol;

int main() {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        int j = i;
        tmp += j;
        
        while (j) {
            tmp += j % 10;
            j /= 10;
        }

        if (tmp == N) {
            sol = i;
            break;
        }
    }

    std::cout << sol;
}