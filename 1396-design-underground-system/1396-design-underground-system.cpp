class UndergroundSystem {
public:
   map<int,pair<string,int>>mp1;
   map<string,pair<double,int>>mp2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
      mp1[id] = {stationName,t};
        
    }
    
    void checkOut(int id, string stationName, int t) {
      auto it = mp1[id];
     
      string fromstation = it.first;
      int start = it.second;
      string fromto = fromstation + "-" + stationName;
      mp2[fromto].first =  mp2[fromto].first + (t-start);
      mp2[fromto].second = mp2[fromto].second+1;
    }
    
    double getAverageTime(string startStation, string endStation) {
      string temp = startStation + "-" + endStation;
      auto it = mp2[temp];
      double ans = it.first/it.second;
      return ans;
        
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */