#include<iostream>
#include<algorithm>
#include<deque>

int A, B;
std::deque<int> d;

int main() {
    for (int i = 0; i < 21; i++) {
        d.push_back(i);
    }

    for (int i = 0; i < 10; i++) {
        std::cin >> A >> B;

        std::reverse(d.begin() + A, d.begin() + B + 1);
    }

    d.pop_front();

    for (auto& i : d) std::cout << i << " ";
 }