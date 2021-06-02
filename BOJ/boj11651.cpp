#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>


std::vector<std::pair<int, int>> v;
int N;
int x, y;

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> x >> y;

        v.push_back(std::make_pair(x, y));
    }

    std::sort(v.begin(), v.end(), cmp);

    for (auto& i : v) {
        std::cout << i.first << " " << i.second << "\n";
    }

    return 0;
}