#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

int N, M;
std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> chicken;

int main() {
    std::cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int z;
            std::cin >> z;

            if (z == 1) {
                house.push_back(std::make_pair(x, y));
            }

            else if (z == 2) {
                chicken.push_back(std::make_pair(x, y));
            }
        }
    }
}