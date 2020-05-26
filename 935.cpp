class Solution {
public:
    int kdutil(int i, int N, unordered_map<int, vector<int>> moves, map<pair<int,int>, int >& dp){
    if(N==0) return 1;
    if(dp.find({i,N}) != dp.end()) return dp[{i,N}];
    vector<int> temp = moves[i];
    int count = 0;
    int div = (pow(10,9)) + 7;
    for(int j = 0; j < temp.size(); j++){
        count = (count + kdutil(temp[j],N-1,moves, dp)) % div;
    }
    dp[{i,N}] = count % div;
    return count % div;
}

int knightDialer(int N){
    unordered_map<int, vector<int>> moves;
    moves[0] = {4,6};
    moves[1] = {6,8};
    moves[2] = {7,9};
    moves[3] = {4,8};
    moves[4] = {0,3,9};
    moves[5] = {};
    moves[6] = {0,1,7};
    moves[7] = {2,6};
    moves[8] = {1,3};
    moves[9] = {2,4};
    int count = 0;
    int div = (pow(10,9)) + 7;
    map<pair<int,int>, int> dp;
    for(int i = 0; i <= 9; i++){
        count = (count + kdutil(i, N-1, moves, dp)) % div;
    }
    
    return (count % div);
}
};
