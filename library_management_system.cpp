#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // If duplicate, do nothing
    return root;
}

// Search for a book ID
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// Display sorted book IDs (inorder)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, id;

    while (true) {
        cout << "\n===== SMART BOOK TRACKING SYSTEM =====\n";
        cout << "1. Insert returned Book ID\n";
        cout << "2. Check if Book ID is returned\n";
        cout << "3. Display all returned Book IDs (sorted)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID to insert: ";
                cin >> id;
                root = insert(root, id);
                cout << "Book ID inserted.\n";
                break;

            case 2:
                cout << "Enter Book ID to search: ";
                cin >> id;
                if (search(root, id))
                    cout << "Book ID FOUND.\n";
                else
                    cout << "Book ID NOT FOUND.\n";
                break;

            case 3:
                cout << "Returned Book IDs in sorted order:\n";
                inorder(root);
                cout << "\n";
                break;

            case 4:
                cout << "Exiting... Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
