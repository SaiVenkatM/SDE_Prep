/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute Force
        /*ListNode* temp = head;
        int len = 0;
        int i= 0;
        while(temp!=NULL){
            len += 1;
            temp = temp->next;
        }
        temp = head;
        if(len == 1 && n ==1){
            head = NULL;
            return head;
        }
        if(i+n ==len){
            head = head->next;
            return head;
        }
        while(temp!=NULL){
            if (i + n >= len-1) break; 
            //cout<<temp->val<<endl;
            temp = temp->next;
            i +=1;
        }
        if(temp->next!=NULL) temp->next = temp->next->next;
        return head;*/
        //Better Approach

        ListNode* temp = head;
        ListNode* fast = head;
        int i= 0;
      
        while(i<n){
            fast = fast->next; 
            i++;   
        }
        if(fast == NULL){
            return head->next;
        }
        while(fast->next !=NULL){
            fast = fast->next;
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
        
    }
};