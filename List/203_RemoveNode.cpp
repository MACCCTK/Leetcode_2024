class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* pos=dummy;
        while(pos->next!=nullptr){
            if(pos->next->val==val){
                ListNode* tmp =pos->next;
                pos->next = pos->next->next;
                delete tmp;
            }          
            else{
                pos = pos->next;
            }      
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
