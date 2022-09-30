class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

//**************************************************************
        //1st Method : Using priority queue

        //1.input ko alag-alag

        vector<pair<int,int>> coord;

        for(auto i:buildings){
            coord.push_back({i[0],-i[2]}); //start x coordinate
            coord.push_back({i[1],i[2]});  //end x coordinate
        }
        //2. sort

        sort(coord.begin(),coord.end());

        //3. priority_queue -> maxheap

        priority_queue<int> pq;

        //4.traverse karna hai coordinated (coord) array


   vector<vector<int>> ans;
   int prev_height=0;

        for(int i=0;i<coord.size();i++){
            int x = coord[i].first;
            int height= coord[i].second;

            if(height<0){
                pq.push(-height);
            }
            else{
                vector<int> temp;

                while(!pq.empty() and pq.top()!=height){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                pq.pop();

               for(auto i:temp){
                   pq.push(i);
               }

            }
            //height reaches to zero
            if(pq.empty()){
                    ans.push_back({x,0});
            }
            else{
                //only height changes
                if(prev_height!=pq.top()){
                    ans.push_back({x,pq.top()});
                    prev_height=pq.top();
                }
            }
        }
         return ans;

//Time Complexity: O(n^2logn)
//Space Compleity: O(n)

//**************************************************************

//**************************************************************
 
 `          //2.solution using multiset

 int prev_height=0;
 vector<vector<int>> ans;
 multiset<int> st;

 for(auto i:coord){
     int x= i.first;
     int height= i.second;

     if(height<0){
            st.insert(-height);
            }
    else {
        st.erase(st.find(height));
    }

    int curr_height= (st.empty()? 0: *(--st.end()));

    if(prev_height!=curr_height){
        ans.push_back({x,curr_height});
        prev_height=curr_height;
    }
  

 }
//  return res;
  return ans;
    }
};

//Time Complexity: O(nlogn)
//Space Complexity: O(n)

//**************************************************************