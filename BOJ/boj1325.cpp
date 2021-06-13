#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string.h>

int N, M;
int sol;
int com[10001];
std::queue<int> q;
std::vector<std::vector<int>> v;

int bfs(int n);

int main() {
    std::cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        v.push_back(std::vector<int>());
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;

        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        int cnt = bfs(i);
        sol = std::max(sol, cnt);
        com[i] = cnt;
    }

    for (int i = 1; i <= N; i++) {
        if (com[i] == sol) {
            std::cout << i << " " ;
        }
    }
    return 0;
}

int bfs(int n) {
    int visit[10001];
    int cnt = 0;
    
    memset(visit, 0, sizeof(visit));
    q.push(n);

    while (!q.empty()) {
        int now = q.front();

        for (auto& i : v[now]) {
            if (!visit[i]) {
                visit[i] = 1;
                cnt++;
                q.push(i);
            }
        }

        q.pop();
    }

    return cnt;
}