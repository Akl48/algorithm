#include <iostream>
#include <vector> // 容器类
#include <string> // sting类
#include <stack>  // 栈
#include <queue>  // 队列 优先级队列
#include <iomanip> // 格式化输出
#include <math.h>  // 数学公式 pow max
#include <time.h>  // 时间
#include <limits.h>
#include <set>
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};