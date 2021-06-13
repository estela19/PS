#include<iostream>
#include<algorithm>

int N, Y, M;


int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        Y += (tmp / 30 + 1) * 10;
        M += (tmp / 60 + 1) * 15;
    }

    if (M > Y) std::cout << "Y " << Y << "\n";
    else if (Y > M) std::cout << "M " << M << "\n";
    else std::cout << "Y M " << M << "\n";
}
