class NumberContainers {
public:
    unordered_map<int,int> nums;
    unordered_map<int,set<int>> indexMap;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (nums.count(index))   indexMap[nums[index]].erase(index);
        nums[index] = number;
        indexMap[number].insert(index);
    }
    
    int find(int number) {
        return indexMap[number].empty()?-1 : *indexMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */