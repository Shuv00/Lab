#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* llink;
    struct node* rlink;
};

struct node* create() {
    struct node* newnode = new node();
    cout << "Enter the data: ";
    cin >> newnode->data;
    newnode->rlink = NULL;
    newnode->llink = NULL;
    return newnode;
}

void insert(struct node** root) {
    struct node* newnode = create();
    if (*root == NULL) {
        *root = newnode;
    } else {
        struct node* current = *root;
        while (true) {
            if (newnode->data < current->data) {
                if (current->llink == NULL) {
                    current->llink = newnode;
                    break;
                }
                current = current->llink;
            } else if (newnode->data > current->data) {
                if (current->rlink == NULL) {
                    current->rlink = newnode;
                    break;
                }
                current = current->rlink;
            } else {
                // Handle case where the data already exists in the tree (if desired)
                break;
            }
        }
    }
}
void preorder(struct node* tmp){
    if(tmp!=NULL){
        cout<<tmp->data<<"->";
        preorder(tmp->llink);
        preorder(tmp->rlink);
    }
}
void inorder(struct node* tmp){
    inorder(tmp->llink);
    cout<<tmp->data<<"->";
    inorder(tmp->rlink);
}
void postorder(struct node* tmp) {
    if (tmp != NULL) {
        postorder(tmp->llink);
        postorder(tmp->rlink);
        cout << tmp->data << "->";
    }
}

int main() {
    struct node* root = NULL;
    insert(&root);
    insert(&root);
    postorder(root);
    return 0;
}
