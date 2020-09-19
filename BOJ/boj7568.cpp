#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

int N;
std::vector<std::pair<int, std::pair<int, int>>> v;

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int w, h;
        std::cin >> w >> h;
        v.push_back(std::make_pair(1, std::make_pair(w, h)));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            auto& now = v[i].second;
            auto& tmp = v[j].second;
			
            if (now.first < tmp.first && now.second < tmp.second) {
                v[i].first += 1;
            }
        }
    }

    for (auto& i : v) {
        std::cout << i.first << " ";
    }
}