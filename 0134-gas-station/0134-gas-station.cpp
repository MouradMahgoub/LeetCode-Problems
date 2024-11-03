class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasSum=0, costSum=0;
        for(int i : gas) gasSum += i;
        for(int i : cost) costSum += i;
        if(costSum > gasSum) return -1;
        int total = 0, indx = 0;
        for(int i=0; i<gas.size(); i++)
            if((total += gas[i] - cost[i]) < 0)
                total = 0, indx = i+1;
        return indx;
    }
};