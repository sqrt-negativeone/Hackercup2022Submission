
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN 101

#define ArrayCount(a) (sizeof(a) / sizeof((a)[0]))

#define MemoryCopy memcpy
#define MemoryMove memmove
#define MemorySet  memset

#define MemoryCopyStruct(d,s) Statement(MemoryCopy((d),(s),sizeof(*(d)));)
#define MemoryCopyArray(d,s) Statement(Assert(sizeof(d)==sizeof(s)); MemoryCopy((d),(s),sizeof(s));)

#define MemoryZero(p,s) MemorySet((p), 0, (s))
#define MemoryZeroArray(a) MemoryZero((a), sizeof(a))
#define MemoryZeroStruct(p) MemoryZero((p), sizeof(*(p)))

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MOD(a, m) (((a) % (m)) >= 0 ? ((a) % (m)) : (((a) % (m)) + (m)))
#define SQUARE(x) ((x) * (x))


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
        if (freopen((name+".in").c_str(), "r", stdin)) {}
        //if (freopen((name+".out").c_str(), "w", stdout)) {}
    }
}

int dRow[4]   = {1, -1, 0,  0};
int dColum[4] = {0,  0, 1, -1};

char Encoding[2] = {'-', '.'};
void solveTestCase(u32 CaseNumber)
{
    cout << "Case #" << CaseNumber << ": ";
    u32 N; cin >> N;
    string C; cin >> C;
    u32 L = C.length();
    u32 ID = 0;
    for (u32 CodewordIndex = 0; CodewordIndex < N - 1; ++CodewordIndex)
    {
        char Codeword[10];
        MemorySet(Codeword, Encoding[0], sizeof(Codeword));
        
        b32 Stop = false;
        for(;!Stop;)
        {
            u32 UsedID = ID++;
            for(u32 Index = 0;UsedID; ++Index)
            {
                Codeword[Index] = Encoding[UsedID % 2];
                UsedID = (UsedID >> 1);
            }
            
            
            for (u32 TestIndex = 0; TestIndex < MIN(L,ArrayCount(Codeword)); ++TestIndex)
            {
                if (Codeword[TestIndex] != C[TestIndex])
                {
                    Stop = true;
                    break;
                }
            }
        }
        
        for(u32 Index = 0; Index < ArrayCount(Codeword); ++Index)
        {
            cout << Codeword[Index];
        }
        cout << endl;
    }
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
