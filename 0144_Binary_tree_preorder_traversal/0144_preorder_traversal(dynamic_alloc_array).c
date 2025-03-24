void preorder(struct TreeNode* node, int **arr, int *capacity, int *return_size) {
    if (node) {
        if (*return_size >= *capacity) {
            *capacity *= 2;
            *arr = (int*)realloc(*arr, sizeof(int) * (*capacity));
        }
        (*arr)[(*return_size)++] = node->val;

        preorder(node->left, arr, capacity, return_size);
        preorder(node->right, arr, capacity, return_size);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int capacity = 10;
    int *arr = (int*)malloc(sizeof(int) * capacity);

    if (!arr) {
        *returnSize = 0;
        return NULL;
    }

    preorder(root, &arr, &capacity, returnSize);
    return arr;
}
