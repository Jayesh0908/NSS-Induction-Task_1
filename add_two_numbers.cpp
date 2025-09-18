#include <iostream>
#include <vector>
using namespace std;

// 2. Add Two Numbers -Leetcode

// defining Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// main Code Logic
ListNode* adder(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* temp = head;
    temp->next = NULL;
    int carry = 0, x;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;

    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        x = 0;
        if (temp1 != NULL) {
            x += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            x += temp2->val;
            temp2 = temp2->next;
        }
        x += carry;
        int y = x % 10;
        carry = x / 10;
        ListNode* newnode = new ListNode();
        newnode->val = y;
        temp->next = newnode;
        temp = temp->next;
    }

    return head->next;
}

// creates the linked lists
ListNode* NewList(vector<int> l1) {
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    for (int i = 0; i < l1.size(); i++) {
        current->next = new ListNode(l1[i]);
        current = current->next;
    }
    return head->next;
}
// prints the final linked list
void display(ListNode* head) {
    ListNode* temp = head;
    cout << "{";

    while (temp != NULL) {
        cout << temp->val;
        temp = temp->next;
        if (temp != NULL) {
            cout << ",";
        }
    }
    cout << "}";
}

// main function
int main() {
    // Change input/linked lists here
    vector<int> v1 = {2, 4, 3};
    vector<int> v2 = {5, 6, 4};

    ListNode* l1 = NewList(v1);
    ListNode* l2 = NewList(v2);

    display(adder(l1, l2));

    return 0;
}