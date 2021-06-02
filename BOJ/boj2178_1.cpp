#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<utility>

int N, M;
std::string map[101];
int visit[101][101];
int cnt[101][101];

int difx[4] = { 1, -1, 0, 0 };
int dify[4] = { 0, 0, 1, -1 };

int bfs();

int main() {

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> map[i];
    }

    bfs();

    std::cout << cnt[N - 1][M - 1];

}

int bfs() {
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));
    cnt[0][0] = 1;
    visit[0][0] = 1;

    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            std::pair<int, int> now = q.front();
            int x = now.first + difx[i];
            int y = now.second + dify[i];

            if (0 <= y && y < N && 0 <= x && x < M && map[y][x] != '0') {
                if (!visit[y][x]) {
                    visit[y][x] = 1;
                    cnt[y][x] = cnt[now.second][now.first] + 1;
                    q.push(std::make_pair(x, y));
                }
            }
        }
        q.pop();
    }

    return 0;
}

