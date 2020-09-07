#include<stdio.h>
#include<string.h>
#include<algorithm>
# define MAX 987654321

long long ps(long long left, long long right);
int n, k, a[10001], sol;
int max = 0;

int main() {
	scanf("%d %d", &k, &n);
	int i;
	for (i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		max = std::max(max, a[i]);
	}
	sol = ps(1, max);
	printf("%d", sol);
}

long long ps(long long left, long long right) {
	int cnt = 0;
	long long mid = (left + right) / 2 + 1;
	if (left != right) {
		int i;
		for (i = 0; i < k; i++)
			cnt += a[i] / mid;
		if (cnt >= n) ps(mid, right);
		else if (cnt < n) ps(left, mid - 1);
	}
	else return left;
}
