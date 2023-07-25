/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-24
 * 
 * @copyright Copyright (c) 2022
 * 
 * 链表操作 15分
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* prior;
    struct node* next;
} Node_S;

void quickSort(node* head, node* tail) {
    if (head == tail || head->next == tail) {
        return;
    }
    int pivot = head->data;
    node *left = head, *cur = head->next;

    while(cur != tail) {
        if (cur->data > pivot) {
            left = left->next;
            swap(left->data, cur->data);
        }
        cur = cur->next;
    }
    swap(head->data, left->data);
    quickSort(head, left);
    quickSort(left->next, tail);
}

node* sort(node* head) { 
    quickSort(head, NULL); 
    return head;
}

int main() { 
    node* a;
    a->data = 3;
    cout << a->data << endl;
    return 0; 
}