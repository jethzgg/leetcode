/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traversal(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        result[(*returnSize)++] = 'null';
        return;
    }
    result[(*returnSize)++] = root->val;

    traversal(root->left,result,returnSize);
    
    traversal(root->right,result,returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(1000 * sizeof(int));
    traversal(root,result,returnSize);
    return result;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int* r1 = (int*)malloc(sizeof(int));
    int* r2 = (int*)malloc(sizeof(int));
    int* a = (int*)malloc(1000 * sizeof(int));
    a = inorderTraversal(p,r1);
    int* b = (int*)malloc(1000 * sizeof(int));
    b = inorderTraversal(q,r2);
    if (*r1 != *r2) {
        return false;
    }
    for (int i = 0; i<*r1; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}