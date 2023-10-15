#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        cout << "data->" << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void push(int data) {
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack is empty. Cannot perform pop operation." << endl;
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int main() {
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();

    return 0;
}
