#include<iostream>
#include<algorithm>

int N;
int student, apple;
int remain;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> student >> apple;

        remain += apple % student;
    }

    std::cout << remain;
}