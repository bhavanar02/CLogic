#include <stdbool.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p == NULL && q == NULL) 
    {
        return true;
    }
    
    if (p == NULL || q == NULL) 
    {
        return false;
    }
    
    if (p->val != q->val) 
    {
        return false;
    }
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

#include <stdio.h>

/* int main() 
{
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};

    struct TreeNode* tree1 = &node1;
    tree1->left = &node2;
    tree1->right = &node3;

    struct TreeNode node4 = {1, NULL, NULL};
    struct TreeNode node5 = {2, NULL, NULL};
    struct TreeNode node6 = {4, NULL, NULL};

    struct TreeNode* tree2 = &node4;
    tree2->left = &node5;
    tree2->right = &node6;

    if (isSameTree(tree1, tree2)) 
    {
        printf("True");
    } 
    else
    {
        printf("False");
    }

    return 0;
} */

