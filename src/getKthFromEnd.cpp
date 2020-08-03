class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* p_front = head;
        ListNode* p_back = head;
        for(int i=0; i<k-1; i++) {
            p_front = p_front->next;
            if(!p_front) return NULL;
        }
        while(p_front->next!=NULL){
            p_back=p_back->next;
            p_front=p_front->next;
        }
        return p_back;
        
    }
};
