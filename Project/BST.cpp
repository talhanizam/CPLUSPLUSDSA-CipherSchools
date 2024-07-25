#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node *left, *right;
};

// Function to create a new node
Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to insert a new key in BST
Node* insert(Node* root, int insertval) {
    if (root == nullptr) {
        return newNode(insertval);
    }
    if (root->key > insertval) {
        root->left = insert(root->left, insertval);
    } else if (root->key < insertval) {
        root->right = insert(root->right, insertval);
    }
    return root;
}

// Function to search a key in BST
bool search(Node* root, int searchval) {
    if (root == nullptr) {
        return false;
    }
    if (root->key == searchval) {
        return true;
    } else if (root->key > searchval) {
        return search(root->left, searchval);
    } else {
        return search(root->right, searchval);
    }
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int deleteval) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->key > deleteval) {
        root->left = deleteNode(root->left, deleteval);
    } else if (root->key < deleteval) {
        root->right = deleteNode(root->right, deleteval);
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* parent = root;
        Node* y = root->right;
        while (y != nullptr && y->left != nullptr) {
            parent = y;
            y = y->left;
        }

        // Copy the inorder successor's content to this node
        root->key = y->key;

        // Delete the inorder successor
        if (parent->left == y) {
            parent->left = y->right;
        } else {
            parent->right = y->right;
        }

        delete y;
    }
    return root;
}

// Function to perform inorder traversal of BST
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // File handling
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Reading number of elements
    int n;
    cin >> n;

    Node* root = nullptr;

    // Inserting elements
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    // Searching elements
    cout << "15 : " << search(root, 15) << endl;
    cout << "25 : " << search(root, 25) << endl;
    cout << "50 : " << search(root, 50) << endl;

    // Inorder traversal
    inorder(root);
    cout << endl;

    // Deleting an element
    int del;
    cin >> del;
    root = deleteNode(root, del);
    cout << "after deleting : " << del << endl;

    // Inorder traversal after deletion
    inorder(root);
    cout << endl;

    return 0;
}
