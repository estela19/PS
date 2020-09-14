#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>

int N;
std::vector<std::pair<int, std::string>> v;

bool cmp(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first < b.first;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int age;
        std::string name;

        std::cin >> age >> name;

        v.push_back(std::make_pair(age, name));

    }
    
    std::stable_sort(v.begin(), v.end(), cmp);

    for (auto& i : v) {
        std::cout << i.first << " " << i.second << "\n";
    }
}