#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string.h>

int N, M, T;
int visit[101][101];
int map[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int gram_x, gram_y;

int sol;

int BFS(){
    std::queue<std::pair<int, int>> q;
    
    visit[0][0] = 0;
    q.push(std::make_pair(0, 0));
    while(!q.empty()){
        std::pair<int, int> now = q.front();

        for(int i = 0; i < 4; i++){
            int x = now.second + dx[i];
            int y = now.first + dy[i];

            if(0 <= x && x < M && 0 <= y && y < N && map[y][x] != 1){
                if(visit[y][x] == -1 || visit[y][x] == 100000){
                    visit[y][x] = visit[now.first][now.second] + 1;
                    q.push(std::make_pair(y, x));
                }
            }
        }
        q.pop();
    }

    return 0;
}

int main(){
    std::cin >> N >> M >> T;

    memset(visit, -1, sizeof(visit));
    visit[N - 1][M - 1] = 100000;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> map[i][j];

            if(map[i][j] == 2){
                gram_y = i;
                gram_x = j;
            }
        }
    }

    BFS();

    int gram_dist = 100000;
    if(visit[gram_y][gram_x] != -1){
        gram_dist = (N - 1) - gram_y + (M - 1) - gram_x;
        gram_dist += visit[gram_y][gram_x];
    }

    sol = std::min(gram_dist, visit[N - 1][M - 1]);

    if( sol <= T){
        std::cout << sol;
    }
    else{
        std::cout << "Fail";
    }

}