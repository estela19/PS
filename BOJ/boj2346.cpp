#include<iostream>
#include<algorithm>

struct Node{
    Node* next = NULL;
    Node* prev = NULL;
    int data;
    int idx;
};

int N;

int main() {
    Node* first = NULL;
    Node* index = NULL;

    std::cin >> N;

    first = new Node;
    index = first;
    for (int i = 0; i < N ; i++) {
        int tmp;
        std::cin >> tmp;
        
        index->next = new Node;
        index->next->prev = index;
        index = index->next;
        index->data = tmp;
        index->idx = i + 1;
    }
    index->next = first->next;
    first->next->prev = index;

    index = first->next;
    while (index->next != NULL) {
        std::cout << index->idx << " ";

        if (index->next == index) {
            index->next = NULL;
            break;
        }
        Node* prev = index->prev;
        index->next->prev = index->prev;
        prev->next = index->next;

        int num = index->data;
        while (num > 0) {
            index = index->next;
            num--;
        }
        while (num < 0) {
            index = index->prev;
            num++;
        }

       
    }
}