struct Job
{
    int id;
    int deadline;
    int profit;
    Job(int id, int deadline, int profit) : id(id), deadline(deadline), profit(profit)
    {};
};

class Solution {
  public:
    static bool Jobcompare(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) 
    {
        vector<Job> jobs;
        int n = id.size();
        for(int i = 0; i<n; i++)
        {
            jobs.push_back(Job(id[i], deadline[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end(), Jobcompare);
        int maxi = jobs[0].deadline;
        for(int i = 1; i<n; i++)
        {
            maxi = max(maxi, jobs[i].deadline);
        }
        vector<int> slot(maxi+1, -1);
        int cntjobs = 0, maxprofit = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = jobs[i].deadline; j>0; j--)
            {
                if(slot[j]==-1)
                {
                    slot[j] = i;
                    cntjobs++;
                    maxprofit+=jobs[i].profit;
                    break;
                }
            }
        }
        vector<int> res = {cntjobs, maxprofit};
        return res;
    }
};
