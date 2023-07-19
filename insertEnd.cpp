#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};
Node *inserAtEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head== NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next!=NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}
void printList(Node *head){
    Node *curr = head;
    while(curr!=NULL){
    cout << (curr->data) << " ";
    curr = curr->next;
    }
}
int main(){
    Node *head = NULL;
    head = inserAtEnd(head, 10);
    head = inserAtEnd(head, 20);
    head = inserAtEnd(head, 30);
    printList(head);
    return 0;
}