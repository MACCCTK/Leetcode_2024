class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); 
        dummyHead->next = head; 
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* f = cur->next; 
            ListNode* s = cur->next->next;
            ListNode* t = cur->next->next->next; 

            cur->next = s;  
            s->next = f;         
            f->next = t;   

            cur = cur->next->next; 
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
