#include<iostream>
#include<algorithm>
#include<deque>
#include<utility>

int T;
int cnt;
bool flag = true;

int main() {
    int N, M;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> N >> M;

        std::deque<std::pair<int, bool>> q;

        for (int j = 0; j < N; j++) {
            int tmp;
            std::cin >> tmp;
            q.push_back(std::make_pair(tmp, false));
        }
        
        auto& key = q[M];
        q[M].second = true;

        int max;
        while (flag || q.empty()) {
            q.front().first;
            int max = max_element(q.begin(), q.end())->first;

            while (q.front().first != max) {
                q.push_back(q.front());
                q.pop_front();
            }
            if (q.front().second) {
                cnt++;
                std::cout << cnt << " \n";
                flag = false;
                break;
            }
            q.pop_front();
            cnt++;
            
        }

        cnt = 0;
        flag = true;
        q.clear();
    }
}