//
//  CTECBinaryTree.hpp
//  NodeProjectXCode
//
//  Created by Hopkins, Michael on 4/11/16.
//  Copyright © 2016 Gage Hopkins. All rights reserved.
//

#ifndef CTECBinaryTree_hpp
#define CTECBinaryTree_hpp

#include "TreeNode.hpp"
template<class Type>
class CTECBinaryTree
{
private:
    int size;
    CTECData::TreeNode<Type> * root;
    int height;
    void calculateSize(CTECData::TreeNode<Type> * currentNode);
    bool balenced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    CTECData::TreeNode<Type> * getRightMostChild(CTECBinaryTree<Type> leftSubTree);
    
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    Type remove(const Type& value);
    bool contains(Type value);
    int getSize();
    int getHeight();
    bool isBalenced;
    CTECData::TreeNode<Type> * getRoot();
    void preorderTraversal(CTECData::TreeNode<Type> * currentNode);
    void inorderTraversal(CTECData::TreeNode<Type> * currentNode);
    void postorderTraversal(CTECData::TreeNode<Type> * currentNode);
    
};


#endif /* CTECBinaryTree_hpp */
