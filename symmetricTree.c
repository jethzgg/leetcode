/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void fromRight(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        result[(*returnSize)++] = 'null';
        return;
    }
    result[(*returnSize)++] = root->val;

    fromRight(root->right, result, returnSize);

    fromRight(root->left, result, returnSize);    
}

void fromLeft(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        result[(*returnSize)++] = 'null';
        return;
    }
    result[(*returnSize)++] = root->val;

    fromLeft(root->left, result, returnSize);
    
    fromLeft(root->right, result, returnSize);    
}

bool isSymmetric(struct TreeNode* root) {
    struct TreeNode* a = root->left;
    struct TreeNode* b = root->right;

    int* result1 = (int*)malloc(1000*sizeof(int));
    int* result2 = (int*)malloc(1000*sizeof(int));
    int* returnSize1 = (int*)malloc(sizeof(int));
    *returnSize1 = 0;
    int* returnSize2 = (int*)malloc(sizeof(int));
    *returnSize2 = 0;
    fromLeft(a,result1,returnSize1);
    fromRight(b,result2,returnSize2);
    if (*returnSize1 != *returnSize2) {
        return false;
    }
    for (int i = 0; i<*returnSize1; i++) {
        printf("%d %d\n",result1[i],result2[i]);
        if (result1[i] != result2[i]) {
            return false;
        }
    }
    return true;
}