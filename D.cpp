
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define MAXN 200001

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
        if (freopen(name.c_str(), "r", stdin)) {}
        //if (freopen((name+".out").c_str(), "w", stdout)) {}
    }
}

int dRow[4]   = {1, -1, 0,  0};
int dColum[4] = {0,  0, 1, -1};

inline u64
MakeKey(u32 X, u32 Y)
{
    u64 Result = ((u64)MIN(X, Y) | ((u64)MAX(X, Y)  << 32));
    return Result;
}



void solveTestCase(u32 CaseNumber)
{
    cout << "Case #" << CaseNumber << ": ";
    u32 N, M, Q; cin >> N >> M >> Q;
    vector<vector<u32>> Graph(N + 1);
    
    map<u64, u64> IndirectMaxTourists;
    map<u64, u64> DirectMaxTourists;
    
    
    for (u32 E = 0; E < M; ++E)
    {
        u32 U, V; u64 C; cin >> U >> V >> C;
        Graph[U].push_back(V);
        Graph[V].push_back(U);
        DirectMaxTourists[MakeKey(U, V)] = C;
    }
    
    for (u32 Day = 0; Day < Q; ++Day)
    {
        
        u32 X, Y; cin >> X >> Y;
        
        u64 Key = MakeKey(X, Y);
        u64 Indirect = 0;
        
        if (IndirectMaxTourists[Key] == 0)
        {
            if (Graph[X].size() < Graph[Y].size())
            {
                for (u32 E_XZ = 0; E_XZ < Graph[X].size();  ++E_XZ)
                {
                    u32 Z = Graph[X][E_XZ];
                    if (Z == Y) continue;
                    
                    u64 C_XZ = DirectMaxTourists[MakeKey(X, Z)];
                    u64 C_ZY = DirectMaxTourists[MakeKey(Z, Y)];
                    
                    Indirect += MIN(C_XZ, C_ZY);
                }
            }
            else
            {
                for (u32 E_YZ = 0; E_YZ < Graph[Y].size();  ++E_YZ)
                {
                    u32 Z = Graph[X][E_YZ];
                    if (Z == X) continue;
                    
                    u64 C_YZ = DirectMaxTourists[MakeKey(Y, Z)];
                    u64 C_ZX = DirectMaxTourists[MakeKey(Z, X)];
                    
                    Indirect += MIN(C_YZ, C_ZX);
                }
            }
            
            IndirectMaxTourists[Key] = Indirect;
        }
        else
        {
            Indirect = IndirectMaxTourists[Key];
        }
        
        
        cout << Indirect + 2 * DirectMaxTourists[Key] << " ";
    }
    cout << endl;
}


int main()
{
#if 0
    setIO("second_flight_input.txt");
#else
    setIO();
#endif
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin >> t;
    u32 CaseNumber = 1;
    while (t--){
        solveTestCase(CaseNumber++);
    }
    return 0;
}
