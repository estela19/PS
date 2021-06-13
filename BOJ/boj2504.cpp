#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

stack<int>s;
vector<int>score;
char input[30];
int len;
int cnt1, cnt2;
int sol;
int now_sol = 1;

int main() {
	scanf("%s", input);
	len = strlen(input);
	
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
			score.push_back(2);
		}

		else if (input[i] == '[') {
			s.push(input[i]);
			score.push_back(3);
		}

		else if (input[i] == ')') {
			if (s.size() == 0 || s.top() == '[') {
				sol = 0;
				break;
			}

			else if (s.top() == '(') {
				if (input[i - 1] == '(') {
					for (auto j : score) {
						now_sol *= j;
					}
					sol += now_sol;
					now_sol = 1;
				}
				score.pop_back();
				s.pop();
			}

		}

		else if (input[i] == ']') {
			if (s.size() == 0 || s.top() == '(') {
				sol = 0;
				break;
			}

			else if (s.top() == '[') {
				if (input[i - 1] == '[') {
					for (auto j : score) {
						now_sol *= j;
					}
					sol += now_sol;
					now_sol = 1;
				}
				score.pop_back();
				s.pop();
			}

		}

	}
	if (s.size() != 0) sol = 0;

	printf("%d", sol);
	return 0;
}
