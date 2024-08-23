/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * morris traversal
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) { return true; }
    if (p == NULL || q == NULL) { return false; }

    // Morris traversal
    while (p != NULL && q != NULL) {
        if (p->val != q->val) { return false; }

        if (p->left == NULL) {
            p = p->right;
        } else {
            // if the left child is not NULL, find the predecessor
            struct TreeNode* pre = p->left;
            while (pre->right != NULL && pre->right != p) {
                pre = pre->right;
            }
            if (pre->right  == NULL) {
                pre->right = p;
                p = p->left;
            }
            else {
                pre->right = NULL;
                p = p->right;
            }
        }

        if (q->left == NULL) {
            q = q->right;
        }
        else {
            struct TreeNode* pre = q->left;
            while (pre->right != NULL && pre->right != q) {
                pre = pre->right;
            }
            if (pre->right == NULL) {
                pre->right = q;
                q = q->left;
            }
            else {
                pre->right = NULL;
                q = q->right;
            }
        }
    }

    return (p == NULL && q == NULL);
}
