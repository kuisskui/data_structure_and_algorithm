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

TreeNode *find(TreeNode *r, valueType x)
{

    if (!r)
    {
        return NULL;
    }
    if (r->val == x)
    {
        return r;
    }
    else if (x < r->val)
    {
        return find(r->left, x);
    }
    else if (x > r->val)
    {
        return find(r->right, x);
    }
    return NULL;
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
        if (x == 1)
        {
            cin >> x;
            insert(root, x);
        }
        else if (x == 2)
        {
            cin >> x;
            if (find(root, x))
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}