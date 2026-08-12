class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
                       greater<ListNode*>> pq;

        for (ListNode* node : lists) {
            if (node != nullptr)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr)
                pq.push(node->next);
        }

        return dummy.next;
    }
};