//wrong answer
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

int dfs(int a, int b);

int main() {
    cnt[0][0] = 1;
    visit[0][0] = 1;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> map[i];
    }

    dfs(0, 0);

    std::cout << cnt[N - 1][M - 1];

}

int bfs(int a, b) {

}

int dfs(int a, int b) {
    if (a == M - 1 && b == N - 1) {
//        cnt++;
        return 0;
    }
    
    for (int i = 0; i < 4; i++) {
        int x = a + difx[i];
        int y = b + dify[i];

        if (0 <= y && y < N && 0 <= x && x < M && map[y][x] != '0') {
            if (!visit[y][x]) {
                visit[y][x] = 1;
//                cnt++;
                cnt[y][x] = cnt[b][a] + 1;
                if (!dfs(x, y)) {
                    return 0;
                }
            }
        }
    }

    return -1;


}