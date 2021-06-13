#include<iostream>
#include<stack>
#include<vector>

int N;
int a = 1;
bool isable = true;
std::stack<int> s;
std::vector<char> v;

int main() {
    std::cin >> N;

    s.push(a++);
    v.push_back('+');

    while((!s.empty() || a <= N) && isable == true) {
        int tmp;
        std::cin >> tmp;

        while (a <= tmp) {
            s.push(a++);
            v.push_back('+');
        }

        if (tmp < a) {
            if (s.top() != tmp) isable = false;
            else {
                s.pop();
                v.push_back('-');
            }
        }
    }

    if (isable == false) std::cout << "NO";
    else {
        for (auto& i : v) std::cout << i << "\n";
    }
}