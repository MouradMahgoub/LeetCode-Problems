class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for(int i=0; i<n; i++){
            jobs[i][0] = startTime[i]; 
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[0]));
        int[] memo = new int[n+1];
        for(int i=0; i<n+1; i++)
            memo[i] = -1;
        return foo(0, jobs, memo);
    }

    private int foo (int i, int[][] jobs, int[] memo) {
        if(i == jobs.length) return 0;
        if(memo[i] != -1) return memo[i];
        int notTaken = foo(i+1, jobs, memo);
        int firstValidJobIndex = bs(jobs[i][1],  jobs);
        int taken = jobs[i][2] + foo(firstValidJobIndex, jobs, memo);
        return memo[i] = Math.max(notTaken, taken);
    }

    private int bs (int e, int[][] jobs) {
        int l=0, r=jobs.length;
        while(l < r){
            int mid = l + (r-l)/2;
            int startTime = jobs[mid][0];
            if(startTime >= e)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
}
        // List<int[]> dp = new ArrayList<>();
        // dp.add(new int[] {0, 0});
        // for(int[] job : jobs) {
        //     int s = job[0], e = job[1], p = job[2];
        //     int lastPrevJobIndex = bs (dp, s);
        //     int taken = p + dp.get(lastPrevJobIndex)[1];
        //     int notTaken = dp.get(dp.size()-1)[1];
        //     if(taken > notTaken)
        //         dp.add(new int[] {e, taken});
        // }
        // return dp.get(dp.size() -1)[1];
    // private int bs (List<int[]> dp, int s) {
    //     int l=0, r=dp.size()-1;
    //     while(l < r){
    //         int mid = l + (r-l+1)/2;
    //         int endTime = dp.get(mid)[0];
    //         if(endTime <= s)
    //             l = mid;
    //         else
    //             r = mid-1;
    //     }
    //     return l;
    // }