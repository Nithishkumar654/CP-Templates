#pragma once
#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE

// ============================================================
// Contest mode: all debugging completely disabled
// ============================================================

#define dbg(...)  do {} while (0)
#define dbgv(...) do {} while (0)
#define dbgr(...) do {} while (0)
#define dbgi(...) do {} while (0)
#define dbgt(...) do {} while (0)
#define dbga(...) do {} while (0)
#define dbgl(...) do {} while (0)

#else

namespace dbg_detail {

  template <class T>
  using clean_t = remove_cvref_t<T>;

  // ============================================================
  // Traits
  // ============================================================

  template <class T>
  struct is_pair : false_type {};

  template <class A, class B>
  struct is_pair<pair<A, B>> : true_type {};


  template <class T>
  struct is_tuple : false_type {};

  template <class... Ts>
  struct is_tuple<tuple<Ts...>> : true_type {};


  template <class T>
  struct is_queue : false_type {};

  template <class T, class C>
  struct is_queue<queue<T, C>> : true_type {};


  template <class T>
  struct is_stack : false_type {};

  template <class T, class C>
  struct is_stack<stack<T, C>> : true_type {};


  template <class T>
  struct is_pq : false_type {};

  template <class T, class C, class Comp>
  struct is_pq<priority_queue<T, C, Comp>> : true_type {};


  template <class T, class = void>
  struct is_iterable : false_type {};

  template <class T>
  struct is_iterable<T, void_t<
    decltype(begin(declval<T>())),
    decltype(end(declval<T>()))
    >> : true_type {};


  template <class T, class = void>
  struct is_streamable : false_type {};

  template <class T>
  struct is_streamable<T, void_t<
    decltype(cerr << declval<T>())
    >> : true_type {};


  // ============================================================
  // SINGLE printer implementation
  // ============================================================

  template <class T>
  void print(const T& x) {

    using U = clean_t<T>;

    // string
    if constexpr (is_same_v<U, string>) {
      cerr << x;
    }

    // string_view
    else if constexpr (is_same_v<U, string_view>) {
      cerr << x;
    }

    // C-string
    else if constexpr (
      is_pointer_v<U> &&
      is_same_v<remove_cv_t<remove_pointer_t<U>>, char>
      ) {
      cerr << x;
    }

    // char array / string literal
    else if constexpr (
      is_array_v<U> &&
      is_same_v<remove_extent_t<U>, char>
      ) {
      cerr << x;
    }

    // pair
    else if constexpr (is_pair<U>::value) {
      cerr << '(';
      print(x.first);
      cerr << ", ";
      print(x.second);
      cerr << ')';
    }

    // tuple
    else if constexpr (is_tuple<U>::value) {

      cerr << '(';

      size_t cnt = 0;

      apply([&](const auto&... v) {
        (
          (
            (cnt++ ? cerr << ", " : cerr),
            print(v)
            ),
          ...
          );
        }, x);

      cerr << ')';
    }

    // queue
    else if constexpr (is_queue<U>::value) {

      auto q = x;

      cerr << "queue[";

      bool first = true;

      while (!q.empty()) {
        if (!first) cerr << ", ";
        first = false;

        print(q.front());
        q.pop();
      }

      cerr << ']';
    }

    // stack
    else if constexpr (is_stack<U>::value) {

      auto st = x;

      cerr << "stack[";

      bool first = true;

      while (!st.empty()) {
        if (!first) cerr << ", ";
        first = false;

        print(st.top());
        st.pop();
      }

      cerr << ']';
    }

    // priority queue
    else if constexpr (is_pq<U>::value) {

      auto pq = x;

      cerr << "pq[";

      bool first = true;

      while (!pq.empty()) {
        if (!first) cerr << ", ";
        first = false;

        print(pq.top());
        pq.pop();
      }

      cerr << ']';
    }

    // iterable containers
    else if constexpr (
      is_iterable<U>::value &&
      !is_same_v<U, string> &&
      !is_same_v<U, string_view>
      ) {

      cerr << '[';

      bool first = true;

      for (const auto& v : x) {
        if (!first) cerr << ", ";
        first = false;

        print(v);
      }

      cerr << ']';
    }

    // everything streamable
    else if constexpr (is_streamable<U>::value) {
      cerr << x;
    }

    // unsupported
    else {
      cerr << "<unprintable>";
    }
  }


  // ============================================================
  // Names
  // ============================================================

  inline vector<string> split_names(const string& s) {

    vector<string> res;

    int depth = 0;
    bool single = false;
    bool dbl = false;

    size_t start = 0;

    for (size_t i = 0; i < s.size(); ++i) {

      char c = s[i];

      if (c == '\'' && !dbl)
        single = !single;

      else if (c == '"' && !single)
        dbl = !dbl;

      if (single || dbl)
        continue;

      if (c == '(' || c == '[' || c == '{')
        ++depth;

      else if (c == ')' || c == ']' || c == '}')
        --depth;

      else if (c == ',' && depth == 0) {
        res.push_back(s.substr(start, i - start));
        start = i + 1;
      }
    }

    res.push_back(s.substr(start));

    for (auto& x : res) {
      size_t l = 0, r = x.size();

      while (l < r && isspace((unsigned char)x[l]))
        ++l;

      while (r > l && isspace((unsigned char)x[r - 1]))
        --r;

      x = x.substr(l, r - l);
    }

    return res;
  }


