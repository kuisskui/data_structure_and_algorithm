#include <iostream>
#include <algorithm>

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

void inorder(TreeNode *r, int level)
{
    string stuff(3 * level, '.');
    if (!r)
    {
        return;
    }
    inorder(r->right, level + 1);
    cout << stuff << "* " << r->val << endl;
    inorder(r->left, level + 1);
}

const int MAX_CD = 1000010;
int Jack[MAX_CD], Jill[MAX_CD];
int main()
{
    int Jack_cd = 1;
    int Jill_cd = 1;
    while (true)
    {
        TreeNode *Jack_root = 0;
        TreeNode *Jill_root = 0;
        int counter = 0;
        int x = 0;

        cin >> Jack_cd >> Jill_cd;
        for (int i = 0; i < Jack_cd; i++)
        {
            cin >> x;
            Jack[i] = x;
            insert(Jack_root, x);
        }
        for (int i = 0; i < Jill_cd; i++)
        {
            cin >> x;
            insert(Jill_root, x);
        }
        // cout << "This is the Jack's root" << endl;
        // inorder(Jack_root, 0);
        // cout << "This is the Jill's root" << endl;
        // inorder(Jill_root, 0);
        for (int i = 0; i < Jack_cd; i++)
        {
            if (find(Jill_root, Jack[i]))
            {
                counter += 1;
            }
        }

        if (!Jack_cd && !Jill_cd)
        {
            break;
        }
        cout << counter << endl;
    }
}