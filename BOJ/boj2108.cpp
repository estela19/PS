#include<iostream>
#include<algorithm>
#include<numeric>
#include<set>

std::set<int> s;

int N, a[500001];
int cnt[8002];
long long sum;
int max = -1;
int bin1;
int bin2 = -5000;

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        cnt[a[i] + 4000]++;
        int& num = cnt[a[i] + 4000];
        sum += a[i];

    }
    
    std::cout << std::fixed;
    std::cout.precision(0);

    std::cout << sum / (double)N << "\n";

    std::sort(a, a + N);

    std::cout << a[N / 2] << "\n";

    for (int i = 0; i < 8002; i++) {
        if (cnt[i] > max) {
            max = cnt[i];
            bin1 = i - 4000;
            bin2 = -5000;
        }
        else if ((max == cnt[i]) && (bin2 == -5000)) {
            bin2 = i - 4000;
        }
    }

    if (bin2 == -5000){
        std::cout << bin1 << "\n";
    }
    else {
        std::cout << bin2 << "\n";
    }

    std::cout << a[N - 1] - a[0] << "\n";
}