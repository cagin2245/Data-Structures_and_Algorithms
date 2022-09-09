#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <vector>



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
        cout << "Preorder: " << root->left.get() << endl;

        treeTraversal(root->left);

        cout << "Preorder: " << root->right.get() << endl;

        treeTraversal(root->right);

        cout << "Post-order: " << root->data << endl;
        
    }
}