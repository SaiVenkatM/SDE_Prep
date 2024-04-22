/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    //brute force
   /*int len = 0;
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len ++;
    }
    temp = head;
    int i = len/2 + 1;
    while( temp!=NULL){
         i = i-1;
         if (i == 0) {
           break;
         }
         temp = temp->next;
    }
    return temp;*/
    //better approach
    int i=0,j=0;
    int len = 0;
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* temp2 = head;
    while(temp != NULL){
        temp = temp->next;
        len ++;
    }
    temp = head;
    while(j < len-1){
        temp = temp->next;
        i+= 1;
        if (temp2->next!= NULL) {
            j += 2;
         //cout<<temp->next->next<<endl;
          temp2 = temp2->next->next;
          
        }
    }

    return temp;

   
}

