class Solution {
public:
    string pushDominoes(string dom) {
        int n= dom.size();
        
        vector<int> prev_right(n,INT_MAX),prev_left(n,INT_MAX);
        
        int distance=0;
        int flag=0;   //there is no "R" occured till now 
        
        for(int i=0;i<n;i++){
            if(dom[i]=='R'){
                flag=1;
                prev_right[i]=0;
                distance=1;
            }
            if(dom[i]=='L') //break
            {
                flag=0;
                distance=0;
            }
            if(flag and dom[i]=='.'){
                prev_right[i]=distance;
                distance++;
            }
        }
        
        distance=0;
        flag=0;  //there is no "L" occured till now
        
        for(int i=n-1;i>=0;i--){
              if(dom[i]=='L'){
                flag=1;
                prev_left[i]=0;
                distance=1;
            }
            if(dom[i]=='R') //break
            {
                flag=0;
                distance=0;
            }
            if(flag and dom[i]=='.'){
                prev_left[i]=distance;
                distance++;
            }
        }
        
        string ans;
        
        for(int i=0;i<n;i++){
            
            if(prev_right[i]==INT_MAX and prev_left[i]==INT_MAX) ans+=".";
            else if(prev_right[i]==INT_MAX) ans+="L";
            else if(prev_left[i]==INT_MAX) ans+="R";
            else if(prev_right[i]==prev_left[i]) ans+="."; //force balanced
            else if(prev_right[i]<prev_left[i]) ans+="R";
            else ans+="L";
        }
        return ans;
    }
};

//Time complexity: O(N)
//Space Complexity: O(N)