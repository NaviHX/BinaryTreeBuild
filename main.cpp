#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

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
                << "输入形如\"abc**d**e**\"的字符串\n"
                << "输出广义表表示的二叉树结构\n"
                << "广义表每一层有三个元素,第一个元素为当前的节点,第二第三分别为左右子树\n";
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
