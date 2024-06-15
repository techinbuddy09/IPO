class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //STORING THE SIZE OF THE ARRAY
        int n=profits.size();
        //now a vector to stor the pair of profit and capital
        //inorder to create a pair of two vectors
        //vector<pair<int,int>>(nameof vector)
        vector<pair<int,int>>pair(n);//length passing
       // now a loop to iteate over to create the pairs of(capital,profit
        for(int i=0;i<n;i++)
        {
            pair[i]={capital[i],profits[i]};// making their pairs
        }
        // now sorting the array of capital for w
        sort(pair.begin(),pair.end());// by default sort functions sorts the first array only
         int read=0;// for reading in this pair vector for every pair
        
        // now a max heap for outputting the max profit
        priority_queue<int>pro;
        // now we will run our work till k(project)=0
        while(k--)
        {
            // condition when we can purchase the property
            while(read<n &&pair[read].first<=w) // here checking with first element which is capital
            {
                pro.push(pair[read].second) ;// means here push back the the second elemnt which is holding profit
                    read++;// incrementing read 
                
            }
            // if priority_queue only empty
            if(pro.empty()) // empty function
            {
                break;
            }
            w+=pro.top();// adding the top ma
            pro.pop();// everytime adding to the last
        }
        return w;// finally returning the max capital
    }
};
