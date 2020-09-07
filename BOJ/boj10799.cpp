#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int sol, stick;
char input[100001];
int i, j, k;
int len;

int main() {
	scanf("%s", input);

	len = strlen(input);
	for (i = 0; i < len; i++) {
		if (input[i] == '(') {
			stick++;
		}

		else if (input[i] == ')') {
			if (input[i - 1] == '(') {
				stick--;
				sol += stick;
			}
			else {
				stick--;
				sol++;
			}
		}
	}
	printf("%d", sol);
}
