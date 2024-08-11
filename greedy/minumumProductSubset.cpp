#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minProSubset(vector<int> &v){
    int cn = 0,cz = 0,cp = 0;
    int ans = 1;
    int posprod = 1;
    int negprod = 1;
    int mn = INT_MIN;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            cn++;
            negprod*=v[i];
            mn= max(mn,v[i]);
        }
        if(v[i]==0)cz++;
        if(v[i]>0){
            cp++;
            posprod*=v[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it = min_element(v.begin(),v.end()); // ye hamara minimum element ka addressfind kar dega
            return *it;
        }
    }
    else{
        if(cz>0) return 0;
        if(cn%2==0){//even no of negative
            negprod/=mn;
            return ans = posprod*negprod;
        }
        else{
            ans = (posprod*negprod);
        }
        
    }
    return ans;
    

}
int main(){
    vector<int> v = {0,-2,-3,4,5};
    int result = minProSubset(v);
    cout<<result<<endl;
}