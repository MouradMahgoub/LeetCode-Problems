class NumberContainers {
public:
    unordered_map<int, set<int>> indexesOfNum;
    unordered_map<int, int> numAtIndex;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(numAtIndex.find(index) != numAtIndex.end()){
            indexesOfNum[numAtIndex[index]].erase(index);
            if(indexesOfNum[numAtIndex[index]].size() == 0)
                indexesOfNum.erase(numAtIndex[index]);
        }
        numAtIndex[index] = number;
        indexesOfNum[number].insert(index);
    }
    
    int find(int number) {
        return indexesOfNum.find(number) == indexesOfNum.end() ? -1 : *indexesOfNum[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */