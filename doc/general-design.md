# 概要设计

## 功能思路

根据先序遍历的顺序递归建树,并同时计算树的高度.建树完毕后,根据每一层的深度确定结点间的间隔,并输出.  

## 数据结构类型定义

```c++
typedef struct BinaryTreeNode //二叉树节点
{
    struct BinaryTreeNode *left;  //左子节点
    struct BinaryTreeNode *right; //右子节点
    char val;                     //权值
} node;
```

## 主程序流程

```c++
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
        case 0:
            cout << "感谢使用\n";
            break;
        default:
            cout << "无效的选项\n";
            break;
        }
    } while (arg);
}

```

## 函数调用关系

main()调用binaryTreeBuild(),binaryTreePrint(root),binaryTreeFree(root). binaryTreeBuild()为递归过程. binaryTreePrint(root)调用getBinaryTreeDepth()
