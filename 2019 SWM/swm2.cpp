#include<iostream>
#include<string.h>

int T;
int N, M;
int arr[55][55];
bool flag = true;

int main()
{
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                std::cin >> arr[j][k];
            }
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M - 2; k++)
            {
                int tmp = arr[j][k] + arr[j][k + 1] + arr[j][k + 2];
                if (tmp == 1)
                {
                    flag = false;
                    break;
                }
            }
        }

        for (int j = 0; j < N; j++)
        {
            if (arr[j][0] == 1 && arr[j][1] == 0) flag = false;
            else if (arr[j][M - 1] == 1 && arr[j][M - 2] == 0) flag = false;
            else if (arr[0][j] == 1 && arr[1][j] == 0) flag = false;
            else if (arr[N - 1][j] == 1 && arr[N - 2][j] == 0) flag = false;
        }

        if (flag == false) std::cout << "NO\n";
        else std::cout << "YES\n";
        memset(arr, 0, sizeof(arr));
    }
}