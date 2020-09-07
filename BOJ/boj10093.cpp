#include<iostream>
#include<algorithm>

long long A, B, M, m;

int main() {
    std::cin >> M >> m;

    B = std::max(M, m);
    A = std::min(M, m);
    if (A == B) std::cout << "0\n";
    else std::cout << B - A - 1 << "\n";

    for (long long i = A + 1; i < B; i++) {
        std::cout << i << " ";
    }
}