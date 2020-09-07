#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

int check(int x, int y);
void dfs(int x, int y);

int can_x, can_y, x, t, cnt, max_x, max_y, min_x, min_y;
int coord[101][101];
int visit[101][101];
int s[100];
const int dx[4] = { 1, 0, 0, -1 };
const int dy[4] = { 0, 1, -1, 0 };

int main() {
	scanf("%d %d %d", &can_y, &can_x, &t);
	int k;
	for (k = 0; k < t; k++) {
		scanf("%d %d %d %d", &min_x, &min_y, &max_x, &max_y);

		int i, j;
		for (j = min_y; j < max_y; j++) {
			for (i = min_x; i < max_x; i++) {
				coord[i][j] = 1;
			}
		}
	}
	
	int i, j;
	for (i = 0; i < can_x; i++) {
		for (j = 0; j < can_y; j++) {
			if (visit[i][j] == 0 && coord[i][j] == 0) {
				cnt++;
				dfs(i, j);
			}
		}
	} 
	sort(s + 1, s + cnt + 1);
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; i++) {
		printf("%d ", s[i] + 1);
	}

	
}

void dfs(int x, int y) {
	int l;
	visit[x][y] = 1;
	for (l = 0; l < 4; l++) {
		if (check(x + dx[l], y + dy[l])) {
			s[cnt]++;
			dfs(x + dx[l], y + dy[l]);
		}
	}
}

int check(int x, int y) {
	if (x < 0 || x >= can_x || y < 0 || y >= can_y || coord[x][y] == 1 || visit[x][y] == 1) {
		return 0;
	}
	else return 1;
}

