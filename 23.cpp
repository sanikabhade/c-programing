class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, 
                       vector<ListNode*>, 
                       Compare> pq;

        // Put first node of every list into heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to answer
            tail->next = smallest;
            tail = tail->next;

            // Add next node of same list
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};