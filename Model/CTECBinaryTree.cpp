//
//  CTECBinaryTree.cpp
//  NodeProjectXCode
//
//  Created by Hopkins, Michael on 4/11/16.
//  Copyright © 2016 Gage Hopkins. All rights reserved.
//

#include "CTECBinaryTree.hpp"
#include <iostream>

using namespace std;

template<class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    this->root = nullptr;
    this->size = 0;
    this->height = 0;
    this->balenced = true;
}

template<class Type>
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{
    
}

template<class Type>
int CTECBinaryTree<Type> :: getSize()
{
    size = 0;
    calculateSize(root);
    return size;
}


template<class Type>
void CTECBinaryTree<Type> :: calculateSize(CTECData::TreeNode
                                           <Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        calculateSize(currentNode -> getLeftChild());
        calculateSize(currentNode->getRightChild());
        size++;
        
        
    }
    
}

template<class Type>
CTECData::TreeNode<Type> * CTECBinaryTree<Type> :: getRoot()
{
    return root;
}

template<class Type>
void CTECBinaryTree<Type> :: preorderTraversal(CTECData::TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() << " " << endl;
        
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template<class Type>
void CTECBinaryTree<Type> :: inorderTraversal(CTECData::TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " << endl;
        inorderTraversal(currentNode->getRightChild());
    }
}
template<class Type>
void CTECBinaryTree<Type> :: postorderTraversal(CTECData::TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() << " " << endl;
    }
}

template<class Type>
bool CTECBinaryTree<Type> :: contains(Type Value)
{
    bool isInTree = false;
    if(root != nullptr)
    {
        if(root->getValue() == Value)
        {
            isInTree = true;
        }
        else
        {
            if(Value < root-> getValue())
            {
                isInTree = contains(Value, root->getLeftChild());
            }
            else
            {
                isInTree = contains(Value, root->getRightChild());
            }
            
        }
        
    }
    
    return isInTree;
}






template<class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECData::TreeNode<Type> * currentTree)
{
    bool isInTree = false;
    
    if(currentTree != nullptr)
    {
        if(currentTree -> getValue() == value)
        {
            isInTree = true;
        }
        else
        {
            if(value < currentTree-> getValue())
            {
                isInTree = contains(value, currentTree->getLeftChild());
            }
            else
            {
                isInTree = contains(value, currentTree->getRightChild());
            }
            
        }
    }
    
    return isInTree;
}

template<class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    
    if(contains(value))
    {
        return false;
    }
    else
    {
        CTECData::TreeNode<Type> * current = root;
        CTECData::TreeNode<Type> * trailNode;
        
        if(root == nullptr)
        {
            root = new CTECData::TreeNode<Type>(value);
        }
        else
        {
            while(current != nullptr)
            {
                trailNode = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                    
                }
                else
                {
                    current = current->getRightChild();
                    
                }
            }
            if(trailNode->getValue() > value)
            {
                trailNode->setLeftChild(new CTECData::TreeNode<Type>(value, trailNode));
                
            }
            else
            {
                CTECData::TreeNode<Type> * insertedNode = new CTECData::TreeNode<Type>(value, trailNode);
                trailNode->setRightChild(insertedNode);
                
            }
            
        }
    }
    return true;
}

template <class Type>
CTECData::TreeNode<Type> * CTECBinaryTree<Type>:: getRightMostChild(CTECData::TreeNode<Type> * leftSubTree)
{
    CTECData::TreeNode<Type> * rightNode= leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}

template <class Type>
CTECData::TreeNode<Type> * CTECBinaryTree<Type>:: getLeftMostChild(CTECData::TreeNode<Type> * rightSubTree)
{
    CTECData::TreeNode<Type> * leftNode= rightSubTree->getRoot();
    while(leftNode->getleftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}


template<class Type>
Type CTECBinaryTree<Type> :: remove(const Type& value)
{
    CTECData::TreeNode<Type> * current;
    CTECData::TreeNode<Type> * trailing;
    
    if(!contains(value))
    {
        return;
    }
    else
    {
        current = root;
        trailing =root;
        
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        if(current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild());
        }
        else
        {
            remove(trailing->hetRightChild());
        }
    }
    
}
template<class Type>
void CTECBinaryTree<Type> :: remove(CTECData::TreeNode<Type> * nodeToBeRemoved)
{
    CTECData::TreeNode<Type> * current;
    CTECData::TreeNode<Type> * trailing;
    CTECData::TreeNode<Type> * temp;
    
    if(nodeToBeRemoved == nullptr)
    {
        cerr << "That isn't in the list" << endl;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr && nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = nullptr;
        delete temp;
    }
    else if(nodeToBeRemoved->getLeftChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getRightChild();
        delete temp;
    }
    else if(nodeToBeRemoved->getRightChild() == nullptr)
    {
        temp = nodeToBeRemoved;
        nodeToBeRemoved = temp->getLeftChild();
        delete temp;
    }
    else
    {
        current = nodeToBeRemoved->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild() != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToBeRemoved->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToBeRemoved->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        delete current;
        
    }
    
}
