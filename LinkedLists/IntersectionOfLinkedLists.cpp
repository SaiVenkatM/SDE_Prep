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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Brute Force
        /*unordered_map<ListNode*, int> myList;
        while(headA || headB){
            if( headA && myList[headA] == 1){
                return headA;
            }
            else if(headB && myList[headB] == 1){
                return headB;
            }
            if(headA){
                    myList[headA] = 1;
                    headA = headA->next;
                }
                if(headB) {
                if (myList[headB] == 1){
                    return headB;
                }else{
                    myList[headB] = 1;
                }
                headB = headB->next;
                }
            
        }
        return NULL;*/
        int len1 = 0;
        int len2 = 0;
        ListNode* tempA= headA;
        ListNode* tempB = headB;
        while(tempA){
            len1++;
            tempA = tempA->next;
        }
        while(tempB){
            len2++;
            tempB = tempB->next;
        }
        int diff = abs(len1-len2);
        tempA = headA;
        tempB = headB;
        if (len1 > len2){
            for(int i=0; i<diff; i++){
                tempA = tempA->next;
            }
        }
        else if(len1 < len2){
            for(int i=0; i<diff; i++){
                tempB = tempB->next;
            }
        }
        while(tempA || tempB){
            if (tempA == tempB){
                return tempA;
            }
            tempA= tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};