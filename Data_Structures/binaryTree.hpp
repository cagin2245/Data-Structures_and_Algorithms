#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <vector>
#include <utility>


using std::cout, std::endl;


template <typename T>
struct binaryTreeNode {
    T data;
    std::unique_ptr<binaryTreeNode<T>> left,right;    
};

void treeTraversal (const std::unique_ptr<binaryTreeNode<int>> & root)
{
    if(root)
    {
        cout << "Preorder: "<< root->data << endl;

        treeTraversal(root->left);

        cout << "Inorder: " << root->right << endl;

        treeTraversal(root->right);

        cout << "Post-order: " << root->data << endl;
        
    }
}