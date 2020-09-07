#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

int T, N, P;
long long sol;
std::string tmp;
std::vector<std::string> v;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> T;

	for (int i = 1; i <= T; i++) {
		std::cin >> N >> P;
		sol = pow(2, N);
		std::cin >> tmp;
		v.push_back(tmp);
		for (int j = 1; j < P; j++) {
			std::cin >> tmp;
			for (int l = 0; l < j; l++) {
				if (v[l].find(tmp) == 0) {
					v[l] = tmp;
				}
				else if (tmp.find(v[l]) == 0) {
					break;
				}
				else {
					v.push_back(tmp);
				}
			}
		}

		int len = v.size();
		for (int j = 0; j < len; j++) {
			sol -= pow(2, N - v[j].size());
		}
		std::cout << "Case #" << i << ": " << sol << "\n";
		v.clear();
	}
}

/*
R과 B두개의 버튼 중 하나를 N번 누름
그중 P개의 누르면 안되는 패턴이 있음.
그 패턴을 "처음에" 누르면 안됨 (RB가 안되는 거일때 RRB는 가능)
총 누를 수 있는 가짓수?
*/