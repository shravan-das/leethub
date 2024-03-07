class ParkingSystem {
public:
    map<string,int>mp;
    ParkingSystem(int big, int medium, int small) {
      string b = "big";
      string m = "medium";
      string s = "small";
      mp[b] = big;
      mp[m] = medium;
      mp[s] = small;
      
        
    }
    
    bool addCar(int carType) {
      string temp;
      if(carType==3){
        temp = "small";
      }
      else if(carType==2){
        temp = "medium";
      }
      else{
        temp = "big";
      }
      if(mp[temp]==0){
        return false;
      }
      mp[temp] = mp[temp]-1;
      return true;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */