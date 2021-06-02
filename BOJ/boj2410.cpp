#include<iostream>
#include<algorithm>

int N;
int dp[1000001];

int myeok(int a);

int main() {
	std::cin >> N;

	dp[1] = 1;
}

int myeok(int a) {
	if (dp[a] != 0) {
		return dp[a];
	}
	else {
