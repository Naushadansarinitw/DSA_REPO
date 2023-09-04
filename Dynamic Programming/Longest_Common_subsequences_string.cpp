
int f(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
    if(i< 0 || j< 0 ) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == s[j]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);

    return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
}

int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, s, t);
}


// 2 method tabulation 

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++){
            if(s[i-1] == s[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }
 
   return  dp[n][m];


   // so if we want string then need tabulation 

   int len = dp[n][m];
   string ans = "";
   for(int i=0; i<len; i++) ans += '$';

   int index = len -1;
   int i=n, j=m;
   while(i>0 && j>0) {
    if(s[i-1] == t[j-1]) {
        ans[index] = s[i-1];
        index--;
        i--,j--;
    }
    else if(dp[i-1][j] > dp[i][j-1]) i--;
    else j--;
   }

   return str;