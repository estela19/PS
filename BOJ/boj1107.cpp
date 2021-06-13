#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

int channel;
int c[7];
int len;
int N;
int num;
int directcnt;
int cnt;
int sol;
int* Min;
int* Max;
std::set<int> s;

int StrToInt(int* str)

int main()
{
//    std::string test = "123";
    scanf("%d", &channel);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        s.insert(tmp);
    }

    // 모든 버튼이 고장났을 경우
    if (s.size() == 10)
    {
        sol = std::abs(channel - 100);
    }

    else
    {
        while (channel)
        {
            c[len++] = channel % 10;
            channel /= 10;
        }

        // 채널 누르는 버튼 수보다 + - 누르는게 빠를 경우
        directcnt = std::abs(channel - 100);
        if (len >= directcnt)
        {
            sol = directcnt;
        }

        //max
        Max = new int[len];
        for (int i = len - 1; i >= 0; i--)
        {
            num = c[i];
            while (s.find(num) != s.end())
            {
                num++;
            }

            Max[len - 1 - i] = num;
        }

        //min
        Min = new int[len];
        for (int i = len - 1; i >= 0; i--)
        {
            num = c[i];
            while (s.find(num) != s.end())
            {
                num--;
            }

            Min[len - 1 - i] = num;
        }
        int minnum = StrToInt(Min);
        int maxnum = StrToInt(Max);
        cnt = std::min(std::abs(minnum - channel) + Min.length(), std::abs(maxnum - channel) + Max.length());
    }
    printf("%d", cnt);
}

int StrToInt(int* str)
{
    int num = 0;
    for (int i = 1; i <= len; i++)
    {
        num += (str[i] * (len - i));
    }
    return num;
}