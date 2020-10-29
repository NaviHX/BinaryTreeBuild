#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

typedef struct BinaryTreeNode
{
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    char val;
} node;

node *nodeInit(node *left, node *right, char val);
node *binaryTreeBuild(string &s, int *idx);
void binaryTreeFree(node *root);
void binaryTreePrint(node *root);
int getBinaryTreeDepth(node *root);
void test();
void testPrint(node *root);

int main()
{
    int arg;
    cout
        << "可以选择的功能选项:\n"
        << "1.输入先序遍历序列转二叉树\n"
        << "2.查看帮助,了解输入输出格式\n"
        << "0.退出程序\n";
    do
    {
        cout << "\n请输入功能选项:";
        cin >> arg;
        switch (arg)
        {
        case 1:
            /* work */
            break;

        case 2:
            cout
                << "输出二叉树的树形结构\n";
            break;
        case 3:
            cout << "测试:\n";
            test();
            break;
        case 0:
            cout << "感谢使用\n";
            break;
        default:
            cout << "无效的选项\n";
            break;
        }
    } while (arg);
}

node *nodeInit(node *left, node *right, char val)
{
    node *ret = (node *)malloc(sizeof(node));
    ret->left = left;
    ret->right = right;
    ret->val = val;
    return ret;
}

node *binaryTreeBuild(string &s, int *idx)
{
    if (*idx >= s.length())
        return NULL;
    char val = s[*idx];
    (*idx)++;
    if (val != '*')
    {
        node *ret = nodeInit(NULL, NULL, val);
        ret->left = binaryTreeBuild(s, idx);
        ret->right = binaryTreeBuild(s, idx);
        return ret;
    }
    return NULL;
}

void binaryTreeFree(node *root)
{
    if (!root)
        return;
    binaryTreeFree(root->left);
    binaryTreeFree(root->right);
    free(root);
}

void binaryTreePrint(node *root)
{
    int level = getBinaryTreeDepth(root), count = 0, curLevel = 1, levelSize = 1, sumSize = 1;
    int loc = 0;
    queue<node *> q;
    queue<int> qloc;
    q.push(root);
    while (curLevel <= level)
    {
        int dis = (1 << (level - curLevel));
        node *temp = q.front();
        q.pop();
        count++;
        cout << (temp == NULL ? ' ' : temp->val);
        if (!temp)
        {
            q.push((node *)NULL);
            q.push((node *)NULL);
            for (int i = 0; i < dis; i++)
                cout << " ";
            for (int i = 0; i < dis - 1; i++)
                cout << " ";
            loc += 2 * dis;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
            if (temp->left)
                qloc.push(loc);
            if (temp->right)
            {
                for (int i = 0; i < dis; i++)
                {
                    cout << "_";
                    loc++;
                }
                qloc.push(loc);
            }
            else
                for (int i = 0; i < dis; i++)
                {
                    cout << " ";
                    loc++;
                }
            for (int i = 0; i < dis - 1; i++)
                cout << " ";
        }
        if (count == sumSize)
        {
            levelSize *= 2;
            sumSize += levelSize;
            curLevel++;
            cout << '\n';
            loc = 0;
            int i = 0;
            while (!qloc.empty())
            {
                if (i == qloc.front())
                {
                    cout << "|";
                    qloc.pop();
                }
                else
                {
                    cout << " ";
                }
                i++;
            }
            cout << "\n";
        }
    }
}

int getBinaryTreeDepth(node *root)
{
    if (!root)
        return 0;
    return max(getBinaryTreeDepth(root->left), getBinaryTreeDepth(root->right)) + 1;
}

void test()
{
    string s = "abc**d**e**";
    int idx = 0;
    node *tree = binaryTreeBuild(s, &idx);
    binaryTreePrint(tree);
}
