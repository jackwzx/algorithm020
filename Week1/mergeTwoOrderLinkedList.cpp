//
//  main.cpp
//  mergeTwoOrderLinkedList
//
//  Created by jackwangliang on 2020/11/21.
//  Copyright © 2020 jackwangliang. All rights reserved.
//

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        //1 新建一个链表mergeList
        //2 p和q，分别指向两个链表的首个节点进行比较，curentMinNode指向p和q中最小的节点，并且p或者q向后移动指向next
        //3 重复步骤2，直到p或者q其中一个为空，每一次循环，都会找到curentMinNode，循环结束后curentMinNode指向curentMinNode->next
        //4 循环结束后，让curentMinNode->next指向p或者q不为空的即可
        
        if (p == NULL) {
            return q;
        }
        if (q == NULL) {
            return p;
        }
        
        ListNode* mergeListNode = NULL;
        
        if (p->val < q->val) {
            mergeListNode = p;
            p = p->next;
        }
        else {
            mergeListNode = q;
            q = q->next;
        }
        ListNode* curentMinNode = mergeListNode;
        
        while (p != NULL && q != NULL) {
            if (p->val > q->val) {
                curentMinNode->next = q;
                q = q->next;
            }
            else {
                curentMinNode->next = p;
                p = p->next;
            }
            curentMinNode = curentMinNode->next;
        }
        curentMinNode->next = (p == NULL ? q:p);
        
        return mergeListNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
