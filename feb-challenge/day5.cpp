// DAY 5 (23. Merge k Sorted Lists)=============================================================================

// APPROACH 1 (Using Priority Queue) --> O(n*log(k))

struct comp
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    for (int i = 0; i < lists.size(); i++)
        if (lists[i])
            pq.push(lists[i]);

    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();
        ListNode *nxt = node->next;
        if (nxt)
            pq.push(nxt);

        itr->next = node;
        itr = itr->next;
    }

    return ans->next;
}

// APPROACH 2 (DIVIDE)

// METHOD 1 (Brute Force) --> O(n*k) [n -> total nodes]

ListNode *merge2lists(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            itr->next = l1;
            l1 = l1->next;
        }
        else
        {
            itr->next = l2;
            l2 = l2->next;
        }
        itr = itr->next;
    }
    itr->next = l1 ? l1 : l2;
    return ans->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    ListNode *ans = new ListNode(INT_MIN);
    for (int i = 0; i < lists.size(); i++)
        ans = merge2lists(ans, lists[i]);

    return ans->next;
}

// METHOD 2 (Divide and Conquer) --> O(n*logn(k)) [n -> total nodes] [O(1) space]

ListNode *merge2lists(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(INT_MIN), *itr = ans;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            itr->next = l1;
            l1 = l1->next;
        }
        else
        {
            itr->next = l2;
            l2 = l2->next;
        }
        itr = itr->next;
    }
    itr->next = l1 ? l1 : l2;
    return ans->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
        return nullptr;

    for (int i = 1; i < lists.size(); i *= 2)
        for (int j = 0; i + j < lists.size(); j += (i * 2))
            lists[j] = merge2lists(lists[j], lists[i + j]);

    return lists[0];
}
