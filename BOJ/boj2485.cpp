#include<iostream>
#include<algorithm>

int N;
int start;
int first, second;
int diff, divisor;

int gcd(int a, int b);

int main() {
    std::cin >> N;
    std::cin >> second;

    start = second;
    for (int i = 1; i < N; i++) {
        first = second;
        std::cin >> second;

        diff = second - first;

        if (divisor == 0) {
            divisor = diff;
        }

        divisor = gcd(divisor, diff);
    }

    std::cout << (second - start) / divisor - N + 1;
}

int gcd(int a, int b) {
    if (b > a) {
        int c = b;
        b = a;
        a = c;
    }

    if (b == 0) return a - b;
    else return gcd(a % b, b);
}