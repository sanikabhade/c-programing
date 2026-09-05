class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Nodes to swap
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to next pair
            prev = first;
        }

        return dummy->next;
    }
};