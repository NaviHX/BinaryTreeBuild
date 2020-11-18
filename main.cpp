#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

typedef struct BinaryTreeNode //二叉树节点
{
    struct BinaryTreeNode *left;  //左子节点
    struct BinaryTreeNode *right; //右子节点
    char val;                     //权值
} node;

node *nodeInit(node *left, node *right, char val); //得到并初始化一个节点
node *binaryTreeBuild(string &s, int *idx);        //递归建立二叉树
void binaryTreeFree(node *root);                   //释放二叉树
void binaryTreePrint(node *root);                  //打印二叉树
int getBinaryTreeDepth(node *root);                //获得二叉树深度
void test();
void testPrint(node *root);

int main()
{
    int arg;
    string s;
    node *root = NULL;
    int idx = 0;
    cout
        << "可以选择的功能选项:\n"
        << "1.输入先序遍历序列转二叉树\n"
        << "2.查看帮助,了解输入输出格式\n"
        << "0.退出程序\n";
    do
    {
        cout << "\n请输入功能选项:";
        idx = 0;
        root = NULL;
        cin >> arg;
        switch (arg)
        {
        case 1:
            cout << "请输入二叉树的先序序列:";
            cin >> s;
            root = binaryTreeBuild(s, &idx);
            binaryTreePrint(root);
            binaryTreeFree(root);
            break;

        case 2:
            cout
                << "输出二叉树的树形结构\n"
                << "节点正下面的连线表示左子节点,右下方的连线表示右子节点\n"
                << "e.g. : 输入abc**d**e**\n"
                << "       输出:\n"
                << "       a____\n"
                << "       |   |\n"
                << "       b__ e\n"
                << "       | |  \n"
                << "       c d  \n";
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
    queue<node *> q; //层序遍历队列
    queue<int> qloc; //计算每个节点应该打印的位置
    q.push(root);
    while (curLevel <= level)
    {
        int dis = (1 << (level - curLevel)); //计算间隔
        node *temp = q.front();
        q.pop();
        count++;
        cout << (temp == NULL ? ' ' : temp->val);
        if (!temp) //空节点
        {
            //添加两个空子节点
            //相应位置输出空格
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
            //压入左右子节点
            q.push(temp->left);
            q.push(temp->right);
            if (temp->left)
            {
                qloc.push(loc);
            }
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
            {
                cout << " ";
                loc++;
            }
            loc++;
        }
        if (count == sumSize)
        {
            //处理向下的连线
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
    string s = "abc***d*e**";
    int idx = 0;
    node *tree = binaryTreeBuild(s, &idx);
    binaryTreePrint(tree);
}
