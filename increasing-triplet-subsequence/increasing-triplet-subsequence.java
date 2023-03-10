class Solution {
    public boolean increasingTriplet(int[] nums) {
        int firstMinimum = Integer.MAX_VALUE, secondMinimum = Integer.MAX_VALUE;
        for(int x : nums) {
            if(x <= firstMinimum) firstMinimum = x;
            else if(x <= secondMinimum) secondMinimum = x;
            else return true;
        }
        
        return false;
    }
}