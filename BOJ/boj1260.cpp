#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

void dfs(int now);
void bfs(int now);

int n, m, v, i, k;
int a, b;
vector<int>edge[10001];
queue<int>q;
int visit_dfs[10001];
int visit_bfs[10001];

int main() {
	scanf("%d %d %d", &n, &m, &v);
	
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 0; i <= n; i++) {
		sort(edge[i].begin(),edge[i].end());
	}
	dfs(v);
	printf("\n");
	bfs(v);

}

void dfs(int now) {
	visit_dfs[now] = 1;
	printf("%d ", now);
	for (int j = 0; j < edge[now].size(); j++) {
		if (!visit_dfs[edge[now][j]]) {
			dfs(edge[now][j]);
		}
	}
}

void bfs(int now) {
	q.push(now);
	visit_bfs[now] = 1;
	while (!q.empty()) {
		now = q.front();
		printf("%d ", now);
		q.pop();
		for (i = 0; i < edge[now].size(); i++) {
			if (!visit_bfs[edge[now][i]]) {
				q.push(edge[now][i]);
				visit_bfs[edge[now][i]] = 1;
			}
		}
	}

}
