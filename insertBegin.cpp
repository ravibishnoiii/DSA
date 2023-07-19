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
Node *insertBeginning(Node *head,int x){
    Node *temp = new Node(x);
    temp->next = head;   // <- in this temp -> next = head this means in beginning head = null so next = null
    return temp;
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
    head = insertBeginning(head, 30);
    head = insertBeginning(head, 20);
    head = insertBeginning(head, 10);
    head = insertBeginning(head, 5);
    printList(head);
    return 0;
}