/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode creationListPtr;
        ListNode mergeListPtr;
        ListNode referenceNode;
        
        if(list1 == null)
            return list2;
        
        if(list2 == null)
            return list1;
        
        if(list1.val < list2.val) {
            creationListPtr = list1;
            mergeListPtr = list2;
        } else {
            creationListPtr = list2;
            mergeListPtr = list1;
        }
        
        referenceNode = creationListPtr;
        
        while(mergeListPtr != null) {
            ListNode peakCreationPtr = creationListPtr.next;
            if(peakCreationPtr != null) {
                while(peakCreationPtr.val < mergeListPtr.val) {
                    creationListPtr = creationListPtr.next;
                    peakCreationPtr = creationListPtr.next;
                    if(peakCreationPtr == null)
                        break;
                }
            }
            
            insertNode(creationListPtr, mergeListPtr.val);
            mergeListPtr = mergeListPtr.next;
            creationListPtr = creationListPtr.next;
        }
        return referenceNode;
    }
    
    public void insertNode(ListNode list, int val){
        ListNode nextNode = list.next;
        list.next = new ListNode(val, nextNode);
    }
}