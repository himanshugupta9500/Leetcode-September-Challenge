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
    
//*************************************
        //Method 1

        int length=0;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            length++;
            temp=temp->next;  //forward 
        }
        
        int to_be_deleted=length-n; //length - n +1 =4         
        temp=head;
        
        ListNode* prev=NULL;
        
        while(to_be_deleted){
            prev=temp;
            temp=temp->next;
            to_be_deleted--;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next= temp->next;  //or prev->next= prev->next->next;
        
        return head;
//************************************
        
//**********************************
        //Method 2
        
        ListNode* prev=NULL;
        ListNode* ram= head;
        ListNode* harry= head;
        
        for(int i=1;i<n;i++){
            harry=harry->next;
        }
        while(harry->next!=NULL)
        {
            prev=ram;
            ram=ram->next;
            harry=harry->next;
        }
        if(prev==NULL){
            return head->next;
        }
        prev->next=prev->next->next;
        return head;
//**********************************    
        
//**********************************
        //Method 3
       // dummy node
        
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* slow= dummy;
        ListNode* fast=dummy;
        
        for(int i=1;i<=n;i++){
            fast=fast->next;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next= slow->next->next;
        return dummy->next;
    }
//***********************************
};

//Time Complexity: O(N)
//Space Complexity: O(N)