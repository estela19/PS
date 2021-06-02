#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

int N, M;
int map[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int safezone() {

}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][M];
        }
    }
}