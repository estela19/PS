#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>

int N, M;
int erase; 
int map[10][10];
int visit[10][10];
std::vector<std::pair<int, int>> virus;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int safezone(int a, int b) {
    if (!visit[a][b]) {

        std::queue<std::pair<int, int>> q;
        int cnt = 1;

        visit[a][b] = 1;

        q.push(std::make_pair(a, b));

        while (!q.empty()) {
            std::pair<int, int> now = q.front();

            for (int i = 0; i < 4; i++) {
                int x = now.first + dx[i];
                int y = now.second + dy[i];

                if (0 <= x && x < M && 0 <= y && y < N && map[x][y] != 1) {
                    if (!visit[x][y]) {
                        visit[x][y] = 1;
                        cnt++;
                        q.push(std::make_pair(x, y));
                    }
                }
            }
            q.pop();
        }
        return cnt;
    }
    return 0;
}


int main() {

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[j][i];

            if (map[j][i] == 1) {
                erase++;
            }

            if (map[j][i] == 2) {
                virus.push_back(std::make_pair(j, i));
            }
        }
    }
 
    int sol = 0;

    for (int x1 = 0; x1 < M; x1++) {
        for (int y1 = 0; y1 < N; y1++) {
            if (map[x1][y1] != 0) continue;

            for (int x2 = 0; x2 < M; x2++) {
                for (int y2 = 0; y2 < N; y2++) {
                    if (map[x2][y2] != 0) continue;

                    for (int x3 = 0; x3 < M; x3++) {
                        for (int y3 = 0; y3 < N; y3++) {
                            if (map[x3][y3] != 0) continue;

                            if (x1 == x2 && y1 == y2) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            if (x3 == x1 && y3 == y1) continue;

                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;

//                            if (x1 == 0 && x2 == 1 && x3 == 1 && y1 == 2 && y2 == 0 && y3 == 1)
//                                std::cout << "a\n";

                            memset(visit, 0, sizeof(visit));
                            int cnt = 0;

                            for (auto& i : virus) {
                                cnt += safezone(i.first, i.second);
                            }
                            
                            int tmp = N * M - erase - 3 - cnt;

                            if (sol < tmp) {
                                sol = tmp;

 /*
                                std::cout << "x1:" << x1 << " y1:" << y1 << "\n";
                                std::cout << "x2:" << x2 << " y2:" << y2 << "\n";
                                std::cout << "x3:" << x3 << " y3:" << y3 << "\n";

                                std::cout << "cnt: " << cnt << "\n";
                                std::cout << "sol: " << sol << "\n";
 */

                            }
                            
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    std::cout << sol;

    return 0;
}