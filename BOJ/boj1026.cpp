#include<iostream>
#include<algorithm>

int N;
int a[51], b[51];
int sol;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    std::sort(a, a + N);
    std::sort(b, b + N);

    for (int i = 0; i < N; i++) {
        sol += a[i] * b[N - i - 1];
    }

    std::cout << sol;
}