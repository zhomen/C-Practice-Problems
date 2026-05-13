#pragma once

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* findMiddle(ListNode* head);
int hasCycle(ListNode* head);