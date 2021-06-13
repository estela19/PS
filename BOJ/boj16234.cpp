#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<math.h>

int N, L, R;
int map[51][51];
int uni[51][51];
int visit[51][51];

int people[51];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int unicnt;
int sol;

int bfs(int x_, int y_) {
    std::queue<std::pair<int, int>> q;

    int sum = map[x_][y_];
    int cnt = 1;

    if (!visit[x_][y_]) {
        unicnt++;
        visit[x_][y_] = 1;
        uni[x_][y_] = unicnt;
        q.push(std::make_pair(x_, y_));

        while (!q.empty()) {
            std::pair<int, int> now = q.front();

            int prevp = map[now.first][now.second];

            for (int i = 0; i < 4; i++) {
                int x = now.first + dx[i];
                int y = now.second + dy[i];
                int nowp = map[x][y];

                int diff = abs(nowp - prevp);

                if (0 <= x && x < N && 0 <= y && y < N) {
                    if (!visit[x][y]) {
                        if (L <= diff && diff <= R) {
                            visit[x][y] = 1;
                            uni[x][y] = unicnt;
                            sum += map[x][y];
                            cnt++;
                            q.push(std::make_pair(x, y));
                        }
                    }
                }
            }
            q.pop();
        }
        people[unicnt] = sum / cnt;
    }


    return cnt;
}

int main() {
    std::cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    while (true) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bfs(i, j);
            }
        }

        if (unicnt == N * N) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = people[uni[i][j]];
            }
        }

        memset(visit, 0, sizeof(visit));
        memset(uni, 0, sizeof(uni));
        unicnt = 0;
        sol++;
    }

    std::cout << sol;

}