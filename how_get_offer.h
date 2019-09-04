#include "config.h"

class _01_offer {
    /*
    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
    */
    bool Find(int target, vector<vector<int> > array) {
        int len1 = array.size();
        if (len1 <= 0) return false;
        int len2 = array[0].size();
        if (len2 <= 0) return false;
        int i = 0 , j = len2 - 1;
        while (i <= len1 - 1 && j >= 0) {
            if (array[i][j] == target) {
                return true;
            } else if (array[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};

class _02_offer {
    /*
    请实现一个函数，将一个字符串中的每个空格替换成“%20”。
    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
    */
    void replaceSpace(char *str,int length) {
        if (length <= 0) return;
        int oldLenght = 0 , newLenght = 0;
        while (str[oldLenght] != '\0') {
            if (str[oldLenght++] == ' ') {
                newLenght+=3;
            } else {
                newLenght++;
            }
        }
        while (oldLenght >= 0 && newLenght > oldLenght) {
            if (str[oldLenght] == ' ') {
                str[newLenght--] = '0';
                str[newLenght--] = '2';
                str[newLenght--] = '%';
            } else {
                str[newLenght--] = str[oldLenght];
            }
            oldLenght--;
        }
	}
};

class _03_offer {
    /*
    输入一个链表，按链表从尾到头的顺序返回一个ArrayList.
    */
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> ListValStack;
        ListNode *p = head;
        while (p != NULL) {
            ListValStack.push(p->val);
            p = p->next;
        }
        vector<int> tailToHead;
        while (!ListValStack.empty())
        {
            tailToHead.push_back(ListValStack.top());
            ListValStack.pop();
        }
        return tailToHead;
    }
};

class _04_offer {
    /*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
    则重建二叉树并返回。
    */
   TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
       int len1 = pre.size() , len2 = vin.size();
       return reConstructBinaryTree(pre, 0 , len1 - 1,vin , 0 , len2 - 1);
   }
   TreeNode* reConstructBinaryTree(vector<int> pre,int pLeft,int pRight,vector<int> vin,int vLeft,int vRight) {
       if (pLeft > pRight || vLeft > vRight) return NULL;
       int res = pre[pLeft];
       TreeNode *root = new TreeNode(res);
       int i; // 从i开始遍历
       for ( i = vLeft ; i <= vRight ; i++ ) {
           if (res == vin[i]) {
               break;
           }
       }
       int len = i - vLeft;
       root->left = reConstructBinaryTree(pre, pLeft + 1, pLeft + len , vin, vLeft, i - 1);
       root->right = reConstructBinaryTree(pre, pLeft + len + 1, pRight , vin, i + 1, vRight);
       return root;
   }
};
class _05_offer {
    /*
        在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
        数组中某些数字是重复的，但不知道有几个数字是重复的。
        也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
        例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
    */
    bool duplicate(int numbers[], int length, int* duplication) {
        
    }
};