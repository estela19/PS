#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<string.h>

int N, K;
int visit[200001];

int main() {
    std::cin >> N >> K;

    memset(visit, -1, sizeof(visit));
    visit[N] = 0;

    std::queue<int> q;

    q.push(N);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == K) break;

        if (now * 2 <= 100000 && visit[now * 2] == -1) {
            visit[now * 2] = visit[now];
            q.push(now * 2);
        }

        if (now + 1 <= 100000 && visit[now + 1] == -1) {
            visit[now + 1] = visit[now] + 1;
            q.push(now + 1);
        }

        if (now - 1 >= 0 && visit[now - 1] == -1) {
            visit[now - 1] = visit[now] + 1;
            q.push(now - 1);
        }

        //q.pop();

    }

    std::cout << visit[K];
    
}