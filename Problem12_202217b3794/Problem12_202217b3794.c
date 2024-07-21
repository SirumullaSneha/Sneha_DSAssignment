#include <stdio.h>
#include <stdlib.h> // Needed for malloc and free

// Node structure to define the structure of a node in the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert nodes into the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to find the minimum value node in a binary tree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node in the binary tree
Node* deletion(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deletion(root->left, key);
    } else if (key > root->data) {
        root->right = deletion(root->right, key);
    } else {
        // Node to be deleted found with one or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node to be deleted has two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

// Function for inorder tree traversal (Left - Root - Right)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder tree traversal (Root - Left - Right)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder tree traversal (Left - Right - Root)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function for level order tree traversal using a queue
void levelorderTraversal(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
}

/* Driver function to check the above algorithms. */
int main() {
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform different traversals
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level order traversal: ");
    levelorderTraversal(root);
    printf("\n");

    // Delete node with value 20
    root = deletion(root, 20);

    // Perform inorder traversal after deletion
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
