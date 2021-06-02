#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

int N;
int parent[100001];
int visit[100001];
std::vector<std::vector<int>> v;
std::queue<int> q;

int bfs(int n);

int main() {
    visit[1] = 1;

    std::cin >> N;

    for (int i = 0; i < N + 1; i++) {
        v.push_back(std::vector<int>());
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        
        std::cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    if (!bfs(1)) {
        for (int i = 2; i <= N; i++) {
            std::cout << parent[i] << "\n";
        }
    }

}

int bfs(int n) {
    q.push(n);

    while (!q.empty()) {
        int now = q.front();

        for (auto& i : v[now]) {
            if (!visit[i]) {
                visit[i] = 1;
                parent[i] = now;
                q.push(i);
            }
        }

        q.pop();
    }

    return 0;
}