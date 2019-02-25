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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 =l1;
        while(true){
        if(l1->val+l2->val>=10)
        {
            l1->val = (l1->val+l2->val)%10;
            if(l1->next==NULL)
            {
                l1->next = (ListNode*)malloc(sizeof(ListNode));
                l1->next->val =1;
                l1->next->next=NULL;
            }
            else
            {
                l1->next->val+=1;
            }
        }
        else
        {
            l1->val = l1->val+l2->val;
        }
            if(l1->next!=NULL||l2->next!=NULL)
            {
                if(l1->next==NULL)
                {
                    l1->next = (ListNode*)malloc(sizeof(ListNode));
                    l1->next->val=0;
                    l1->next->next=NULL;
                }
                if(l2->next==NULL)
                {
                    l2->next = (ListNode*)malloc(sizeof(ListNode));
                    l2->next->val=0;
                    l2->next->next=NULL;
                }
                l1=l1->next;
                l2=l2->next;
        }
            else{break;}

    }
         return l3;
    }
};
