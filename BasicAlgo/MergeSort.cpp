#define ll    long long
#define vi    vector<ll>
#define mod   1000000007

ll merge(vi &v, int l, int mid, int r){
    int i = l, j = mid + 1, k = 0;
    ll inv = 0;
    vi t(r - l + 1);
    while(i <= mid && j <= r){
        if(v[i] <= v[j]){
            t[k++] = v[i++];
        }else{
            t[k++] = v[j++];
            inv += (mid - i + 1);
            inv %= mod;
        }
    }

    while(i <= mid) t[k++] = v[i++];
    while(j <= r) t[k++] = v[j++];

    for(int i = l; i <= r; i++){
        v[i] = t[i - l];
    }
    return inv;
}

ll mergeSort(vi &v, int l, int r){
    ll inv = 0;
    if(l < r){
        int mid = (l + r) >> 1;
        inv += mergeSort(v, l, mid);
        inv %= mod;
        inv += mergeSort(v, mid + 1, r);
        inv %= mod;
        inv += merge(v, l, mid, r);
        inv %= mod;
    }
    return inv;
}
