/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return root;
    }

    struct TreeNode* queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct TreeNode* curr = queue[front++];

        // Swap the left and right subtree
        struct TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        // Push the left and right node to the queue
        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }

    return root;
}
