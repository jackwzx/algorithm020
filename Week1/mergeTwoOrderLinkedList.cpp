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
        //1 新建临时节点fakeNode,新建tail节点，指向fakeNode
        //2 循环遍历p和q直到其中一个不为空，对p和q进行比较，调整tail->next指向p或者q，p或者q指向其下一个节点，
        //  每一次遍历后，移动tail使其指向fakeNode的最后的一个节点
        //3 循环结束后，让tail->next指向p或者q不为空的即可
        
        ListNode fakeNode(0);
        ListNode* tail = &fakeNode;

        while (p != NULL && q != NULL) {
            if (p->val > q->val) {
                tail->next = q;
                q = q->next;
            }
            else {
                tail->next = p;
                p = p->next;
            }
            tail = tail->next;
        }
        tail->next = p?p:q;

        return fakeNode.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
