#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

    Node(T value) : value(value) {}

    Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
      left->parent = right->parent = this;
    }

    // traverse the node and its children preorder
    // and put all the results into `result`
    void helper(Node *root, vector<Node<T>*>& result)
    {
        if(root==nullptr)
            return;
            
        result.push_back(root);
        helper(root->left, result);
        helper(root->right, result);
        return;
    }
    void preorder_traversal(vector<Node<T>*>& result)
    {
        helper(this, result);
        return;
    }
};
