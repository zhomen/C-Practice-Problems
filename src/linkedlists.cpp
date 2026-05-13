#include "linkedlists.hpp"

/// @brief Reverses a singly linked list.
/// @param head Pointer to the head of the list.
/// @return Pointer to the new head of the reversed list.
ListNode *reverseList(ListNode* head) {
    if(!head) return nullptr;

    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/// @brief Merges one singly linked list onto the end of another.
/// @param l1 Pointer to the first list.
/// @param l2 Pointer to the second list.
/// @return Pointer to the merged list.
ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2) return nullptr;
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode* dummy = l1;

    while(dummy->next){
        dummy = dummy->next;
    }
    dummy->next = l2;
    return l1;
}

/// @brief Finds the middle node of a singly linked list.
/// @param head Pointer to the head of the list.
/// @return Pointer to the middle node.
ListNode *findMiddle(ListNode* head) {
    if (!head) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/// @brief Determines if a singly linked list has a cycle.
/// A cycle occurs when a node's next pointer points to a previous node in the list, creating a loop (Floyd's Algorithm).
/// @param head Pointer to the head of the list.
/// @return 1 if the list has a cycle, 0 otherwise.
int hasCycle(ListNode* head) {
    if (!head) return 0;

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1; // Cycle detected
    }
    return 0; // No cycle
}