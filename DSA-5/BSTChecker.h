#ifndef BSTCHECKER_H
#define BSTCHECKER_H
#include <set>
#include <unordered_set>
#include <climits>

// TODO: Include any needed header files
#include "BSTNode.h"
using namespace std;

unordered_set<int> globalpoint;
BSTNode* temp;

class BSTChecker {
public:
   // TODO: Add any desired utility functions

   // CheckBSTValidty() determines if the tree is a valid BST. If so, nullptr
   // is returned. If not, the first (in preorder traversal) node in violation
   // of BST requirements is returned. Such a node will be one of the following:
   // - A node in the left subtree of an ancestor with a lesser or equal key
   // - A node in the right subtree of an ancestor with a greater or equal key
   // - A node that is encountered more than once during traversal
   static bool CompareRoot(BSTNode* rootNode, int min, int max)
    {
       if(rootNode == nullptr)
       {
           return true;
       }
       
       else
       {
           //cout << "Now testing in function 1: " << rootNode->key<<endl;
           if (rootNode->key >= max || rootNode->key <= min)
           {
               temp = rootNode;
               return false;
           }
           
           return (CompareRoot(rootNode->left, min, rootNode->key )&&CompareRoot(rootNode->right, rootNode->key, max));
           
       }
    }
    
    
    static bool CheckLoopingPointers(BSTNode* rootNode)
    {
        
        if (rootNode == nullptr)
        {
            return true;
        }
        //cout << "Now testing in function 2: " << rootNode->key<<endl;
        if (globalpoint.find(rootNode->key) != globalpoint.end())
            {
                temp = rootNode;
                return false;
            }
            globalpoint.insert(rootNode->key);

        return (CheckLoopingPointers(rootNode->left)&&CheckLoopingPointers(rootNode->right));
        
        
    };
    static void globalclear()
    {
        globalpoint.clear();
        temp = nullptr;
    };
    
   static BSTNode* CheckBSTValidity(BSTNode* rootNode) {
      // TODO: Type your code here (remove placeholer line below)
       globalclear();
       if (CompareRoot(rootNode,INT_MIN,INT_MAX) != true)
       {
           return temp;
       }
       globalclear();
       if (CheckLoopingPointers(rootNode) != true)
       {
           return temp;
       }
       return nullptr;
   }
   
};

#endif
