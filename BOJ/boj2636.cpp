#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#include<memory.h>

int N, M;
int prechz;
int sol = 0;
int board[101][101];
int visit[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs() {
    std::queue<std::pair<int, int>> q;
    
    visit[0][0] = 1;
    q.push(std::make_pair(0, 0));

    while (!q.empty()) {
        std::pair<int, int> now = q.front();

        for (int i = 0; i < 4; i++) {
            int x = now.first + dx[i];
            int y = now.second + dy[i];

            if (0 <= x && x < M && 0 <= y && y < N) {
                if (!visit[y][x]) {
                    visit[y][x] = 1;

                    if (board[y][x] == 0) {
                        q.push(std::make_pair(x, y));
                    }
                    else if (board[y][x] == 1) {
                        prechz++;
                        board[y][x] = 0;
                    }
                }
            }
        }
        q.pop();
    }
    return prechz;
}

int IsEmpty(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(board[i][j] == 1)
                return false;
        }
    }
    return true;
}

int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }

    while (true) {
        bfs();

        if(IsEmpty()) break;

        memset(visit, 0, sizeof(visit));
        prechz = 0;
        sol++;
    }

    if (prechz == 0) std::cout << sol << "\n";
    else std::cout << sol + 1 << "\n";

    std::cout << prechz;
}