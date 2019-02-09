// Still in progress


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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
     int size = lists.size();
        ListNode *head = NULL;
        
        for(auto curList : lists)
        {
            while(!curList)
            {
                head = AddNodesSorted(curList->val,head);
                curList = curList->next;
            }
        }
        
        return head;
    }
    
    ListNode* AddNodesSorted(int val,ListNode *head)
    {
       if(head == NULL)
       {
           head = new ListNode(val);
           cout<<"Head is NULL";
           return head;
       }
        
        ListNode *tmp = head;
        
        while(!tmp)
        {
            if(!tmp->next) 
            {
                if(val <= tmp->val)
                {
                    ListNode *someNode = new ListNode(val);
                    someNode->next = tmp;
                    head = tmp;
                    return head;
                }
                
                else
                {
                    ListNode *someNode = new ListNode(val);
                    tmp->next = someNode;
                    return head;
                }
            }
            
            else if(val <= tmp->val)
            {
                ListNode *someNode = new ListNode(val);
                someNode->next = tmp;
                head = tmp;
                return head;
            }
            
            else
            {
                if(val <= tmp->next->val)
                {
                    ListNode *someNode = new ListNode(val);
                    someNode->next = tmp->next;
                    tmp->next = someNode;
                    return head;
                }
                
                else
                {
                    tmp = tmp->next;
                }
            }             
        }
        
        return head;
    }
};
