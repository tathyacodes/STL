# C++ STL Complete Reference

A practical reference for the **C++ Standard Template Library (STL)**
covering containers, iterators, algorithms, utilities, strings, ranges,
and the important differences between similar functions.

> **Scope:** This is a learning/reference README rather than a dump of
> every overload in the standard library. Function families and their
> important overload behavior are grouped together so the file stays
> usable.

------------------------------------------------------------------------

## Table of Contents

1.  [STL at a Glance](#stl-at-a-glance)
2.  [Containers](#containers)
    -   [Sequence Containers](#sequence-containers)
    -   [Associative Containers](#associative-containers)
    -   [Unordered Containers](#unordered-containers)
    -   [Container Adaptors](#container-adaptors)
    -   [`array`](#array)
    -   [`bitset`](#bitset)
3.  [Container Operations](#container-operations)
4.  [Iterators](#iterators)
5.  [Algorithms](#algorithms)
    -   [Searching](#searching)
    -   [Sorting](#sorting)
    -   [Binary Search](#binary-search)
    -   [Min/Max](#minmax)
    -   [Modification](#modification)
    -   [Set Algorithms](#set-algorithms)
    -   [Heap Algorithms](#heap-algorithms)
    -   [Numeric Algorithms](#numeric-algorithms)
    -   [Permutation Algorithms](#permutation-algorithms)
6.  [Strings and Character Utilities](#strings-and-character-utilities)
7.  [Pairs, Tuples and Structured
    Data](#pairs-tuples-and-structured-data)
8.  [Functions, Lambdas and Function
    Objects](#functions-lambdas-and-function-objects)
9.  [Smart Pointers](#smart-pointers)
10. [Useful STL Types](#useful-stl-types)
11. [C++20/23 Ranges](#c2023-ranges)
12. [Complexity Cheat Sheet](#complexity-cheat-sheet)
13. [Similar Functions --- Important
    Differences](#similar-functions--important-differences)
14. [Common STL Loopholes / Pitfalls](#common-stl-loopholes--pitfalls)
15. [Common Competitive-Programming
    Patterns](#common-competitive-programming-patterns)
16. [Quick Decision Guide](#quick-decision-guide)

------------------------------------------------------------------------

# STL at a Glance

The STL is primarily built around four ideas:

  -----------------------------------------------------------------------
  Part                    Purpose                 Examples
  ----------------------- ----------------------- -----------------------
  Containers              Store data              `vector`, `set`, `map`

  Iterators               Navigate through        `begin`, `end`, `next`
                          containers              

  Algorithms              Process data            `sort`, `find`,
                                                  `reverse`

  Function objects /      Tell algorithms what to `greater<int>()`,
  lambdas                 do                      `[](int x){...}`
  -----------------------------------------------------------------------

Typical STL usage:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {5, 2, 4, 1, 3};

    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << ' ';
}
```

For production code, prefer the specific standard headers instead of
`bits/stdc++.h` when portability matters.

------------------------------------------------------------------------

# Containers

## Container Classification

``` text
STL Containers
│
├── Sequence
│   ├── vector
│   ├── deque
│   ├── list
│   ├── forward_list
│   └── array
│
├── Associative (ordered)
│   ├── set
│   ├── multiset
│   ├── map
│   └── multimap
│
├── Unordered (hash-based)
│   ├── unordered_set
│   ├── unordered_multiset
│   ├── unordered_map
│   └── unordered_multimap
│
└── Adaptors
    ├── stack
    ├── queue
    └── priority_queue
```

------------------------------------------------------------------------

# Sequence Containers

## `vector`

Dynamic contiguous array.

``` cpp
vector<int> v;

v.push_back(10);
v.emplace_back(20);

v.pop_back();

v[0];
v.at(0);

v.front();
v.back();

v.size();
v.empty();

v.clear();
v.resize(10);
v.reserve(100);
v.capacity();
```

### Important properties

-   Contiguous memory.
-   Random access: `O(1)`.
-   `push_back`: amortized `O(1)`.
-   Insert/erase in the middle: `O(n)`.
-   Reallocation can invalidate iterators/references/pointers.

### `reserve()` vs `resize()`

``` cpp
v.reserve(100); // capacity becomes at least 100; size unchanged
v.resize(100);  // size becomes 100
```

This is one of the most important STL distinctions.

------------------------------------------------------------------------

## `deque`

Double-ended queue.

``` cpp
deque<int> d;

d.push_back(10);
d.push_front(20);

d.pop_back();
d.pop_front();

d.front();
d.back();
d[2];
```

Typical complexity:

-   Front insertion/removal: `O(1)`
-   Back insertion/removal: `O(1)`
-   Random access: `O(1)`
-   Middle insertion/removal: `O(n)`

Unlike `vector`, a `deque` is not one contiguous block.

------------------------------------------------------------------------

## `list`

Doubly linked list.

``` cpp
list<int> l = {1, 2, 3};

l.push_front(0);
l.push_back(4);

l.pop_front();
l.pop_back();

l.insert(it, 10);
l.erase(it);

l.remove(10);
l.remove_if([](int x) {
    return x % 2 == 0;
});

l.sort();
l.reverse();
l.unique();
```

Important:

-   No random access.
-   `l[i]` is invalid.
-   Insertion/erasure at a known iterator is `O(1)`.
-   `list::sort()` exists because `std::sort()` requires random-access
    iterators.

------------------------------------------------------------------------

## `forward_list`

Singly linked list.

``` cpp
forward_list<int> fl = {1, 2, 3};

fl.push_front(0);
fl.pop_front();

fl.insert_after(it, 10);
fl.erase_after(it);
```

Use when one-way traversal is enough and the lower overhead of a singly
linked list matters.

------------------------------------------------------------------------

# Associative Containers

Ordered containers are normally implemented using balanced trees.

## `set`

Stores unique keys in sorted order.

``` cpp
set<int> s = {5, 2, 2, 4, 1};
// {1, 2, 4, 5}

s.insert(10);
s.erase(4);

s.find(5);
s.count(5);

s.lower_bound(4);
s.upper_bound(4);
```

Typical operations: `O(log n)`.

### Key property

``` cpp
s.insert(x);
```

does nothing if `x` already exists.

------------------------------------------------------------------------

## `multiset`

Like `set`, but duplicates are allowed.

``` cpp
multiset<int> ms = {1, 2, 2, 2, 5};

ms.count(2);

auto it = ms.find(2);
if (it != ms.end())
    ms.erase(it);       // erase ONE occurrence

ms.erase(2);            // erase ALL occurrences of 2
```

This distinction is extremely important.

------------------------------------------------------------------------

## `map`

Stores key-value pairs with unique keys.

``` cpp
map<string, int> mp;

mp["apple"] = 5;
mp["banana"] = 10;

mp.insert({"orange", 7});
mp.emplace("mango", 8);

cout << mp["apple"];
```

### Dangerous difference

``` cpp
mp["missing"];
```

If `"missing"` does not exist, `operator[]` creates it with a default
value.

Use:

``` cpp
mp.find(key);
```

when you only want to check existence.

C++20 also provides:

``` cpp
mp.contains(key);
```

------------------------------------------------------------------------

## `multimap`

Multiple values can have the same key.

``` cpp
multimap<int, string> mm;

mm.insert({1, "A"});
mm.insert({1, "B"});
mm.insert({2, "C"});
```

`operator[]` is not available.

To access all values for a key:

``` cpp
auto range = mm.equal_range(1);

for (auto it = range.first; it != range.second; ++it)
    cout << it->second;
```

------------------------------------------------------------------------

# Unordered Containers

Hash-table based containers.

## `unordered_set`

``` cpp
unordered_set<int> us;

us.insert(10);
us.erase(10);

us.find(10);
us.count(10);
us.contains(10); // C++20
```

Average:

-   Insert: `O(1)`
-   Find: `O(1)`
-   Erase: `O(1)`

Worst case can be `O(n)`.

Order is **not sorted** and should not be relied upon.

------------------------------------------------------------------------

## `unordered_map`

``` cpp
unordered_map<string, int> freq;

freq["apple"]++;
freq["banana"] += 2;

if (freq.find("apple") != freq.end()) {
    // found
}
```

Useful for frequency counting.

``` cpp
for (auto &[key, value] : freq)
    cout << key << ' ' << value << '\n';
```

The iteration order is unspecified.

------------------------------------------------------------------------

# Container Adaptors

Adaptors provide restricted interfaces over underlying containers.

## `stack`

LIFO.

``` cpp
stack<int> st;

st.push(10);
st.emplace(20);

st.top();

st.pop();

st.empty();
st.size();
```

`pop()` returns `void`.

``` cpp
int x = st.top();
st.pop();
```

------------------------------------------------------------------------

## `queue`

FIFO.

``` cpp
queue<int> q;

q.push(10);
q.emplace(20);

q.front();
q.back();

q.pop();
```

Again, `pop()` returns `void`.

------------------------------------------------------------------------

## `priority_queue`

Heap-based priority structure.

``` cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top(); // 30

pq.pop();
```

Default = max heap.

### Min heap

``` cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### Pair priority queue

``` cpp
priority_queue<pair<int,int>> pq;
```

Pairs are compared lexicographically.

------------------------------------------------------------------------

# `array`

Fixed-size container.

``` cpp
array<int, 5> a = {1, 2, 3, 4, 5};

a[0];
a.at(0);

a.size();
a.front();
a.back();
a.fill(0);
```

Unlike C arrays, `std::array` knows its size and works naturally with
STL algorithms.

------------------------------------------------------------------------

# `bitset`

Fixed number of bits.

``` cpp
bitset<8> b("10110010");

b[0];
b.set(2);
b.reset(2);
b.flip(0);

b.count();
b.any();
b.none();
b.all();

cout << b.to_string();
```

Useful for fixed-size bit manipulation.

------------------------------------------------------------------------

# Container Operations

Most containers expose some combination of:

``` cpp
size()
empty()
clear()
begin()
end()
cbegin()
cend()
front()
back()
insert()
erase()
find()
count()
swap()
```

Do not assume every container has every function.

For example:

-   `vector` has `operator[]`.
-   `set` does not.
-   `stack` does not expose iterators.
-   `priority_queue` does not expose iterators.

------------------------------------------------------------------------

# Iterators

## Basic

``` cpp
auto it = v.begin();

cout << *it;
++it;
```

`end()` points **one position past the last element**.

Never dereference `end()`.

------------------------------------------------------------------------

## `begin()` vs `cbegin()`

``` cpp
auto it = v.begin();   // iterator
auto cit = v.cbegin(); // const_iterator
```

`cbegin()` prevents modification through that iterator.

------------------------------------------------------------------------

## Reverse iterators

``` cpp
v.rbegin();
v.rend();

v.crbegin();
v.crend();
```

Example:

``` cpp
for (auto it = v.rbegin(); it != v.rend(); ++it)
    cout << *it;
```

------------------------------------------------------------------------

## Iterator helper functions

``` cpp
next(it);
prev(it);

advance(it, n);

distance(first, last);
```

Important:

``` cpp
next(it, 5);
```

returns a new iterator.

``` cpp
advance(it, 5);
```

moves `it` itself.

------------------------------------------------------------------------

# Algorithms

Most algorithms are in `<algorithm>`.

## Searching

### `find`

Finds an exact value.

``` cpp
auto it = find(v.begin(), v.end(), x);

if (it != v.end())
    cout << "Found";
```

Complexity: `O(n)`.

------------------------------------------------------------------------

### `find_if`

Finds the first element satisfying a condition.

``` cpp
auto it = find_if(v.begin(), v.end(),
                  [](int x) {
                      return x > 10;
                  });
```

------------------------------------------------------------------------

### `find_if_not`

Finds the first element that does **not** satisfy the condition.

``` cpp
find_if_not(v.begin(), v.end(),
            [](int x) { return x % 2 == 0; });
```

------------------------------------------------------------------------

## Sorting

``` cpp
sort(v.begin(), v.end());
```

Descending:

``` cpp
sort(v.begin(), v.end(), greater<int>());
```

Custom:

``` cpp
sort(v.begin(), v.end(),
     [](int a, int b) {
         return a > b;
     });
```

`std::sort` requires random-access iterators.

------------------------------------------------------------------------

## `stable_sort`

``` cpp
stable_sort(v.begin(), v.end());
```

Equal elements preserve their original relative order.

Usually slower/more memory-intensive than `sort`.

------------------------------------------------------------------------

## `partial_sort`

Sorts only a prefix.

``` cpp
partial_sort(v.begin(),
             v.begin() + k,
             v.end());
```

Useful when the first `k` sorted elements are needed.

------------------------------------------------------------------------

## `nth_element`

``` cpp
nth_element(v.begin(),
            v.begin() + k,
            v.end());
```

Afterward:

-   element at index `k` is the same element that would appear there in
    sorted order;
-   elements before it are not necessarily sorted, but are no greater;
-   elements after it are not necessarily sorted, but are no smaller.

Average complexity: `O(n)`.

This is often much faster than fully sorting when only an order
statistic is needed.

------------------------------------------------------------------------

# Binary Search

Binary-search algorithms require the relevant range to be sorted
according to the same ordering.

## `binary_search`

Returns only `true/false`.

``` cpp
bool found = binary_search(v.begin(), v.end(), x);
```

------------------------------------------------------------------------

## `lower_bound`

Returns iterator to the first element **not less than** `x`.

Equivalent condition:

``` text
element >= x
```

Example:

``` cpp
vector<int> v = {1, 2, 2, 4, 7};

auto it = lower_bound(v.begin(), v.end(), 2);
```

Points to the first `2`.

------------------------------------------------------------------------

## `upper_bound`

Returns iterator to the first element **greater than** `x`.

``` text
element > x
```

For `{1,2,2,4,7}`, `upper_bound(..., 2)` points to `4`.

------------------------------------------------------------------------

## Count occurrences in a sorted range

``` cpp
int count = upper_bound(v.begin(), v.end(), x)
          - lower_bound(v.begin(), v.end(), x);
```

For random-access iterators, the subtraction gives the count directly.

------------------------------------------------------------------------

# Min/Max

``` cpp
min(a, b);
max(a, b);

min({a, b, c});
max({a, b, c});
```

For iterators:

``` cpp
auto it = min_element(v.begin(), v.end());
auto it = max_element(v.begin(), v.end());
```

Both return an iterator.

------------------------------------------------------------------------

## `minmax`

``` cpp
auto [mn, mx] = minmax(a, b);
```

For a range:

``` cpp
auto [mn, mx] = minmax_element(v.begin(), v.end());
```

------------------------------------------------------------------------

# Modification Algorithms

## `reverse`

``` cpp
reverse(v.begin(), v.end());
```

------------------------------------------------------------------------

## `rotate`

``` cpp
rotate(v.begin(), v.begin() + k, v.end());
```

Transforms:

``` text
[a b c d e]
      ^
```

into:

``` text
[c d e a b]
```

when `k = 2`.

------------------------------------------------------------------------

## `remove`

This is a famous STL trap.

``` cpp
remove(v.begin(), v.end(), x);
```

**does not actually shrink a vector.**

It moves unwanted elements toward the end and returns a new logical end.

Correct erase-remove idiom:

``` cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

C++20:

``` cpp
erase(v, x);
```

when using the container-aware `std::erase`.

------------------------------------------------------------------------

## `remove_if`

``` cpp
v.erase(
    remove_if(v.begin(), v.end(),
              [](int x) {
                  return x % 2 == 0;
              }),
    v.end()
);
```

------------------------------------------------------------------------

## `unique`

Removes **consecutive duplicates logically**.

``` cpp
auto it = unique(v.begin(), v.end());
v.erase(it, v.end());
```

If you want to remove all duplicates:

``` cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

------------------------------------------------------------------------

# Set Algorithms

These operate on sorted ranges.

``` cpp
set_union(...)
set_intersection(...)
set_difference(...)
set_symmetric_difference(...)
includes(...)
```

Example:

``` cpp
set_intersection(
    a.begin(), a.end(),
    b.begin(), b.end(),
    back_inserter(result)
);
```

------------------------------------------------------------------------

# Heap Algorithms

``` cpp
make_heap(v.begin(), v.end());
push_heap(v.begin(), v.end());
pop_heap(v.begin(), v.end());
sort_heap(v.begin(), v.end());
```

By default, these create a max heap.

For a min heap:

``` cpp
make_heap(v.begin(), v.end(), greater<int>());
```

A `priority_queue` is usually more convenient when you need a persistent
heap interface.

------------------------------------------------------------------------

# Numeric Algorithms

Mostly `<numeric>`.

## `accumulate`

``` cpp
int sum = accumulate(v.begin(), v.end(), 0);
```

Important: the type of the initial value affects the result type.

``` cpp
accumulate(v.begin(), v.end(), 0);   // integer accumulation
accumulate(v.begin(), v.end(), 0LL); // long long accumulation
```

Custom operation:

``` cpp
int product = accumulate(
    v.begin(), v.end(), 1,
    multiplies<int>()
);
```

------------------------------------------------------------------------

## `reduce` (C++17)

``` cpp
reduce(v.begin(), v.end(), 0);
```

Unlike `accumulate`, `reduce` may reorder operations and is designed to
support parallel execution.

Do not assume floating-point accumulation will have exactly the same
result as `accumulate`.

------------------------------------------------------------------------

## `iota`

``` cpp
iota(v.begin(), v.end(), 1);
```

Produces:

``` text
1 2 3 4 5 ...
```

------------------------------------------------------------------------

## Prefix operations

``` cpp
partial_sum(...)
inclusive_scan(...)
exclusive_scan(...)
```

These are useful for prefix sums and generalized scans.

------------------------------------------------------------------------

# Permutation Algorithms

## `next_permutation`

``` cpp
do {
    // use permutation
} while (next_permutation(v.begin(), v.end()));
```

Generates lexicographically increasing permutations.

------------------------------------------------------------------------

## `prev_permutation`

Generates lexicographically decreasing permutations.

------------------------------------------------------------------------

# Strings and Character Utilities

## `string`

``` cpp
string s = "hello";

s.size();
s.length();

s.empty();

s[0];
s.at(0);

s.front();
s.back();

s.push_back('!');
s.pop_back();

s += " world";

s.substr(pos, len);
s.find("world");
s.rfind("l");

s.compare(other);

s.erase(pos, len);
s.insert(pos, "abc");
s.replace(pos, len, "abc");
```

### Numeric conversion

``` cpp
stoi("123");
stol("123");
stoll("123");

stof("1.2");
stod("1.2");
stold("1.2");
```

Reverse conversion:

``` cpp
to_string(123);
```

------------------------------------------------------------------------

# Pairs, Tuples and Structured Data

## `pair`

``` cpp
pair<int, string> p = {1, "hello"};

p.first;
p.second;
```

Creation:

``` cpp
make_pair(1, "hello");
```

------------------------------------------------------------------------

## `tuple`

``` cpp
tuple<int, string, double> t = {1, "A", 3.14};

get<0>(t);
get<1>(t);
get<2>(t);
```

Structured binding:

``` cpp
auto [id, name, score] = t;
```

------------------------------------------------------------------------

# Functions, Lambdas and Function Objects

## Lambda

``` cpp
auto square = [](int x) {
    return x * x;
};
```

Capture:

``` cpp
int k = 10;

auto f = [k](int x) {
    return x + k;
};
```

Reference capture:

``` cpp
auto f = [&k](int x) {
    return x + k;
};
```

------------------------------------------------------------------------

## Common function objects

``` cpp
less<int>()
greater<int>()

plus<int>()
minus<int>()
multiplies<int>()
divides<int>()
modulus<int>()

equal_to<int>()
not_equal_to<int>()
```

Example:

``` cpp
sort(v.begin(), v.end(), greater<int>());
```

------------------------------------------------------------------------

## `function`

Stores a callable.

``` cpp
function<int(int)> f = [](int x) {
    return x * 2;
};
```

It can hold:

-   function pointers
-   lambdas
-   functors
-   compatible callable objects

------------------------------------------------------------------------

# Smart Pointers

Although smart pointers are not containers, they are important parts of
the standard library.

## `unique_ptr`

Exclusive ownership.

``` cpp
unique_ptr<int> p = make_unique<int>(10);
```

Cannot be copied:

``` cpp
// unique_ptr<int> q = p; // error
```

Can be moved:

``` cpp
auto q = move(p);
```

------------------------------------------------------------------------

## `shared_ptr`

Shared ownership.

``` cpp
auto p = make_shared<int>(10);
auto q = p;
```

Both own the same object.

``` cpp
p.use_count();
```

------------------------------------------------------------------------

## `weak_ptr`

Non-owning reference to an object managed by `shared_ptr`.

``` cpp
weak_ptr<int> w = p;

if (auto locked = w.lock()) {
    cout << *locked;
}
```

Useful for avoiding ownership cycles.

------------------------------------------------------------------------

# Useful STL Types

Common standard-library types include:

``` text
vector
array
deque
list
forward_list

set
multiset
map
multimap

unordered_set
unordered_multiset
unordered_map
unordered_multimap

stack
queue
priority_queue

pair
tuple

optional
variant
any

bitset

string
string_view

span

unique_ptr
shared_ptr
weak_ptr

function
reference_wrapper
```

------------------------------------------------------------------------

# C++20/23 Ranges

Ranges provide a cleaner way to compose algorithms.

Instead of:

``` cpp
sort(v.begin(), v.end());
```

you can write:

``` cpp
ranges::sort(v);
```

Searching:

``` cpp
ranges::find(v, x);
```

Sorting with projection:

``` cpp
ranges::sort(v, {}, &Student::marks);
```

Common range facilities include:

``` text
ranges::sort
ranges::find
ranges::find_if
ranges::count
ranges::count_if
ranges::reverse
ranges::rotate
ranges::copy
ranges::transform
ranges::remove
ranges::unique
ranges::lower_bound
ranges::upper_bound
```

Views include:

``` text
views::filter
views::transform
views::take
views::drop
views::reverse
views::iota
```

Example:

``` cpp
auto result =
    v
    | views::filter([](int x) { return x % 2 == 0; })
    | views::transform([](int x) { return x * x; });
```

Views are generally lazy; they do not necessarily create a new
container.

------------------------------------------------------------------------

# Complexity Cheat Sheet

  ------------------------------------------------------------------------------
  Container                  Access         Search         Insert          Erase
  ------------------ -------------- -------------- -------------- --------------
  `vector`                     O(1)           O(n) O(1) amortized    O(n) middle
                                                           at end 

  `deque`                      O(1)           O(n)      O(1) ends    O(n) middle

  `list`                       O(n)           O(n)      O(1) with      O(1) with
                                                         iterator       iterator

  `forward_list`               O(n)           O(n)     O(1) after     O(1) after
                                                         iterator       iterator

  `set`                         ---       O(log n)       O(log n)       O(log n)

  `map`                         ---       O(log n)       O(log n)       O(log n)

  `unordered_set`               ---   O(1) average   O(1) average   O(1) average

  `unordered_map`               ---   O(1) average   O(1) average   O(1) average

  `priority_queue`         top O(1)            ---       O(log n)       O(log n)
  ------------------------------------------------------------------------------

For unordered containers, worst-case lookup/insertion/erasure can be
`O(n)`.

------------------------------------------------------------------------

# Similar Functions --- Important Differences

## `size()` vs `capacity()`

``` cpp
v.size();      // number of actual elements
v.capacity();  // allocated storage capacity
```

`capacity()` can be larger than `size()`.

------------------------------------------------------------------------

## `reserve()` vs `resize()`

``` cpp
v.reserve(100);
```

Changes capacity, not size.

``` cpp
v.resize(100);
```

Changes size.

------------------------------------------------------------------------

## `clear()` vs `erase()`

``` cpp
v.clear();
```

Removes all elements.

``` cpp
v.erase(it);
```

Removes a specific element/range.

------------------------------------------------------------------------

## `erase()` vs `remove()`

``` cpp
remove(...);
```

Rearranges elements and returns a logical new end.

``` cpp
erase(...);
```

Actually removes elements from containers that support it.

Common pattern:

``` cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

------------------------------------------------------------------------

## `find()` vs `count()`

For a `set`:

``` cpp
s.find(x);
```

returns an iterator.

``` cpp
s.count(x);
```

returns `0` or `1`.

For a `multiset`, `count()` can be greater than `1`.

------------------------------------------------------------------------

## `find()` vs `contains()`

``` cpp
s.find(x) != s.end();
```

works in older standards and gives you the iterator.

``` cpp
s.contains(x);
```

C++20; gives only a boolean.

If you need the element/iterator afterward, `find()` is useful.

------------------------------------------------------------------------

## `lower_bound()` vs `upper_bound()`

``` text
lower_bound(x) -> first element >= x
upper_bound(x) -> first element >  x
```

For:

``` text
1 2 2 2 5
```

`lower_bound(2)` → first `2`

`upper_bound(2)` → `5`

Number of occurrences:

``` cpp
upper_bound(...) - lower_bound(...)
```

for random-access iterators.

------------------------------------------------------------------------

## `binary_search()` vs `lower_bound()`

``` cpp
binary_search(...)
```

answers:

> Does it exist?

``` cpp
lower_bound(...)
```

answers:

> Where is the first valid position?

Use `lower_bound` when you need the position.

------------------------------------------------------------------------

## `sort()` vs `stable_sort()`

`sort()`:

-   generally faster
-   equal elements are not guaranteed to keep relative order

`stable_sort()`:

-   preserves relative order of equivalent elements
-   can require additional memory

------------------------------------------------------------------------

## `sort()` vs `partial_sort()` vs `nth_element()`

### Need everything sorted

``` cpp
sort(...)
```

### Need first `k` elements sorted

``` cpp
partial_sort(...)
```

### Need the element that belongs at position `k`

``` cpp
nth_element(...)
```

`nth_element` does **not** fully sort either side.

------------------------------------------------------------------------

## `push_back()` vs `emplace_back()`

``` cpp
v.push_back(obj);
```

inserts an existing object/value.

``` cpp
v.emplace_back(args...);
```

constructs the element directly from arguments.

Example:

``` cpp
vector<pair<int,string>> v;

v.push_back({1, "A"});
v.emplace_back(1, "A");
```

`emplace_back` is not automatically faster in every situation. Use it
when direct construction is actually useful.

------------------------------------------------------------------------

## `insert()` vs `emplace()`

Similar idea:

``` cpp
container.insert(value);
```

takes an object/value.

``` cpp
container.emplace(args...);
```

constructs an object in place.

------------------------------------------------------------------------

## `at()` vs `operator[]`

``` cpp
v[i];
```

does not perform bounds checking.

``` cpp
v.at(i);
```

performs bounds checking and throws `std::out_of_range` when invalid.

------------------------------------------------------------------------

## `front()` / `back()` vs `[0]` / `[size()-1]`

``` cpp
v.front();
v.back();
```

express intent clearly.

But all are invalid on an empty container.

------------------------------------------------------------------------

## `begin()` vs `end()`

``` cpp
begin() // first element
end()   // one past last element
```

Never:

``` cpp
*container.end();
```

------------------------------------------------------------------------

## `next()` vs `advance()`

``` cpp
auto it2 = next(it, 3);
```

does not change `it`.

``` cpp
advance(it, 3);
```

changes `it`.

------------------------------------------------------------------------

## `++it` vs `it++`

Both move the iterator forward.

Prefer:

``` cpp
++it;
```

because postfix increment conceptually creates a previous-value copy.

For many iterators the difference is optimized away, but prefix
increment is the conventional choice.

------------------------------------------------------------------------

## `map[key]` vs `map.at(key)` vs `map.find(key)`

``` cpp
mp[key];
```

may insert a missing key.

``` cpp
mp.at(key);
```

throws if missing.

``` cpp
mp.find(key);
```

does not insert and returns an iterator.

------------------------------------------------------------------------

## `set` vs `unordered_set`

`set`:

-   sorted
-   `O(log n)` operations
-   predictable ordering

`unordered_set`:

-   no sorted order
-   average `O(1)`
-   hash table
-   performance depends on hashing/load factor

------------------------------------------------------------------------

## `map` vs `unordered_map`

`map`:

``` text
key -> value
ordered by key
O(log n)
```

`unordered_map`:

``` text
key -> value
hash based
O(1) average
```

Choose based on required ordering and performance characteristics.

------------------------------------------------------------------------

## `set` vs `multiset`

``` text
set       -> unique keys
multiset  -> duplicate keys allowed
```

------------------------------------------------------------------------

## `map` vs `multimap`

``` text
map       -> one value per key
multimap  -> multiple entries per key
```

------------------------------------------------------------------------

## `vector` vs `list`

Prefer `vector` when:

-   random access matters
-   data is mostly appended
-   cache locality matters
-   you need STL sorting

Prefer `list` when:

-   you already have iterators to positions
-   frequent insertion/erasure in the middle is important
-   random access is unnecessary

Do not choose `list` merely because "insertion is O(1)". Finding the
insertion position can still cost `O(n)`.

------------------------------------------------------------------------

# Common STL Loopholes / Pitfalls

## 1. `map::operator[]` inserts

``` cpp
map<int,int> mp;

cout << mp[100];
```

Now key `100` exists with a default-initialized value.

Use `find()` or `contains()` if you only want to test existence.

------------------------------------------------------------------------

## 2. `vector::erase()` invalidates iterators

``` cpp
auto it = v.begin() + 2;
v.erase(it);

// it should not be used afterward
```

Always use the iterator returned by `erase()` when continuing iteration.

------------------------------------------------------------------------

## 3. `vector` reallocation invalidates references

``` cpp
int &x = v[0];

v.push_back(100);
```

If `push_back` causes reallocation, `x` may become invalid.

`reserve()` can reduce reallocations when the approximate final size is
known.

------------------------------------------------------------------------

## 4. `unordered_map` iteration order is not sorted

Never write code that assumes:

``` cpp
for (auto &[k,v] : mp)
```

visits keys in ascending order.

Use `map` if sorted iteration is required.

------------------------------------------------------------------------

## 5. `unordered_map` can degrade

Average complexity is often `O(1)`, but worst-case operations can be
`O(n)`.

Do not treat "unordered" as a mathematical guarantee of constant time.

------------------------------------------------------------------------

## 6. `unique()` does not remove all duplicates

``` cpp
unique(v.begin(), v.end());
```

only handles consecutive equivalent elements.

To deduplicate:

``` cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

------------------------------------------------------------------------

## 7. `remove()` does not shrink the container

Wrong:

``` cpp
remove(v.begin(), v.end(), x);
```

Correct:

``` cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

------------------------------------------------------------------------

## 8. `priority_queue::pop()` returns nothing

Wrong:

``` cpp
int x = pq.pop();
```

Correct:

``` cpp
int x = pq.top();
pq.pop();
```

------------------------------------------------------------------------

## 9. `queue::pop()` also returns nothing

``` cpp
int x = q.front();
q.pop();
```

------------------------------------------------------------------------

## 10. `stack::pop()` also returns nothing

``` cpp
int x = st.top();
st.pop();
```

------------------------------------------------------------------------

## 11. `end()` is not an element

``` cpp
auto it = v.end();

// *it is invalid
```

------------------------------------------------------------------------

## 12. Empty containers make `front()` and `back()` dangerous

``` cpp
if (!v.empty()) {
    cout << v.front();
}
```

------------------------------------------------------------------------

## 13. `vector<bool>` is special

``` cpp
vector<bool>
```

is a specialized representation rather than a normal `vector<T>`.

It packs bits efficiently, but its element access behaves through proxy
objects.

If ordinary boolean semantics are more important than bit packing,
consider:

``` cpp
vector<char>
```

or another suitable representation.

------------------------------------------------------------------------

## 14. `reserve()` does not initialize elements

``` cpp
vector<int> v;
v.reserve(100);

cout << v[0]; // invalid
```

You reserved capacity, but `size()` is still `0`.

Use:

``` cpp
v.resize(100);
```

if you need 100 actual elements.

------------------------------------------------------------------------

## 15. `resize()` can destroy elements

``` cpp
v.resize(3);
```

when `v` previously contained more than 3 elements removes the excess
elements.

------------------------------------------------------------------------

## 16. `sort()` requires random-access iterators

This works:

``` cpp
sort(v.begin(), v.end());
```

This does not:

``` cpp
sort(l.begin(), l.end()); // list iterator is not random access
```

Use:

``` cpp
l.sort();
```

for `list`.

------------------------------------------------------------------------

## 17. `lower_bound()` needs the correct ordering

This is only valid when the range is sorted according to the ordering
used by the search.

Do not binary-search an unsorted vector.

------------------------------------------------------------------------

## 18. Comparator must define a consistent ordering

A comparator used for ordered algorithms/containers must obey the
required ordering rules.

For sorting, this is good:

``` cpp
[](int a, int b) {
    return a < b;
}
```

Do not write arbitrary conditions such as:

``` cpp
[](int a, int b) {
    return a <= b;
}
```

for `std::sort`; the comparator must use strict ordering.

------------------------------------------------------------------------

## 19. `accumulate` initial value controls the type

``` cpp
vector<long long> v;

accumulate(v.begin(), v.end(), 0);
```

starts accumulation using `int`.

Prefer:

``` cpp
accumulate(v.begin(), v.end(), 0LL);
```

when the result should be `long long`.

------------------------------------------------------------------------

## 20. Signed/unsigned comparisons

Container sizes use an unsigned type:

``` cpp
v.size()
```

Mixing it carelessly with `int` can produce surprising comparisons.

Example:

``` cpp
for (int i = 0; i < v.size(); ++i)
```

usually works for ordinary sizes, but a more type-correct form is:

``` cpp
for (size_t i = 0; i < v.size(); ++i)
```

or, when indexing logic naturally uses signed integers, take care with
conversions.

------------------------------------------------------------------------

## 21. Iterator invalidation differs by container

Never assume that inserting/erasing one element leaves all iterators
valid.

General examples:

-   `vector`: reallocation can invalidate all iterators/references.
-   `deque`: invalidation rules are more complicated.
-   `list`: insertion generally does not invalidate existing iterators.
-   `set`/`map`: insertion generally does not invalidate existing
    iterators; erasing an element invalidates iterators to that element.
-   `unordered_*`: rehashing can invalidate iterators.

Always check the container's invalidation rules when writing
iterator-heavy code.

------------------------------------------------------------------------

# Common Competitive-Programming Patterns

## Frequency map

``` cpp
unordered_map<int, int> freq;

for (int x : v)
    freq[x]++;
```

------------------------------------------------------------------------

## Sorted unique values

``` cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

------------------------------------------------------------------------

## Coordinate compression skeleton

``` cpp
vector<int> temp = v;

sort(temp.begin(), temp.end());
temp.erase(unique(temp.begin(), temp.end()), temp.end());

for (int &x : v) {
    x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
}
```

------------------------------------------------------------------------

## Count values in a sorted range

``` cpp
int count = upper_bound(v.begin(), v.end(), r)
          - lower_bound(v.begin(), v.end(), l);
```

This counts values in `[l, r]`.

------------------------------------------------------------------------

## K largest elements

``` cpp
priority_queue<int, vector<int>, greater<int>> pq;

for (int x : v) {
    pq.push(x);

    if (pq.size() > k)
        pq.pop();
}
```

------------------------------------------------------------------------

## K smallest elements

``` cpp
priority_queue<int> pq;

for (int x : v) {
    pq.push(x);

    if (pq.size() > k)
        pq.pop();
}
```

------------------------------------------------------------------------

## Reverse a container

``` cpp
reverse(v.begin(), v.end());
```

or:

``` cpp
sort(v.rbegin(), v.rend());
```

The second one sorts descending; it is **not** simply a replacement for
`reverse`.

------------------------------------------------------------------------

## Iterate through a map

``` cpp
for (auto &[key, value] : mp) {
    cout << key << ' ' << value << '\n';
}
```

The structured binding requires C++17.

------------------------------------------------------------------------

## Iterate with explicit iterator

``` cpp
for (auto it = mp.begin(); it != mp.end(); ++it) {
    cout << it->first << ' ' << it->second << '\n';
}
```

------------------------------------------------------------------------

## Erase while iterating

For associative containers:

``` cpp
for (auto it = s.begin(); it != s.end(); ) {
    if (*it % 2 == 0)
        it = s.erase(it);
    else
        ++it;
}
```

The returned iterator is the safe way to continue.

------------------------------------------------------------------------

# Quick Decision Guide

### Need a dynamic array?

``` text
vector
```

### Need fast insertion/removal at both ends?

``` text
deque
```

### Need a doubly linked list with iterator-based insertion/erasure?

``` text
list
```

### Need unique sorted values?

``` text
set
```

### Need duplicate sorted values?

``` text
multiset
```

### Need sorted key-value pairs?

``` text
map
```

### Need duplicate key-value entries?

``` text
multimap
```

### Need average O(1) key lookup?

``` text
unordered_map
unordered_set
```

### Need LIFO?

``` text
stack
```

### Need FIFO?

``` text
queue
```

### Need repeatedly access the largest/smallest element?

``` text
priority_queue
```

### Need fixed-size array?

``` text
array
```

### Need a fixed collection of bits?

``` text
bitset
```

### Need "is it present?"

``` text
set/map -> contains() (C++20)
```

### Need the position of a value?

``` text
find()
```

### Need first element \>= x?

``` text
lower_bound()
```

### Need first element \> x?

``` text
upper_bound()
```

### Need everything sorted?

``` text
sort()
```

### Need only the k-th order statistic?

``` text
nth_element()
```

### Need first k sorted elements?

``` text
partial_sort()
```

### Need to remove elements matching a value from a vector?

``` text
erase(remove(...), end())
```

or C++20:

``` text
std::erase(container, value)
```

------------------------------------------------------------------------

# Header Cheat Sheet

Common headers:

``` cpp
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>

#include <algorithm>
#include <numeric>
#include <iterator>

#include <string>
#include <string_view>

#include <utility>
#include <tuple>

#include <functional>

#include <memory>

#include <optional>
#include <variant>
#include <any>

#include <bitset>

#include <ranges>       // C++20
#include <span>         // C++20
```

------------------------------------------------------------------------

# One-Page Mental Model

``` text
                 STL
                  |
       +----------+----------+
       |          |          |
   Containers  Algorithms  Utilities
       |          |          |
       |          |          +-- pair / tuple
       |          |          +-- function
       |          |          +-- smart pointers
       |          |
       |          +-- sort
       |          +-- find
       |          +-- binary search
       |          +-- min/max
       |          +-- heap
       |          +-- numeric
       |
       +-- vector
       +-- deque
       +-- list
       +-- set/map
       +-- unordered_set/map
       +-- stack/queue/priority_queue

                +
            Iterators
                |
        begin / end / rbegin
        next / prev / advance
        distance

                +
             Ranges
                |
        C++20/23 algorithms
        views and pipelines
```

------------------------------------------------------------------------

# Recommended Learning Order

For learning STL from scratch:

1.  `vector`
2.  `pair`
3.  `string`
4.  `sort`
5.  `reverse`
6.  `find`
7.  `min_element` / `max_element`
8.  `set`
9.  `map`
10. `unordered_set`
11. `unordered_map`
12. `stack`
13. `queue`
14. `priority_queue`
15. iterators
16. `lower_bound` / `upper_bound`
17. `erase` / `remove` / `unique`
18. custom comparators
19. `lambda`
20. `tuple`
21. heap algorithms
22. numeric algorithms
23. ranges

------------------------------------------------------------------------

# Final Rule of Thumb

When choosing an STL tool, ask:

``` text
1. How do I need the data ordered?
2. Do duplicates matter?
3. Do I need random access?
4. Where are insertions/deletions happening?
5. Do I need key -> value mapping?
6. Do I need average O(1) hashing or O(log n) ordering?
7. Do I need the whole range sorted or only an order statistic?
8. Will iterator/reference invalidation matter?
```

The STL becomes much easier once these questions become automatic.
