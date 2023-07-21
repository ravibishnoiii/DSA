#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = nullptr;
    }
};
void printlist(Node *head){
    if(head==nullptr)
        return ;
    Node *p=head;
    do{
        cout << (p->data) << " ";
        p = p->next;
    } while (p != head);
}

// Approach 1 (Naive Approach) - Time Complexity-O(N)

Node *insertEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }else{
        Node *curr = head;
        while(curr->next!=head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
        return head;
    }
}

// Approach 2 (Efficient Solution) - Time Complexity-O(1)

Node *insertAtEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }else{
        //adding the node at second number 
        temp->next = head->next;
        head->next = temp;
        //swapping
        int t = temp->data;
        temp->data = head->data;
        head->data = t;
        // return temp as new head
        return temp;
    }
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(77);
    head->next->next = new Node(20);
    head->next->next->next = new Node(54);
    head->next->next->next->next = head;
    head = insertEnd(head, 50);
    head = insertAtEnd(head, 80);
    printlist(head);
}