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

// Method 1 - using for loop

void printList(Node *head)
{
    if(head==nullptr)
        return ;
    //if LL is not empyt then first we print head and after  that we will print next of the node
    cout << (head->data) <<" " ;
    for (Node *p = head->next; p != head;p=p->next){
        cout << (p->data)<<" ";
    }
    cout << endl;
}

// Method 2 - using do while loop

void printlist(Node *head){
    if(head==nullptr)
        return ;
    Node *p=head;
    do{
        cout << (p->data) << " ";
        p = p->next;
    } while (p != head);
}
int main(){
    Node *head = new Node(10);
    head->next = new Node(77);
    head->next->next = new Node(20);
    head->next->next->next = new Node(54);
    head->next->next->next->next = head;
    cout << "method 1"<<endl;
    printList(head);
    cout << "method 2" << endl;
    printlist(head);
}