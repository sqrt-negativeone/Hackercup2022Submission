
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN 200001

#define MemoryCopy memcpy
#define MemoryMove memmove
#define MemorySet  memset

#define MemoryCopyStruct(d,s) Statement(MemoryCopy((d),(s),sizeof(*(d)));)
#define MemoryCopyArray(d,s) Statement(Assert(sizeof(d)==sizeof(s)); MemoryCopy((d),(s),sizeof(s));)

#define MemoryZero(p,s) MemorySet((p), 0, (s))
#define MemoryZeroArray(a) MemoryZero((a), sizeof(a))
#define MemoryZeroStruct(p) MemoryZero((p), sizeof(*(p)))

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef i8       b8;
typedef i16      b16;
typedef i32      b32;
typedef i64      b64;
typedef float    r32;
typedef double   r64;
typedef size_t   usize;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.length()) {
        if (freopen(name.c_str(), "r", stdin)) {}
        //if (freopen((name+".out").c_str(), "w", stdout)) {}
    }
}

static int SCount[MAXN];

void solveTestCase(u32 CaseNumber)
{
    MemoryZeroArray(SCount);
    cout << "Case #" << CaseNumber << ": ";
    int N, K; cin >> N >> K;
    int PairCount = 0;
    for (int i = 0; i < N; ++i)
    {
        int s; cin >> s;
        ++SCount[s];
    }
    
    for (int i = 0; i < MAXN; ++i)
    {
        if (SCount[i] > 2)
        {
            cout << "NO" << endl;
            return;
        }
        else if (SCount[i] == 2)
        {
            ++PairCount;
        }
    }
    
    int MaxStylePerCase = PairCount + (N - 2 * PairCount) / 2 + N % 2;
    if (MaxStylePerCase <= K) cout << "YES" << endl;
    else cout << "NO"  << endl;
    
}


int main()
{
    setIO();
    int t = 1;
    cin >> t;
    u32 CaseNumber = 1;
    while (t--){
        solveTestCase(CaseNumber++);
    }
    return 0;
}
