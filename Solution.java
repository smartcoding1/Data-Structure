class Solution {
    public int maxProductDifference(int[] nums) 
    {
        
        int n = nums.length;
 
        // One by one move boundary of unsorted subarray
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min_idx = i;
            for (int j = i+1; j < n; j++)
                if (nums[j] < nums[min_idx])
                    min_idx = j;
 
            // Swap the found minimum element with the first
            // element
            int temp = nums[min_idx];
            nums[min_idx] = nums[i];
            nums[i] = temp;
        }
    
      
      int  max_diff=(nums[n-1]*nums[n-2])-(nums[0]*nums[1]);
        return max_diff;
    } 

    
}
