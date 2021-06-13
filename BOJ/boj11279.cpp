#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

int N;
std::priority_queue<int> pq;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;

        if (tmp == 0) {
            if (pq.empty()) {
                std::cout << "0\n";
            }

            else {
                std::cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(tmp);
        }
    }
}