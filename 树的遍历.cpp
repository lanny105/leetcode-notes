
先序： // 其实就是dfs.
 vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> mystack;
        vector<int> res;
        mystack.push(root);

        while(mystack.size()) {
            TreeNode* root = mystack.top();
            mystack.pop();
            res.push_back(root->val);

            if(root->right) {
                mystack.push(root->right);
            }

            if(root->left) {
                mystack.push(root->left);
            }
        }

        return res;
    }


中序： //步骤是这样的，先从root开始，一边压栈，一边往左下节点走，直到走到最底端，然后从栈里弹出，改点就是当前root的最先遍历点，便利，然后，将root更新到改点的右子树。重新进行上述循环，如果右子树存在，则表明下一次循环时要先访问右子树，右子树不存在的话  就访问上一层父母。

    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> mystack;
        vector<int> res;

        while(root||mystack.size()) {   //每一次进循环都是中序访问以root为根节点的子树。  如果root为空 从栈里弹出之前的节点，注意这种节点的左子树肯定访问过，所以就访问本身，再访问右子树。

            while(root){   //root存在
                mystack.push(root);
                root = root->left;
            }

            root = mystack.top();
            mystack.pop();
            res.push_back(root->val);

            root = root->right;
        }

        return res;

    }


后序：

思想很简单，每一次循环看栈顶这个点，如果栈顶这个点 对至少有一个孩子的节点，必须先访问它们，肯定是将其右孩子压入栈，左孩子压入栈，得一会先访问左右孩子。第二次访问就直接弹出栈。如果这个点没有孩子或者孩子访问完毕，就访问该点。 问题是怎么知道孩子访问过了？我们可以控制一个pre指针，每一次访问过一个节点，就保存给pre，每一次检测该节点的左孩子和右孩子是否访问过，就看pre是否等于左孩子或右孩子，且pre要不等于空。

// 其实右左的先序是后序遍历的逆序。。。

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        if(!root) return {};

        TreeNode* pre = NULL;
        stack<TreeNode*> mystack;
        mystack.push(root);
        vector<int> res;


        while(mystack.size()) {
            TreeNode* root1 = mystack.top();

            if((!root1->left&&!root1->right)||(pre&&(pre == root1->left||pre == root1->right))) {

                res.push_back(root1->val);
                pre = root1;
                mystack.pop();

            }

            else {
                if(root1->right) {
                    mystack.push(root1->right);
                }

                if(root1->left) {
                    mystack.push(root1->left);
                }
            }
        }


        return res;

    }
};
