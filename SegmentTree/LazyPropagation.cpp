#define ll              long long
#define all(x)          (x).begin(), (x).end()

class SegmentTree{
        vector<ll> segTree, lazy;
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

        void lazy_update(int i, int low, int high, ll val, int l, int r){

            if(lazy[i] != 0){
                segTree[i] = max(segTree[i], lazy[i]);
                // segTree[i] = (high - low + 1) * lazy[i];
                if(low != high){
                    lazy[2 * i + 1] = lazy[i];
                    lazy[2 * i + 2] = lazy[i];
                }
                lazy[i] = 0;
            }

            if(low > r || high < l) return;

            if(low >= l && high <= r){
                segTree[i] = val;
                // segTree[i] = (high - low + 1) * val;
                if(low != high){
                    lazy[2 * i + 1] = val;
                    lazy[2 * i + 2] = val;
                }
                return;
            }
            int mid = (low + high) >> 1;
            lazy_update(2 * i + 1, low, mid, val, l, r);
            lazy_update(2 * i + 2, mid+1, high, val, l, r);
            // segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
            segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        }


        // sum in range l->r [l, r]
        // max in range l->r [l, r]
        ll lazy_rangeQuery(int i, int low, int high, int l, int r){
            if(lazy[i] != 0){
                // segTree[i] += (high - low + 1) * lazy[i];
                segTree[i] = max(segTree[i], lazy[i]);
                if(low != high){
                    lazy[2 * i + 1] = lazy[i];
                    lazy[2 * i + 2] = lazy[i];
                }
                lazy[i] = 0;
            }

            if(low >= l && high <= r) return segTree[i];
            // if(low > r || high < l) return 0ll;
            if(low > r || high < l) return LLONG_MIN;
            ll mid = (low + high) >> 1;
            ll left = lazy_rangeQuery(2 * i + 1, low, mid, l, r);
            ll right = lazy_rangeQuery(2 * i + 2, mid + 1, high, l, r);
            // return (left + right);  
            return max(left, right);
            //return max(rangeQuery(low, mid, l, r, 2*i+1), rangeQuery(mid + 1, high, l, r, 2*i+2));
        }


    public:
        SegmentTree(int n){
            this->n = n;
            segTree.resize(4*n);
            lazy.resize(4*n);
            fill(all(segTree), LLONG_MIN);
            fill(all(lazy), 0ll);
        }

        void build(vector<ll>& v){
            build(v, 0, n - 1, 0);
        }

        // l->r [l, r] 0-based indexing
        void lazy_update(int l, int r, ll val){
            lazy_update(0, 0, n - 1, val, l, r);
        }

        // l->r [l, r] 0-based indexing
        ll lazy_rangeQuery(int l, int r){
            return lazy_rangeQuery(0, 0, n - 1, l, r);
        }
};
