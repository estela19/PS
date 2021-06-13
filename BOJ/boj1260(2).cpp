#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void dfs(int start);
void bfs(int start);

int ver, edg, start, i, j, k, a, b;
int visit1[1001], visit2[1001];
vector<int> vertex[1001];
queue<int> q;

int main() {
	scanf("%d %d %d", &ver, &edg, &start);
	for (i = 0; i < edg; i++) {
		scanf("%d %d", &a, &b);
		vertex[a].push_back(b);
		vertex[b].push_back(a);
	}
	
	for (j = 1; j <= ver; j++) sort(vertex[j].begin(), vertex[j].end());

	dfs(start);
	printf("\n");
	bfs(start);
}

void dfs(int start) {
	visit1[start] = 1;
	int now = start;
	printf("%d ", now);
	int i;
	for (i = 0; i < vertex[now].size(); i++) {
		int& ret = vertex[now][i];

		if (visit1[ret] == 0) {
			visit1[ret] = 1;
			dfs(ret);
		}
	}
}

void bfs(int start) {
	visit2[start] = 1;
	int now = start;
	printf("%d ", now);

	int i;
	for (i = 0; i < vertex[now].size(); i++) {
		int& ret = vertex[now][i];
		if (visit2[ret] == 0) {
			q.push(ret);
			visit2[ret] = 1;
		}
	}
	if (q.empty() == 1) return;
	now = q.front();
	q.pop();
	bfs(now);
	
}
