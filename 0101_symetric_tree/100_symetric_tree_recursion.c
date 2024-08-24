/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helperFunction(struct TreeNode* root_1, struct TreeNode* root_2)
{
    if (root_1 == NULL && root_2 == NULL) {
        return true;
    }
    else if(root_1 == NULL || root_2 == NULL) {
        return false;
    }

    if (root_1->val == root_2->val) {
        return helperFunction(root_1->left, root_2->right) && helperFunction(root_1->right, root_2->left);
    }

    return false;
}

bool isSymmetric(struct TreeNode* root) {
    return helperFunction(root, root);
}
