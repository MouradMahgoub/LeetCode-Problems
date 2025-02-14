class ProductOfNumbers {
public:
    vector<int> prfx;
    ProductOfNumbers() {
        prfx.push_back(1);
    }
    
    void add(int num) {
        if(num)
            prfx.push_back(prfx.back()*num);        
        else
            prfx = {1};
    }
    
    int getProduct(int k) {
        return k < prfx.size() ? prfx.back()/prfx[prfx.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */