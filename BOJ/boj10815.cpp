#include<stdio.h>
#include<algorithm>
using namespace std;

int find(int, int, int);

int n, m;
int ans[500001];
int num;

int main() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &ans[i]);
	}
	sort(ans, ans + n);

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &num);
		int result = find(num, 0, n - 1);
		printf("%d ", result);
	}
}

int find(int num, int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) return 0;
	else {
		if (num > ans[mid]) find(num, mid + 1, right);
		else if (num < ans[mid]) find(num, left, mid - 1);
		else return 1;
	}
}
