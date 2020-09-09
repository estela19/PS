#include<iostream>
#include<algorithm>
#include<deque>
#include<string>

int N;
std::string str;
std::deque<int> q;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> str;


        if (str == "push") {
            int num;
            std::cin >> num;
            q.push_back(num);
        }

        else if (str == "pop") {
            if (q.empty()) {
                std::cout << "-1\n";
            }

            else {
                std::cout << q.front() << "\n";
                q.pop_front();
            }
        }

        else if (str == "size") {
            std::cout << q.size() << "\n";
        }

        else if (str == "empty") {
            std::cout << q.empty() << "\n";
        }

        else if (str == "front") {
            if (q.empty()) {
                std::cout << "-1\n";
            }

            else {
                std::cout << q.front() << "\n";
            }
        }

        else if (str == "back") {
            if (q.empty()) {
                std::cout << "-1\n";
            }

            else {
                std::cout << q.back() << "\n";
            }
        }

    }
}