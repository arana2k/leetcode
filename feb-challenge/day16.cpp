// DAY 16(24. Swap Nodes in Pairs)==========================================================================================


  ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 2 is new head, 1 is head
        ListNode* new_head = head->next;
        // store 3
        ListNode* third = head->next->next;
        // 2->1
        new_head->next = head;
        // 1->3
        head->next = swapPairs(third);
        
        return new_head;
    }
