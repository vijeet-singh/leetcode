class Solution {
public:
    
int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> bag(wordList.begin(), wordList.end());
    if(bag.find(endWord) == bag.end()) return 0;
    queue<string> q;
    q.push(beginWord);
    unordered_map<string,int> visited;                    //maintain haspmap for visited words, with their distances
    std::pair<string,int> p(beginWord,1);
    visited.insert(p);
    while(!q.empty()){
        string curr_word = q.front();
        for(int i = 0; i < curr_word.size(); i++){
            string temp(curr_word);
            for(int j = 97; j < 97+26; j++){
                char ab = (char)j;
                string ab_s(1,ab);
                string neigh = temp.replace(i,1,ab_s);
                if(bag.find(neigh) != bag.end() && visited.find(neigh) == visited.end()){
                    int curr_dist = visited[curr_word];
                    if(neigh == endWord) return curr_dist+1;
                    std::pair<string,int> tempair(neigh, curr_dist+1);
                    visited.insert(tempair);
                    q.push(neigh);
                }
            }
        }
        q.pop();
    }
    return 0;
}
    
};
