 ListNode* AddNodesSorted(int val,ListNode *head)
    {

       if(head == NULL)
       {
           head = new ListNode(val);
           return head;
       }
        
        ListNode *tmp = head;
        ListNode *prev = head;
        
        while(tmp != NULL)
        {
            if(tmp->next == NULL)
            {
                if(tmp == head)
                {
                    if(val<=tmp->val)
                    {
                        ListNode *someNode = new ListNode(val);
                        someNode->next = head;
                        head = someNode;
                        return head;
                    }
                    
                    else
                    {
                         ListNode *someNode = new ListNode(val);
                         head->next = someNode;
                         return head;
                    }
                }
                
                else
                {
                    if(val <= tmp->val)
                    {
                        ListNode *someNode = new ListNode(val);
                        someNode->next = tmp;
                        prev->next = someNode;
                        return head;
                    }
                    
                    else
                    {
                        ListNode *someNode = new ListNode(val);
                        tmp->next = someNode;
                        return head;
                    }
                }
            }
            
            else if(val <= tmp->val)
            {
            ListNode *someNode = new ListNode(val);
            someNode->next = tmp;
            if(tmp == head)
            {
                head = someNode;
                return head;
            }
            prev->next = someNode;
            return head;
            }
            
            prev = tmp;
            tmp = tmp->next;
        }
        
        return head;
    }
