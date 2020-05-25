class Solution {
public:
    long double kdutil(int i, int N, unordered_map<int, vector<int>> moves, map<pair<int,int>, long double>& dp){
    if(N==0) return 1;
    if(dp.find({i,N}) != dp.end()) return dp[{i,N}];
    vector<int> temp = moves[i];
    long double count = 0;
    for(int j = 0; j < temp.size(); j++){
        count += kdutil(temp[j],N-1,moves, dp);
    }
    dp[{i,N}] = count;
    return count;
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
    long double count = 0;
    map<pair<int,int>, long double> dp;
    for(int i = 0; i <= 9; i++){
        count += kdutil(i, N-1, moves, dp);
    }
    long double div = (pow(10,9)) + 7;
    return fmod(count, div);
}
};
