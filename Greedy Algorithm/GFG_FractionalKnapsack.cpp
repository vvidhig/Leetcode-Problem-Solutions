class Solution {
  private:
    priority_queue<pair<double, int>> maxHeap;
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        double ans = 0.0;
        int n = val.size();
        for(int i = 0; i<n; i+=1)
        {
            double valwtratio = (double)val[i]/(double)wt[i];
            maxHeap.push({valwtratio, i});
        }
        while(!maxHeap.empty())
        {
            int idx = maxHeap.top().second;
            int value = val[idx];
            int weight = wt[idx];
            maxHeap.pop();
            
            if(weight<= capacity)
            {
                ans += value;
                capacity -= weight;
            }
            else if(weight>capacity && capacity>0)
            {
                double fraction = (double)capacity/(double)weight;
                ans += (value*fraction);
                capacity = 0;
                break;
            }
        }
        return ans;
    }
};
