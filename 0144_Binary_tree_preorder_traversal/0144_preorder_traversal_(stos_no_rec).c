int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) {
        return NULL;
    }

    int stackCapacity = 100;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * stackCapacity);
    int stackTop = -1;

    int resultCapacity = 100;
    int* result = (int*)malloc(sizeof(int) * resultCapacity);

    stack[++stackTop] = root;

    while (stackTop >= 0) {
        struct TreeNode* current = stack[stackTop--];

        if (*returnSize >= resultCapacity) {
            resultCapacity *= 2;
            result = (int*)realloc(result, sizeof(int) * resultCapacity);
        }
        result[(*returnSize)++] = current->val;

        if (current->right) {
            if (stackTop + 1 >= stackCapacity) {
                stackCapacity *= 2;
                stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*) * stackCapacity);
            }
            stack[++stackTop] = current->right;
        }
        if (current->left) {
            if (stackTop + 1 >= stackCapacity) {
                stackCapacity *= 2;
                stack = (struct TreeNode**)realloc(stack, sizeof(struct TreeNode*) * stackCapacity);
            }
            stack[++stackTop] = current->left;
        }
    }

    free(stack); // Zwalniamy pamięć używaną przez stos
    return result;
}
