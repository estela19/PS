#include<iostream>
#include<algorithm>


int board[6][6];
int count[13];
int bingo;
int lz1, lz2, lz3, lz4;
int sol;

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> board[i][j];
        }
    }

    while (bingo < 3) {
        int tmp;
        std::cin >> tmp;
        sol++;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == tmp) {
                    board[i][j] = 0;
                }
            }
        }

        //row, col bingo
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == 0) lz1++;
                if (board[j][i] == 0) lz2++;
            }

            if (lz1 == 5 && count[i] != 1) {
                bingo++;
                count[i] = 1;
            }
            if (lz2 == 5 && count[i + 5] != 1) {
                bingo++;
                count[i + 5] = 1;
            }
            lz1 = 0;
            lz2 = 0;
        }

        //cross bingo
        for (int i = 0; i < 5; i++) {
            if (board[i][i] == 0) lz3++;
            if (board[i][4 - i] == 0) lz4++;
        }

        if (lz3 == 5 && count[10] != 1) {
            bingo++;
            count[10] = 1;
        }
        if (lz4 == 5 && count[11] != 1) {
            bingo++;
            count[11] = 1;
        }
        lz3 = 0;
        lz4 = 0;
    }

    std::cout << sol;
}
