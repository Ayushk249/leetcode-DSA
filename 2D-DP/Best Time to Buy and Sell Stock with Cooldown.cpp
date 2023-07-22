// caching

class Solution {
public:
    int dfs(int i,bool buy_state,vector<int>& prices,map<pair<int,bool>,int>&m){
        if(i>= prices.size()){
            return 0;
        }

        if(m.find(make_pair(i,buy_state)) != m.end()){
            return m[make_pair(i,buy_state)];
        }

        // recursive call
        if(buy_state){
            int buy = dfs(i+1,!buy_state,prices,m) - prices[i];
            int cool = dfs(i+1, buy_state,prices,m);
            // profits gets maximized either by buying or leaving
            m[make_pair(i,buy_state)] = max(buy,cool);
        }else{
            int sell = dfs(i+2,!buy_state,prices,m) + prices[i];
            int cool = dfs(i+1,buy_state, prices, m);
            m[make_pair(i,buy_state)] = max(sell,cool);
        }

        return m[make_pair(i,buy_state)];
    }

    int maxProfit(vector<int>& prices) {
        // (index,buy_state) --> profit
        // if selling then i+2;
        // if buying then i+1;

        map<pair<int,bool>,int> m;

        return dfs(0,true,prices,m);
    }
};