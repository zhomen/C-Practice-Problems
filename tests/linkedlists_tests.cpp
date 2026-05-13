#include <gtest/gtest.h>
#include <iostream>
#include "linkedlists.hpp"

TEST(LinkedListsTest, ReverseList) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* reversed = reverseList(head);
    ASSERT_EQ(reversed->val, 3);
    ASSERT_EQ(reversed->next->val, 2);
    ASSERT_EQ(reversed->next->next->val, 1);
    ASSERT_EQ(reversed->next->next->next, nullptr);
}

TEST(LinkedListsTest, MergeTwoLists) {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(4);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(6);

    ListNode* merged = mergeTwoLists(l1, l2);
    ASSERT_EQ(merged->val, 1);
    ASSERT_EQ(merged->next->val, 2);
    ASSERT_EQ(merged->next->next->val, 3);
    ASSERT_EQ(merged->next->next->next->val, 4);
    ASSERT_EQ(merged->next->next->next->next->val, 5);
    ASSERT_EQ(merged->next->next->next->next->next->val, 6);
    ASSERT_EQ(merged->next->next->next->next->next->next, nullptr);
}

TEST(LinkedListsTest, FindMiddle) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* middle = findMiddle(head);
    ASSERT_EQ(middle->val, 3);
    ASSERT_EQ(middle->next->val, 4);
    ASSERT_EQ(middle->next->next->val, 5);
}

TEST(LinkedListsTest, HasCycle) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Create a cycle

    ASSERT_EQ(hasCycle(head), 1);

    ListNode* acyclicHead = new ListNode(1);
    acyclicHead->next = new ListNode(2);
    acyclicHead->next->next = new ListNode(3);

    ASSERT_EQ(hasCycle(acyclicHead), 0);
}
