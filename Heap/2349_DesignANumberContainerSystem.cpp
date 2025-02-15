class NumberContainers {
private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIdx;
    unordered_map<int, int> idxToNumber;

public:
    NumberContainers() {}
    void change(int index, int number) 
    {
        idxToNumber[index] = number;
        numberToIdx[number].push(index);
    }
    int find(int number) {
        if (numberToIdx.find(number) == numberToIdx.end()) 
        {
            return -1;
        }
        auto& pq = numberToIdx[number];
        while (!pq.empty()) 
        {
            int idx = pq.top();
            if (idxToNumber[idx] == number) 
            {
                return idx;
            }
            pq.pop();
        }
        numberToIdx.erase(number);
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
