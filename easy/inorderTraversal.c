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
void traversal(struct TreeNode* root, int *result, int *returnSize) {
    if (root == NULL) {
        return;
    }
    traversal(root->left,result,returnSize);
    result[(*returnSize)++] = root->val;
    traversal(root->right,result,returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *a = (int*)malloc(100 * sizeof(int));
    traversal(root,a,returnSize);
    return a;
}