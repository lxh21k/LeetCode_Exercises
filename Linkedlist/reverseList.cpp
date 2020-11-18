#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            ListNode* ret = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return ret;
        }
};

class Solution1 {
    public:
        ListNode* reverseList1(ListNode* head) {
            ListNode* cur = NULL, *pre = head;
            while (pre != NULL) {
                ListNode* t = pre->next;
                pre->next = cur;
                pre = t;
            }
            return cur;
        }
};
