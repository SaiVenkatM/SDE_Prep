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
   ListNode* merge(ListNode* left, ListNode* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    ListNode* result;
    if (left->val <= right->val) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Function to find the middle node of the linked list.
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge Sort function for linked list.
ListNode* mergeSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // Find the middle of the list.
    ListNode* middle = findMiddle(head);
    ListNode* nextToMiddle = middle->next;

    // Split the list into two halves.
    middle->next = nullptr;

    // Recursively sort the two halves.
    ListNode* leftHalf = mergeSort(head);
    ListNode* rightHalf = mergeSort(nextToMiddle);

    // Merge the sorted halves.
    return merge(leftHalf, rightHalf);
}
    ListNode* sortList(ListNode* head) {
        //Brute Force
        /*ListNode* temp = head;

        int value;
        bool swapped = true;
        while(swapped){
            swapped = false;
            temp = head;
            while (temp && temp->next){
                if (temp->val > temp->next->val){
                    value = temp->val;
                    temp->val = temp->next->val;
                    temp->next->val = value;
                    swapped = true;
                }
                temp = temp -> next;
            }
        }
    return head;*/
    //Better Approach
    return(mergeSort(head));
    
    }
};