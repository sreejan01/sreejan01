#include <iostream>

using namespace std;

struct tree {
    int data;
    tree *lc, *rc;
} ;

void find1(tree *root, tree *nn) {
    if (nn->data < root->data) {
        if (root->lc == NULL) {
            root->lc = nn; // Insert left
        } else {
            find1(root->lc, nn); // Recur left
        }
    } else {
        if (root->rc == NULL) {
            root->rc = nn; // Insert right
        } else {
            find1(root->rc, nn); // Recur right
        }
    }
}

void create(tree *&root, int value) {
    tree *nn = new tree; // Create new node
    nn->data = value;
    nn->lc = NULL;
    nn->rc = NULL;

    if (root == NULL) {
        root = nn; // Set root if tree is empty
    } else {
        find1(root, nn); // Insert node in the correct position
    }
}

void pre_order(tree *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    pre_order(root->lc);
    pre_order(root->rc);
}
void post_order(tree *root) {
    if (root == NULL)
        return;
    
    post_order(root->lc);
    post_order(root->rc);
    cout << root->data << " ";
}
void in_order(tree *root) {
    if (root == NULL)
        return;
    
    in_order(root->lc);
    cout << root->data << " ";
    in_order(root->rc);
}
bool search(tree *root, int value) {
    // Base case: if the tree is empty or the value is found
    if (root == NULL) {
        return false; // Value not found
    }
    if (root->data == value) {
        return true; // Value found
    }
    
    // If the value is less than the current node's data, search in the left subtree
    if (value < root->data) {
        return search(root->lc, value);
    } else { // If the value is greater, search in the right subtree
        return search(root->rc, value);
    }
}

int main() {
    tree *root = NULL; // Initialize root
    create(root, 60);
    create(root, 50);
    create(root, 80);
    create( root, 100);
    create(root, 90);
    pre_order(root);
    cout<<endl;
    post_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    int valueToSearch = 90; // Example value to search
    if (search(root, valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the tree." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the tree." << endl;
    }
    return 0;
    
}