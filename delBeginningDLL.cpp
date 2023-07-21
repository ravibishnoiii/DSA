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
Node *delHead(Node *head){
    if(head==NULL)
    return nullptr;
    if(head->next == NULL){
    delete head;
    return NULL;
    }else{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
    }
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
    head = delHead(head);
    printList(head);
    return 0;
    }