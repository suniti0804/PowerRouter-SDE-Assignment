/*Explanation - 
In this implementation, we use two pointers: a slow pointer that moves one node at a time, and a fast pointer that moves two nodes at a time. 
When the fast pointer reaches the end of the list, the slow pointer points to the middle node. 
If the number of nodes is even, the slow pointer will point to the second middle node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getMiddle(Node* head) {
    if (head == NULL) {
        return -1; // empty list
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

int main() {
    Node* head = new Node;
    head->data = 1;
    head->next = NULL;
    
    Node* second = new Node;
    second->data = 2;
    second->next = NULL;
    head->next = second;
    
    Node* third = new Node;
    third->data = 3;
    third->next = NULL;
    second->next = third;
    
    Node* fourth = new Node;
    fourth->data = 4;
    fourth->next = NULL;
    third->next = fourth;
    
    Node* fifth = new Node;
    fifth->data = 5;
    fifth->next = NULL;
    fourth->next = fifth;
    
    cout << getMiddle(head) << endl; // Output: 3
    
    Node* sixth = new Node;
    sixth->data = 6;
    sixth->next = NULL;
    fifth->next = sixth;
    
    cout << getMiddle(head) << endl; // Output: 4
    
    return 0;
}
