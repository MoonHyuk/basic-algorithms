# 자주 쓰이고 자주 까먹는 STL
## priority_queue 작은것부터 꺼내기
헷갈리게도 greater<> 를 써야 작은것부터 나온다.
```cpp
priority_queue<int, vector<int>, greater<>> q;
```

## vector
### resize
```cpp
for (int i=1;i<10;i++) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

myvector.resize(5); // 1 2 3 4 5
myvector.resize(8,100); // 1 2 3 4 5 100 100 100
myvector.resize(12); // 1 2 3 4 5 100 100 100 0 0 0 0
```

### insert
Return value: An iterator that points to the first of the newly inserted elements.

**들어간 값들 중 가장 앞 원소의 위치를 반환한다**
```cpp
vector<int> myvector(3,100); // 100 100 100
vector<int>::iterator it;

it = myvector.begin();
it = myvector.insert (it, 200); // 200 100 100 100

myvector.insert(it, 2, 300); // 300 300 200 100 100 100

// "it" no longer valid, get a new one:
it = myvector.begin();

vector<int> anothervector(2, 400); // 400 400
myvector.insert(it+2, anothervector.begin(), anothervector.end()); // 300 300 400 400 200 100 100 100

int myarray [] = {501, 502, 503};
myvector.insert(myvector.begin(), myarray, myarray+3); // 501 502 503 300 300 400 400 200 100 100 100
```

### erase
Return value: An iterator pointing to the new location of the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.

**지워진 값들 중 가장 뒤 원소 다음 위치를 반환한다. 만약 마지막 원소가 지워졌다면 end가 된다.**

```cpp
for (int i=1; i<=10; i++) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9 10

myvector.erase(myvector.begin()+5); // 1 2 3 4 5 7 8 9 10

auto it = myvector.erase(myvector.begin(), myvector.begin()+3); // 4 5 7 8 9 10

myvector.erase(it); // 5 7 8 9 10
```

## set, map
### lower_bound, upper_bound

```cpp
set<int> myset;
set<int>::iterator itlow,itup;

for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

itlow=myset.lower_bound (30);                //       ^
itup=myset.upper_bound (60);                 //                   ^

myset.erase(itlow,itup);                     // 10 20 70 80 90
```

### equal_range

```cpp
for (int i=1; i<=5; i++) myset.insert(i*10);   // 10 20 30 40 50

auto ret = myset.equal_range(30);

cout << "the lower bound points to: " << *ret.first << '\n'; // 30
cout << "the upper bound points to: " << *ret.second << '\n'; // 40
```

## algorithm
TBD
## bitset
TBD
