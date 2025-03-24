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

void postorder(struct TreeNode* node, int *arr, int* return_size) {
    if(node) {
        postorder(node->left, arr, return_size);
        postorder(node->right, arr, return_size);
        arr[(*return_size)] = node->val;
        (*return_size)++;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* arr = (int*)malloc(sizeof(int) * 100);

    postorder(root, arr, returnSize);
    return arr;
}
