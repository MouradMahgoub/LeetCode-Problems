class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i=0; i<n; i++){
            jobs[i][0] = startTime[i]; 
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[1]));
        List<int[]> dp = new ArrayList<>();
        dp.add(new int[] {0, 0});
        for(int[] job : jobs) {
            int s = job[0], e = job[1], p = job[2];
            int lastPrevJobIndex = foo (dp, s);
            int taken = p + dp.get(lastPrevJobIndex)[1];
            int notTaken = dp.get(dp.size()-1)[1];
            if(taken > notTaken)
                dp.add(new int[] {e, taken});
        }
        return dp.get(dp.size() -1)[1];
    }

    private int foo (List<int[]> dp, int s) {
        int l=0, r=dp.size()-1;
        while(l < r){
            int mid = l + (r-l+1)/2;
            int endTime = dp.get(mid)[0];
            if(endTime <= s)
                l = mid;
            else
                r = mid-1;
        }
        return l;
    }
}