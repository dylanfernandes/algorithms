/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        //single jumping pointer
        ListNode single = head;
        //double jumping pointer
        ListNode dbl = head;
        if(head == null)
            return false;
        while(true) {
            //don't check equality at start
            if(dbl != head) {
                
                if(nodeEquality(dbl, single))
                    return true;
            }
            if(dbl.next != null)
                dbl = dbl.next;
            else
                return false;
            
            if(nodeEquality(dbl, single))
                    return true;
            
            if(dbl.next != null)
                dbl = dbl.next;
            else
                return false;
            single = single.next;
        }
    }
    
    public boolean nodeEquality(ListNode a, ListNode b) {
        if(a == b)
            return true;
        return false;
    }
}