#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to insert a node at a given position
    void insertAtPosition(int data, int position) {
        Node* newNode = createNode(data);

        if (position == 1) {
            // Inserting at the beginning of the list
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            int currentPosition = 1;

            // Traverse the list to find the node at the previous position
            while (temp != nullptr && currentPosition < position - 1) {
                temp = temp->next;
                currentPosition++;
            }

            if (temp == nullptr) {
                cout << "Invalid position. The list is shorter than the given position.\n";
                delete newNode;
                return;
            }

            // Insert the new node after the previous node
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    LinkedList linkedList;
    linkedList.insertAtPosition(10, 1);
    linkedList.insertAtPosition(20, 2);
    linkedList.insertAtPosition(30, 3);
    linkedList.insertAtPosition(15, 2); 

    linkedList.display(); 

    return 0;
}
