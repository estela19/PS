#include<iostream>
#include<queue>
#include<vector>

int vertex, edge;
int cnt;
std::vector<std::vector<int>> v;
std::queue<int> q;
int visit[101];

int main() {
    std::cin >> vertex;
    std::cin >> edge;

    for (int i = 0; i <= vertex; i++) {
        v.push_back(std::vector<int>());
    }

    for (int i = 0; i < edge; i++) {
        int a, b;
        std::cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    q.push(1);
    visit[1] = 1;

    while (!q.empty()) {
        int size = q.size();
        int now = q.front();

        for (auto& i : v[now]) {
            if (visit[i] == 0) {
                cnt++;
                visit[i] = 1;
                q.push(i);
            }
        }

        q.pop();
    }

    std::cout << cnt;
}