#include<iostream>
#include<algorithm>
#include<vector>

int N;
std::vector<int> v;
int sol;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());

    for (auto& i : v) {
        int res = i * N--;
//        std::cout << res << "\n";
        sol = std::max(sol, res);
    }

    std::cout << sol;
}