#define pii pair<int,int>
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

//******************************************************************************
        //Solution 1 : using Max Heap

        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<arr.size();i++){
            int distance= abs(arr[i]-x);
            int ele= arr[i];
            pq.push({distance,ele});
            
            if(pq.size()>k){
                pq.pop();  //pop vo hoga jiska distance maximum hoga
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

//Time Complexity: O(nlogn) 
//Space Complexity: O(n)

//******************************************************************************

//******************************************************************************
            //Solution 2: using min Heap

        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

//Time Complexity: O(nlogn) 
//Space Complexity: O(n)

//******************************************************************************

//******************************************************************************
        
       //Solution 3: Sliding window : shrink the window => variable size window
        
        int l=0,r=arr.size()-1;
        
        while(r-l>k-1){
            if(abs(arr[r]-x)<abs(arr[l]-x)) l++;
            else r--;
        }
        // vector<int> ans;
        // for(int i=l;i<=r;i++){
        //     ans.push_back(arr[i]);
        // }
        // return ans;
        
        return vector<int>(arr.begin()+l,arr.begin()+r+1);  //slicing 

//Time Complexity: O(n-k) 
//Space Complexity: O(1)

//******************************************************************************

//******************************************************************************

        
        //4th solution : Binary search
        
        int idx= lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int l= idx-1;
        int r= idx;
        int cnt=0;
        while(l>=0 and r<arr.size() and cnt<k){
            if(x-arr[l]<=arr[r]-x){
                l--;
                cnt++;
            }
            else {
                r++;
                cnt++;
            }
        }
        //if cnt is still less than k
        while(l>=0 and cnt<k){
            l--;
            cnt++;
        }
        while(r<arr.size() and cnt<k){
            r++;
            cnt++;
        }
      return vector<int>(arr.begin()+l+1,arr.begin()+r);  //edge case handle
    }
};

//Time Complexity: O(logn + k) 
//Space Complexity: O(1)

//******************************************************************************