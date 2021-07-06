class Solution {
    public int[] runningSum(int[] nums) 
    {
        int size=nums.length;
        int [] x= new int[size];
        int sum=0;
        for(int i=0;i<nums.length;i++)
        {
            sum+=nums[i];
            x[i]=sum;
        }
        
        return x;
    }
}
