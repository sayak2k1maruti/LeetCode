class NumberContainers {
public:
    unordered_map<int,int> nums;
    unordered_map<int,set<int>> indexMap;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int oldNumber=nums[index];
        nums[index] = number;
        if(oldNumber && indexMap.find(oldNumber) != indexMap.end()){
            indexMap[oldNumber].erase(index);
        }
        if(indexMap.find(number) != indexMap.end()) indexMap[number].insert(index);
        else {indexMap[number] = {index};}
    }
    
    int find(int number) {
        if(indexMap.count(number)) return indexMap[number].empty()?-1 : *indexMap[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */