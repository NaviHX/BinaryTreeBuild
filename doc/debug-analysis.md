# 调试分析报告

## 调试过程中遇到的问题

输出空格时用于标记向下连线位置的loc变量没有改变,导致树形结构混乱
```c++
@@ -137,7 +149,11 @@ void binaryTreePrint(node *root)
                     loc++;
                 }
             for (int i = 0; i < dis - 1; i++)
             {
                 cout << " ";
+                loc++;
             }
+            loc++;
         }
```

## 设计回顾

时空分析

设n为节点数,h为树高度

|function|T(n)|S(n)|
|-|-|-|
|binaryTreeBuild|O(n)|O(h)|
|binaryTreeFree|O(n)|O(h)|
|binaryTreePrint|O(2^l)|O(2^(h-1))|
|getBinaryTreeDepth|O(n)|O(h)|

优化思路

将每一层的节点放在其子节点连线的中间,是输出的树形结构更加清晰
