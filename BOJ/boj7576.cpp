#include<iostream>
#include<queue>
#include<utility>

int M, N;
int tmtcnt, cnt;
int tmt[1001][1001];

std::queue<std::pair<int, int>> q;

std::pair<int, int> Dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

/*
bool IsAllRipe() {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            if (tmt[i][j] == 1) {
                cnt++;
            }
        }
    }

    return tmtcnt == cnt;
}
*/

bool IsAllRipe() {
    return tmtcnt == cnt;
}

int BFS() {
    int day = 0;

    if (q.empty()) {
        return -1;
    }

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;

            for (int j = 0; j < 4; j++) {
                int nextx = x + Dir[j].first;
                int nexty = y + Dir[j].second;

                if (0 <= nextx && nextx < M && 0 <= nexty && nexty < N) {
                    if (tmt[nextx][nexty] == 0) {
                        tmt[nextx][nexty] = 1;
                        cnt++;

                        q.push(std::make_pair(nextx, nexty));
                    }
                }
            }
            q.pop();
        }

        if (IsAllRipe() && q.size() == 0) {
            return day;
        }

        else if (!IsAllRipe() && q.size() == 0) {
            return -1;
        }

        day++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> M >> N;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < M; i++) {
            std::cin >> tmt[i][j];

            if (tmt[i][j] == 1) {
                q.push(std::make_pair(i, j));
                cnt++;
            }

            if (tmt[i][j] != -1) {
                tmtcnt++;
            }
        }
    }

    std::cout << BFS();
}