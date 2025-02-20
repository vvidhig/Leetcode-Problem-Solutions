class Solution{
public:
    int pageFaults(int N, int C, int pages[])
    {
       int pageFault = 0;
       unordered_set<int> memory;
       list<int> lru;
       for(int i = 0; i<N; i++)
       {
           int page = pages[i];
           if(memory.find(page)==memory.end())
           {
               pageFault++;
               if(memory.size()==C)
               {
                   int prevUsed = lru.back();
                   lru.pop_back();
                   memory.erase(prevUsed);
               }
           }
           else
           {
               lru.remove(page);
           }
           memory.insert(page);
           lru.push_front(page);
       }
       return pageFault;
    }
};
