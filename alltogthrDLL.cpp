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

Node *insertBegin(Node *head,int data){
    Node *temp = new Node(data);
    temp->next = head;
    if(head!=NULL){
    head->prev = temp;
    }
     return temp;
}
Node *insertEnd(Node *head,int data){
    Node *temp = new Node(data);
    if(head == NULL)
    return temp;
    Node *curr = head;
    while(curr->next!=NULL){
    curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
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
Node *delEnd(Node *head){
    if(head==NULL)
    return nullptr;
    if(head->next==NULL){
    delete head;
    return nullptr;
    }
    Node *curr = head;
    while(curr->next!=nullptr){
    curr = curr->next;
    }
    curr->prev->next = NULL;
    delete curr;
    return head;
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
    head = insertBegin(head, 15);
    head = insertBegin(head, 19);
    head = insertEnd(head, 34);
    head = insertEnd(head, 54);
    head = delHead(head);
    head = delEnd(head);
    head = reverseLL(head);
    printList(head);
    return 0;
    }