#include<iostream>
#include<algorithm>
#include<stack>

int N;
long long cnt;
std::stack<int> s;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

   
    for(int i = 0; i < N; i++){
        int tmp;
        std::cin >> tmp;


        while (!s.empty() && s.top() <= tmp) {
            s.pop();
        }
        s.push(tmp);

        cnt += s.size() - 1;

    }

    std::cout << cnt;
}