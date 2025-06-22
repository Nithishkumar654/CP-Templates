#define ll int64_t
const int block_size = 600;

struct Query {
  int l, r, idx;
  bool operator<(Query other) const {
      return make_pair(l / block_size, r) <
             make_pair(other.l / block_size, other.r);
  }
};

// 

void add(int idx) {
  // add index operation
}

void rem(int idx) {
  // remove index operation
}

ll get_answer() {
  
}

ll answers[Queries.size()];
int cur_l = 0;
int cur_r = -1;
// invariant: data structure will always reflect the range [cur_l, cur_r]
for (Query q : Queries) {
  while (cur_l > q.l) {
    cur_l--;
    add(cur_l);
  }
  while (cur_r < q.r) {
    cur_r++;
    add(cur_r);
  }
  while (cur_l < q.l) {
    rem(cur_l);
    cur_l++;
  }
  while (cur_r > q.r) {
    rem(cur_r);
    cur_r--;
  }
  answers[q.idx] = get_answer();
}
