// prefix function for this string is defined as an array pi of length n, 
// where pi[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring

#define ll     long long
#define sz(x)  (ll)(x).size()

void LPS(string &pattern, vector<ll>& lps){
    int m = sz(pattern);
    lps[0] = 0;
    int j = 0, i = 1;
    while(i < m){
        while(j > 0 && pattern[j] != pattern[i]) j = lps[j - 1];
        if(pattern[i] == pattern[j]) lps[i] = j + 1, j++;
        else lps[i] = 0;
        i++; 
    }
}

vector<int> kmp(string &pattern, string &text){
    int n = sz(text), m = sz(pattern);
    vector<ll> lps(m + 1, 0);
    LPS(pattern, lps);
    int i = 0, j = 0, occurenceCount = 0;
    vector<int> occurences;
    while(i < n){
        if(pattern[j] == text[i]){
            i++; j++; 
            if(j == m){
                occurences.push_back(i - m);
                occurenceCount++; j = lps[j - 1];
            }
            continue;
        }
        if(j == 0) i++;
        else while(j > 0 && pattern[j] != text[i]) j = lps[j - 1];
    }
    return occurences;
}
