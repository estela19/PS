#include<iostream>
#include<algorithm>
#include<string.h>

int R, C;
int cnt;
int trate = 1;
int flag;
int rate[11];
int dist[11];

int main() {
    memset(dist, -1, sizeof(dist));

    std::cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char tmp;
            std::cin >> tmp;

            if (tmp == '.') {
                cnt++;
            }

            else if ('1' <= tmp && tmp <= '9') {
                dist[tmp - '0'] = cnt;
            }
        }
        cnt = 0;
    }

    for (int i = 50; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (dist[j] == i) {
                rate[j] = trate;
                flag = 1;
            }
        }

        if (flag == 1) {
            trate++;
            flag = 0;
        }
    }

    for (int i = 1; i < 10; i++) {
        std::cout << rate[i] << "\n";
    }

}