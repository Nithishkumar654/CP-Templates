#define ll     long long
#define pii    pair<ll, ll>
#define vi     vector<ll>
#define sz(x)  (ll)(x).size()

pii lowerbound(int x, vi &v){
    // vector v is pre-sorted
    int l = 0, h = sz(v) - 1;
    while(l < h){
        int mid = (l + h) >> 1;
        if(v[mid] < x) l = mid + 1;
        else h = mid;
    }
    if(v[h] < x) return {INT_MAX, sz(v)};
    return {v[h], h}; // or return {v[l], l};
}

pii upperbound(int x, vi &v){
    // vector v is pre-sorted
    int l = 0, h = sz(v) - 1;
    while(l < h){
        int mid = (l + h) >> 1;
        if(v[mid] <= x) l = mid + 1;    
        else h = mid;
    }
    if(v[h] <= x) return {INT_MAX, sz(v)};
    return {v[h], h};  // or return {v[l], l};
}

pii floor(int x, vi &a){
    //vector a is pre-sorted
    if(x < a[0]) return {INT_MIN, -1};
    int l = 0, h = sz(a) - 1;
    while(l < h){
        int mid = (l + h + 1) >> 1;
        if(a[mid] > x){
            h = mid - 1;
        }else{
            l = mid;
        }
    }
    return {a[l], l}; // or return {a[h], h};
}
