# 详细设计

node *nodeInit(node *left, node *right, char val)  
得到并初始化一个节点
```c++
node *nodeInit(node *left, node *right, char val)
{
    node *ret = (node *)malloc(sizeof(node));
    //节点赋值
    return ret;
}
```

node *binaryTreeBuild(string &s, int *idx)  
递归建立二叉树  
```c++
node *binaryTreeBuild(string &s, int *idx)
{
    //字符串越界需要提前结束

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
```

void binaryTreeFree(node *root);  
释放二叉树
```c++
void binaryTreeFree(node *root)
{
    if (!root)
        return;
    binaryTreeFree(root->left);
    binaryTreeFree(root->right);
    free(root);
}
```

int getBinaryTreeDepth(node *root)  
获得二叉树深度
```c++
int getBinaryTreeDepth(node *root)
{
    if (!root)
        return 0;
    return max(getBinaryTreeDepth(root->left), getBinaryTreeDepth(root->right)) + 1;
}
```

void binaryTreePrint(node *root)  
层序遍历打印二叉树
```c++
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
        }
        else
        {
            //压入子节点
            //输出节点
            if(有右节点)
                //输出向右的连线
        }
        if (count == sumSize)
        {
            //该层节点输出完毕
            //处理向下的连线
        }
    }
}
```
