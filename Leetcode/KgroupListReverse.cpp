class Solution {
    int length(ListNode* node) {
        if(!node) return 0;
        return length(node->next) + 1; 
    }
    vector<ListNode*> reversegroup(ListNode* node, ListNode* previous, int k) {
        vector<ListNode*> v;
        ListNode* store;
        ListNode* prev = previous;
        v.push_back(prev);
        ListNode* curr = node;
        ListNode* next = curr->next;
        while(k--) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
            if(k == 0) {
                v.push_back(prev);
            }
        }
        v.push_back(curr);
        return v;
    }
    
    ListNode* reverse(ListNode* node, int k, int length, bool first = true) {
        vector<ListNode*> t;
        ListNode* newhead;
        cout << "here ==" << endl;
        while(length / k >= 1) {
            if(first) {
                t = reversegroup(node, NULL,k);
                newhead = t[1];
                // cout << t[0]->val << " ----- ";
                cout << t[1]->val << " ----- ";
                cout << t[2]->val << " ----- ";
                first = !first;
            } else {
                t = reversegroup(t[2], t[0], k);
            }
            length -= k;
        }
        return newhead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        
        if(k > len || k == 1) {

            return head;
        }
        return reverse(head, k, len);
    }
};