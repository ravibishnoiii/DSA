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

int searchLL(Node *head,int x){
    int pos = 1;
    Node *curr = head;
    while(curr!=NULL){
        if(curr->data==x){
            return pos;
        }
           
        else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(60);
    head ->next -> next = new Node(14);
    head ->next->next->next = new Node(19);
    int a = searchLL(head, 60);
    cout << a << endl;
    return 0;
}