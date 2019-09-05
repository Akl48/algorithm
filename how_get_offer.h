#include "config.h"

class _01_offer {
    /*
     * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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
     * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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
     * 输入一个链表，按链表从尾到头的顺序返回一个ArrayList.
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
    /*
     * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
     * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
     * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
     * 则重建二叉树并返回。
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
        if (length <= 0)
            return false;
        for (int i = 0 ; i < length ; i++ ) {
            while (numbers[i] != i)
            {
                int tmp = numbers[numbers[i]];
                if (tmp == numbers[i]) {
                    duplication[0] = tmp;
                    return true;
                }
                numbers[numbers[i]] = numbers[i];
                numbers[i] = tmp;
            }
        }
        return false;
    }
};

class _06_offer {
    /*
     * 输入n个整数，找出其中最小的K个数。
     * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
     */
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = (int)input.size();
        vector<int> output;
        if (len < k)
            return output;
        priority_queue<int, vector<int>, greater<int> > minQueue;
        for (int i = 0 ; i < len ; i++ ) {
            minQueue.push(input[i]);
        }
        while(k) {
            output.push_back(minQueue.top());
            minQueue.pop();
            k--;
        }
        return output;
    }
};

class _07_offer {
    /*
     * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
     * 例如6、8都是丑数，但14不是，因为它包含质因子7。
     * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
     */
    int GetUglyNumber_Solution(int index) {
        if(index < 7)  // 1~6都是丑树
            return index;
        int i = 0,j = 0, k = 0,newNum = 1;
        vector<int> array;
        array.push_back(newNum);
        while(array.size() < index) {
            newNum = min(2 * array[i],min(3 * array[j],5 * array[k]));
            array.push_back(newNum);
            if (newNum == 2 * array[i]) i++;
            if (newNum == 3 * array[j]) j++;
            if (newNum == 5 * array[k]) k++;
        }
        return array[array.size() - 1];
    }
};

class _08_offer {
    /*
     * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
     * 请写程序找出这两个只出现一次的数字。
     */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = (int)data.size();
        if (len <= 1) return;
        int lastNum = 0;
        for (int i = 0 ; i < len ; i++ ) {
            lastNum ^= data[i];
        }
        // 获得到最后两个数的^
        int count = 0;
        while((lastNum & 1) == 0) {
            count++;
            lastNum >>= 1;
        }
        for (int i = 0 ; i < len ; i++ ) {
            if ((data[i] >> count & 1) == 1) {
                num1[0] ^= data[i];
            } else {
                num2[0] ^= data[i];
            }
        }
        return ;
    }
};

class _09_offer {
    /*
     * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，
     * 使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
     */
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = (int)array.size();
        vector<int> res;
        if (len <= 1) return res;
        int left = 0 , right = len - 1;
        while (left < right) {
            if (array[left] + array[right] == sum) {
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            } else if (array[left] + array[right] > sum) {
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};

class _10_offer {
    /*
     * 请实现一个函数，用来判断一颗二叉树是不是对称的。
     * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
     */
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL) 
            return true;
        return comRoot(pRoot->left,pRoot->right);
    } 
    bool comRoot(TreeNode* left,TreeNode* right) {
        if (left == NULL) return (right == NULL);
        if (right == NULL ) return false;
        if (left->val == right->val) {
            return comRoot(left->left,right->right) && comRoot(left->right,right->left);
        } else {
            return false;
        }
    }  
};

class _11_offer {
    /* 
     * 给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1）
     * 每段绳子的长度记为k[0],k[1],...,k[m]。
     * 请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
     * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段
     * 此时得到的最大乘积是18。
     */
    int cutRope(int number) {

    }
};

class _12_offer {
    /*
     * 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留
     * 返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
     */
    ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == NULL) 
            return NULL;
        if (pHead != NULL && pHead->next == NULL)
            return pHead;
        
        ListNode *p;
        if ( pHead->val == pHead->next->val) {
            p = pHead->next->next;
            while (p != NULL && p->val == pHead->val) {
                p = p->next;
            }
            return deleteDuplication(p);
        } else {
            p = pHead->next;
            pHead->next = deleteDuplication(p);
            return pHead;
        }
    }
};

class _13_offer {
    /*
     * 输入两个链表，找出它们的第一个公共结点。
     */
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        int len1 = 1,len2 = 1;
        ListNode *node1 = pHead1;
        ListNode *node2 = pHead2;
        while (node1->next != NULL) {
            node1 = node1->next;
            len1++;
        }
        while (node2->next != NULL) {
            node2 = node2->next;
            len2++;
        }
        if (node2 != node1) {
            return NULL;
        }
        node1 = pHead1;
        node2 = pHead2;
        if (len1 > len2) {
            int k = len1 - len2;
            while(k) {
                node1 = node1->next;
                k--;
            }
        } else {
            int k = len2 - len1;
            while(k) {
                node2 = node2->next;
                k--;
            }
        }
        while(node1) {
            if (node1 == node2) {
                break;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1;
    }
};
