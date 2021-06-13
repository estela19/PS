#include<iostream>
#include<algorithm>
#include<vector>

std::vector<int>v;
int N;
int num;

int main() {

    std::cin >> N;

    while (N--) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cin >> num;

    std::cout << std::count(v.begin(), v.end(), num);
}