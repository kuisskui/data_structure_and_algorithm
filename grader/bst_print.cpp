#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
    valueType val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(valueType val, TreeNode *left = 0, TreeNode *right = 0)
        : val(val), left(left), right(right) {}
};

void inorder(TreeNode *r, int level)
{
    string stuff(3 * level, '.');
    if (!r)
    {
        return;
    }
    inorder(r->right, level+1);
    cout << stuff << "* " << r->val << endl;
    inorder(r->left, level+1);
}

void insert(TreeNode *&r, valueType x)
{
    if (!r)
    {
        r = new TreeNode(x);
    }
    else if (x < r->val)
    {

        insert(r->left, x);
    }
    else if (x > r->val)
    {

        insert(r->right, x);
    }
}

int main()
{
    TreeNode *root = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(root, x);
    }

    inorder(root, 0);
}
