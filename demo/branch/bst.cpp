

// C program to to implement binary tree

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bst.h"

#define queue_size 262144
// Define a structure for tree nodes

// Function to create a new Node
Node* createNode(int64_t data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int64_t data)
{
    if (root == nullptr) { // If the tree is empty, return a
                           // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST
int inorderTraversal(Node* root)
{
    int total =0;
    if (root != nullptr) {
        total++;
        total+=inorderTraversal(root->left);
        //cout << root->data << " ";
        total+=inorderTraversal(root->right);
    }
    return total;
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int64_t key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node* deleteNode(Node* root, int64_t data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/*
int main(int *data, unsigned int size, int threshold)
{

    Node* root = NULL;

    // Inserting nodes
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);
    insert(&root, 80);

    // Inorder traversal
    //printf("Inorder traversal of the given Binary Search "
           "Tree is: ");
    inorderTraversal(root);
    //printf("\n");

    // Deleting a node
    int deleteNodeValue = 20;
    deleteNode (&root, deleteNodeValue);
    //printf("After deletion of %d: ", deleteNodeValue);
    inorderTraversal(root);
    //printf("\n");

    // Inserting a new node
    int insertValue = 25;
    insert(&root, insertValue);
    //printf("After insertion of %d: ", insertValue);
    inorderTraversal(root);
    //printf("\n");

    // Searching for a node
    int target = 25;
    Node* searchResult = search(root, target);
    if (searchResult != NULL) {
        //printf("Node %d found in the BST.\n", target);
    }
    else {
        //printf("Node %d not found in the BST.\n", target);
    }

    return 0;
}
*/
