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

 // Approach 1 (Naive).  In this Time complexity of code is O(n)

 Node *insertBeginning(Node *head,int x){
    Node *temp = new Node(x);
    if (head==nullptr)
         temp->next = temp;
    else{
         Node *curr = head;
         while(curr->next!=head){
             curr = curr->next;
         }
         curr->next = temp;
         temp->next = head;
    }
    return temp;
 }

 // Approact 2 (Efficient). Maintaining the tail pointer and In this time complexity will be O(1)
Node *insertBegin(Node*head,int x){
    Node *temp = new Node(x);
    if (head==nullptr){
    temp->next = temp;
    return temp;
    }else{
        //making this 2nd no. node 
    temp->next = head->next;
    head->next = temp;
    //swaping data of 2nd node with first
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
    }
         

}


int main(){
    Node *head = new Node(10);
    head->next = new Node(77);
    head->next->next = new Node(20);
    head->next->next->next = new Node(54);
    head->next->next->next->next = head;
    head = insertBeginning(head, 35);
    head = insertBegin(head, 88);
    printlist(head);
}