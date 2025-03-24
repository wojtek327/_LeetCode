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

void postorder(struct TreeNode* node, int **arr, int *capacity, int *return_size) {
    if (node) {
        postorder(node->left, arr, capacity, return_size);
        postorder(node->right, arr, capacity, return_size);

        if (*return_size >= *capacity) {
            *capacity *= 2;
            *arr = (int*)realloc(*arr, sizeof(int) * (*capacity));
        }
        (*arr)[(*return_size)++] = node->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int capacity = 10;
    int *arr = (int*)malloc(sizeof(int) * capacity);

    if (!arr) {
        *returnSize = 0;
        return NULL;
    }

    postorder(root, &arr, &capacity, returnSize);
    return arr;
}
