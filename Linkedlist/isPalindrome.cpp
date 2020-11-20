#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (head == NULL) return true;

            ListNode* firstHalfEnd = end0FirstHalf(head);
            ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

            ListNode* p1 = head;
            ListNode* p2 = secondHalfStart;
            bool result = true;
            while (result && p2 != NULL) {
                if (p1->val != p2->val) {
                    result = false;
                }
                p1 = p1->next;
                p2 = p2->next;
            }

            firstHalfEnd->next = reverseList(secondHalfStart);
            return result;
        }

        ListNode* reverseList(ListNode* head) {
            ListNode* cur = NULL, *pre = head;
            while (pre != NULL) {
                ListNode* t = pre->next;
                pre->next = cur;
                cur = pre;
                pre = t;

            }
            return cur;
        }

        ListNode* end0FirstHalf(ListNode* head) {
            ListNode* fast = head;
            ListNode* slow = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }
            
};  
