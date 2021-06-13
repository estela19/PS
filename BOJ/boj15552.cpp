#include<iostream>
#include<algorithm>

int T;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> T;
    
    int A, B;
    for(int i = 0; i < T; i++){
        std::cin >> A >> B;
        std::cout << A + B << "\n";
    }
}