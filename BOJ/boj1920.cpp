#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int find(int, int, int);

int n, m;
int a[100000];
int b[100000];

int main() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	sort(a, a + n );

	for (i = 0; i < m; i++) {
		int& now = b[i];
		int result = find(now, 0, n - 1);
		printf("%d\n", result);
	}
}

int find(int num, int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) return 0;
	else {
		if (num > a[mid]) find(num, mid + 1, right);
		else if (num < a[mid]) find(num, left, mid - 1);
		else return 1;
	}
}
