class StockPrice {
public:
    map<int, int> priceAt;
    map<int, int> countOf;

    StockPrice() {
        
    }
    
    void update(int timestamp, int newPrice) {
        int oldPrice = priceAt[timestamp];
        priceAt[timestamp] = newPrice;
        countOf[oldPrice]--;
        countOf[newPrice]++;
        if(countOf[oldPrice] <= 0) countOf.erase(oldPrice);
    }
    
    int current() {
        return priceAt.rbegin()->second;
    }
    
    int maximum() {
        return countOf.rbegin()->first;
    }
    
    int minimum() {
        return countOf.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */