class Solution {
public:
   bool ispalindromes(string s){
    if (s == string(s.rbegin(), s.rend())) return true;
    return false;
}

bool ispalindromei(int n){
    return(ispalindromes(std::to_string(n)));
}

bool isprime(int n){
    if(n == 2 || n ==3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    if(n%6 == 1 || n%6==5) {
        for(int i=1; 6*i-1 <=sqrt(n); i++){
            if(n%(6*i-1) == 0 || n%(6*i+1) == 0) return false;
        }
    }
    return true;
}

int nextpalin(int n){
    if(n<9) return n+1;
    int nd = log10(n) + 1;
    int root = n/pow(10,(nd)/2);
    if(log10(n+1) == nd) return n+2;
    if(nd%2 == 0){
        string sroot = std::to_string(root);
        string tail(sroot);
        std::reverse(tail.begin(), tail.end());
        string club = sroot+tail;
        if(stoi(club) > n) return stoi(club);
        else{
            root++;
            string sroot = std::to_string(root);
        string tail(sroot);
        std::reverse(tail.begin(), tail.end());
        string club = sroot+tail;
            return stoi(club);
        }
    }
    else{
        int ippx = root/10;
        string sppx = std::to_string(ippx);
        string ssfx(sppx);
            std::reverse(ssfx.begin(), ssfx.end());
        //int isfx = stoi(ssfx);
        
        string sroot = std::to_string(root);
        string club = sroot + ssfx;
        if(stoi(club) > n) return stoi(club);
        else{
            root++;
            string sroot = std::to_string(root);
            int ippx = root/10;
        string sppx = std::to_string(ippx);
        string ssfx(sppx);
            std::reverse(ssfx.begin(), ssfx.end());
            return stoi(sroot + ssfx);
        }
    }
}

int primePalindrome(int N) {
    if(N==1 || N==0) return 2;
    if(ispalindromei(N) && isprime(N)) return N;
    while(!(isprime(N) && ispalindromei(N) )){
        N = nextpalin(N);
    }
    return N;
}

        
};
