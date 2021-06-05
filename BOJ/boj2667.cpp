#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<string>

int N;
int visit[30][30];
std::string map[30];
std::vector<int> apart;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int a, int b) {
    int cnt = 1;
    std::queue<std::pair<int,int>> q;

    visit[b][a] = 1;

    q.push(std::make_pair(a, b));

    while (!q.empty()) {
        std::pair<int, int> now = q.front();
        
        for (int i = 0; i < 4; i++) {
            int x = now.first + dx[i];
            int y = now.second + dy[i];

            if (0 <= x && x < N && 0 <= y && y < N && map[y][x] == '1') {
                if (!visit[y][x]) {
                    visit[y][x] = 1;
                    cnt++;
                    q.push(std::make_pair(x, y));
                }
            }
        }
        q.pop();
    }

    return cnt;
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> map[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[j][i] && map[j][i] == '1') {
                int cnt = bfs(i, j);
                apart.push_back(cnt);
            }
        }
    }

    std::sort(apart.begin(), apart.end());

    std::cout << apart.size() << "\n";
    
    for (auto& i : apart) {
        std::cout << i << "\n";
    }
}