  // ============================================================
  // Named printing
  // ============================================================

  template <class T>
  void print_named(const string& name, const T& value) {

    string label = name;

    // "answer =" style
    if (label.size() >= 2 &&
      label.front() == '"' &&
      label.back() == '"') {

      label = label.substr(1, label.size() - 2);

      if (!label.empty() && label.back() == '=') {
        cerr << label << ' ';
        print(value);
      }
      else {
        cerr << label;
      }

      return;
    }

    cerr << label << " = ";
    print(value);
  }


  // ============================================================
  // Multiple arguments
  // ============================================================

  template <class T>
  void print_args(
    const vector<string>& names,
    size_t idx,
    const T& value
  ) {
    print_named(names[idx], value);
  }


  template <class T, class... Rest>
  void print_args(
    const vector<string>& names,
    size_t idx,
    const T& value,
    const Rest&... rest
  ) {
    print_named(names[idx], value);

    cerr << " | ";

    print_args(
      names,
      idx + 1,
      rest...
    );
  }


  // ============================================================
  // Raw values
  // ============================================================

  template <class T>
  void print_values(const T& x) {
    print(x);
  }

  template <class T, class... Rest>
  void print_values(const T& x, const Rest&... rest) {
    print(x);
    cerr << ' ';
    print_values(rest...);
  }

  // ============================================================
// Timer
// ============================================================

  class Timer {
    string name;
    chrono::steady_clock::time_point start;

  public:
    explicit Timer(string name)
      : name(std::move(name)),
      start(chrono::steady_clock::now()) {
    }

    ~Timer() {
      auto finish = chrono::steady_clock::now();

      auto us = chrono::duration_cast<
        chrono::microseconds
      >(finish - start).count();

      cerr << "[TIME] "
        << name
        << " = "
        << us
        << " us\n";
    }
  };
} // namespace dbg_detail

// ============================================================
// Main debugger
// ============================================================

#define dbg(...) do {                                      \
    cerr << "[DBG] ";                                      \
    auto _dbg_names =                                      \
        dbg_detail::split_names(#__VA_ARGS__);             \
    dbg_detail::print_args(                                \
        _dbg_names, 0, __VA_ARGS__                         \
    );                                                     \
    cerr << '\n';                                          \
} while (0)


// ============================================================
// Raw values
// ============================================================

#define dbgv(...) do {                                     \
    cerr << "[DBG] ";                                      \
    dbg_detail::print_values(__VA_ARGS__);                 \
    cerr << '\n';                                          \
} while (0)


// ============================================================
// Range
//
// Works with vector/array/string/etc. supporting operator[]
// ============================================================

#define dbgr(v, l, r) do {                                 \
    cerr << "[DBG] " << #v                                 \
         << "[" << #l << ".." << #r << "] = [";            \
                                                           \
    for (int _i = (l); _i <= (r); ++_i) {                  \
        if (_i != (l)) cerr << ", ";                       \
        dbg_detail::print((v)[_i]);                        \
    }                                                       \
                                                           \
    cerr << "]\n";                                          \
} while (0)


// ============================================================
// Indexed container
// ============================================================

#define dbgi(v) do {                                       \
    cerr << "[DBG] " << #v << ":\n";                       \
                                                           \
    for (size_t _i = 0;                                 \
         _i < (v).size();                                \
         ++_i) {                                           \
                                                           \
        cerr << "  [" << _i << "] = ";                     \
        dbg_detail::print((v)[_i]);                        \
        cerr << '\n';                                      \
    }                                                       \
} while (0)


// ============================================================
// Timer
//
// Usage:
// {
//     dbgt(dijkstra);
//     ...
// }
// ============================================================

#define dbgt(name)                                         \
    dbg_detail::Timer _dbg_timer_##__LINE__(#name)


// ============================================================
// Assertion
// ============================================================

#define dbga(cond) do {                                    \
    if (!(cond)) {                                         \
        cerr << "[ASSERT] " << #cond                       \
             << " failed at " << __FILE__                  \
             << ':' << __LINE__ << '\n';                   \
    }                                                       \
} while (0)


// ============================================================
// Debug with source location
// ============================================================

#define dbgl(...) do {                                     \
    cerr << "[DBG " << __FILE__ << ':' << __LINE__ << "] ";\
    auto _dbg_names =                                      \
        dbg_detail::split_names(#__VA_ARGS__);             \
    dbg_detail::print_args(                                \
        _dbg_names, 0, __VA_ARGS__                         \
    );                                                      \
    cerr << '\n';                                          \
} while (0)

#endif