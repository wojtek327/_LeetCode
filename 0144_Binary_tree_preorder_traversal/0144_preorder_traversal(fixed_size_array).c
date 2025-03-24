/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorder(struct TreeNode* node, int *arr, int* return_size) {
    if(node) {
        arr[(*return_size)] = node->val;
        (*return_size)++;
        preorder(node->left, arr, return_size);
        preorder(node->right, arr, return_size);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    preorder(root, arr, returnSize);
    return arr;
}
