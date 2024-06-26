/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Brute Force

        /*unordered_map<ListNode*, int> myList;
        while(head != NULL){
            if(myList.find(head) != myList.end()) {
            return true;
        }
        myList[head] = 1;
        head = head->next;
        }
        return false;*/
        //better approach
        ListNode *temp1 = head;
        ListNode *temp2 = head;
        while(temp2 != NULL && temp2->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        
            if (temp1 == temp2){
                return true;
            }
        }
        return false;
    }
};