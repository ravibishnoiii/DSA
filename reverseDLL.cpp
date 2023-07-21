#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};
void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
    cout << (curr->data) << " ";
    curr = curr->next;
    }
}
Node *reverseLL(Node *head){
    if (head == NULL || head->next == NULL)
    return head;
    Node *prev = NULL;
    Node *curr = head;
    while(curr!=NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    head->prev = NULL;
    temp1->next = temp2;
    temp1->prev = head;
    temp2->prev = temp1;
    temp2->next = NULL;
    head = reverseLL(head);
    printList(head);
    }