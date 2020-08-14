package javahelloworld;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;;

class Solution {
    public int longestAwesome(String s) {
        HashMap<Integer,Integer> map=new HashMap<>();
        int cur=0;  
        int ans=1;  
        map.put(cur,-1); 
        for(int c=0;c<s.length();c++){
            int ch=s.charAt(c)-'0';
            cur=cur^(1<<ch);
            for(int i=0;i<10;i++){
                int next=cur^(1<<i);
                if(map.containsKey(next)){
                    ans=Math.max(ans,c-map.get(next));
                }
            }
            if(!map.containsKey(cur)){
                map.put(cur,c);
            }else{
                ans=Math.max(ans,c-map.get(cur));
            }
        }
        return ans;
    }
}

class Solution1 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n==0) return;
        if(m==0){
            for(int k=0; k<n; k++){
                nums1[k]=nums2[k];
            }
            return;
        }
        int i = m-1;
        int j = n-1;
        for(int k = m+n-1; k>=0; k--){
        	if(nums1[i] > nums2[j]){
        		nums1[k]=nums1[i];
        		i--;
        	}
        	else {
        		nums1[k]=nums2[j];
        		j--;
        	}
        	if(j<0){
        		break;
        	}
        	else if(i<0){
        		for(int j0 = 0; j0<=j; j0++){
        			nums1[j0] = nums2[j0];
        		}
        		break;
        	}
        }
    }
    
}	


class ListNode {
     int val;
     ListNode next;
     ListNode(int x) {
         val = x;
         next = null;
     }
}

class Solution2 {
   public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
       HashSet<ListNode> mySet = new HashSet<>();
	   while(headA != null){
		   mySet.add(headA);
		   headA = headA.next;
	   }
	   while(headB !=null && !mySet.contains(headB)){
		   headB = headB.next;
	   }
       return headB;
   }
}

class Solution3 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    	if(l1==null) return l2;
    	if(l2==null) return l1;
    	ListNode ans = new ListNode(0);
        ListNode ans0 = ans;
    	while(l1!=null && l2!=null){
    		if(l1.val < l2.val){
    			ans.next = l1;
    			l1 = l1.next;
    			ans = ans.next;
    		}
    		else {
    			ans.next = l2;
    			l2=l2.next;
    			ans = ans.next;
    		}
    		if(l1==null){
    			ans.next = l2;
    			break;
    		}
    		if (l2==null){
    			ans.next = l1;
    			break;
    		}
    	}
    	
    	return ans0.next;
    }
}

public class helloworld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String test = "3242415";
		Solution solve = new Solution();
		int ans = solve.longestAwesome(test);
        System.out.println(ans);
        
        int[] arr1 = {4,0,0,0,0,0};
        int[] arr2 = {1,2,3,5,6};
        Solution1 solve1 = new Solution1();
        solve1.merge(arr1, 1, arr2, 5);
        System.out.println(Arrays.toString(arr1));
	}

}
