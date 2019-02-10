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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
     int size = lists.size();
        ListNode *head = NULL;
        vector<int> numbers;
        
        for(auto curList : lists)
        {
            while(curList != NULL)
            {
                numbers.push_back(curList->val);
                curList = curList->next;
            }
        }
        sort(numbers.begin(),numbers.end());
        head = AddNumbers(numbers);
        return head;
    }
    
    ListNode* AddNumbers(vector<int> numbers)
    {
        if(numbers.size() == NULL)
            return NULL;
        
        ListNode *head = NULL;
        ListNode *tmp;
        
        for(auto it : numbers)
        {
            if(head == NULL)
            {
                head = new ListNode(it);
                tmp = head;
            }
            
            else
            {
                tmp->next = new ListNode(it);
                tmp = tmp->next;
            }
        }
        
        return head;
    }
    
};
