#define ll              long long
#define all(x)          (x).begin(), (x).end()

class SegmentTree{
        vector<ll> segTree;
        int n;
        // building segment tree
        void build(vector<ll>& v, int l, int h, int i){
            if(l == h){
                segTree[i] = v[l];
                return;
            }
            int mid = (l + h) >> 1;
            build(v, l, mid, 2 * i + 1);
            build(v, mid + 1, h, 2 * i + 2);
            // segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        }

        // updating (or) increasing value at index idx in the array with val 
        void update(int i, int l, int h, ll val, int idx){
            if(l == h){
                //segTree[i] += val; // increasing by val
                segTree[i] = val; // replacing  by val
                return;
            }
            int mid = (l + h) >> 1;
            if(idx <= mid) update(2 * i + 1, l, mid, val, idx);
            else update(2 * i + 2, mid + 1, h, val, idx);
            // segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        }

        // sum in range l->r [l, r]
        // max in range l->r [l, r]
        ll rangeQuery(int i, int low, int high, int l, int r){
            if(low >= l && high <= r) return segTree[i];
          
            // if(low > r || high < l) return 0LL; 
            if(low > r || high < l) return LLONG_MIN;
            int mid = (low + high) >> 1;
            ll left = rangeQuery(2 * i + 1, low, mid, l, r);
            ll right = rangeQuery(2 * i + 2, mid + 1, high, l, r);
            // return (left + right);  
            return max(left, right);
        }

    public:
        SegmentTree(int n){
            this->n = n;
            segTree.resize(4 * n);
            fill(all(segTree), LLONG_MIN);
        }

        void build(vector<ll>& v){
            build(v, 0, n - 1, 0);
        }

        // idx -> 0 based indexing
        void update(int idx, ll val){
            update(0, 0, n - 1, val, idx);
        }
        // l->r [l, r] 0-based indexing
        ll rangeQuery(int l, int r){
            return rangeQuery(0, 0, n - 1, l, r);
        }
};
