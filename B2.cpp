
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAXN 101

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
        if (freopen((name+".in").c_str(), "r", stdin)) {}
        //if (freopen((name+".out").c_str(), "w", stdout)) {}
    }
}

int dRow[4]   = {1, -1, 0,  0};
int dColum[4] = {0,  0, 1, -1};


#define Tree     '^'
#define Rock     '#'
#define Empty    '.'
#define DeadZone ' '

u32
GetFriendsCountAt(vector<string> &Painting, i32 Row, i32 Column)
{
    u32 Ans = 0;
    for (u32 DeltaIndex = 0; DeltaIndex < 4; ++DeltaIndex)
    {
        i32 FRow = Row + dRow[DeltaIndex];
        i32 FColumn = Column + dColum[DeltaIndex];
        Ans += ((0 <= FRow && FRow < Painting.size()) && 
                (0 <= FColumn && FColumn < Painting[0].size()) &&
                !(FColumn == Column && FRow == Row) &&
                Painting[FRow][FColumn] == Tree);
    }
    
    return Ans;
}

b32
TryPaintFriends(vector<string> &Painting, i32 Row, i32 Column)
{
#if 0
    cout << "Visited " << Row << " " << Column << endl;
#endif
    b32 Result = false;
    if (Painting[Row][Column] == DeadZone)
    {
        return Result;
    }
    
    if (Painting[Row][Column] == Empty)
    {
        Painting[Row][Column] = Tree;
    }
    
    u32 FriendsCount = GetFriendsCountAt(Painting, Row, Column);
    if (FriendsCount >= 2)
    {
        Result = true;
    }
    else
    {
        for (u32 DeltaIndex = 0; DeltaIndex < 4; ++DeltaIndex)
        {
            i32 NRow = Row + dRow[DeltaIndex];
            i32 NColumn = Column + dColum[DeltaIndex];
            
            if ((0 <= NRow && NRow < Painting.size()) && 
                (0 <= NColumn && NColumn < Painting[0].length()) &&
                !(NColumn == Column && NRow == Row) &&
                Painting[NRow][NColumn] == Empty)
            {
                if (TryPaintFriends(Painting, NRow, NColumn))
                {
                    ++FriendsCount;
                    if (FriendsCount == 2)
                    {
                        Result = true;
                        goto done;
                    }
                }
            }
        }
    }
    
    done:;
    if (!Result)
    {
        Painting[Row][Column] = DeadZone;
    }
    return Result;
}

void solveTestCase(u32 CaseNumber)
{
    cout << "Case #" << CaseNumber << ": ";
    int R, C; cin >> R >> C;
    vector<string> Painting(R);
    
    for (u32 Row = 0; Row < R; ++Row)
    {
        cin >> Painting[Row];
    }
    
    if (R == 1)
    {
        for (u32 Column = 0; Column < C; ++Column)
        {
            if (Painting[0][Column] == '^')
            {
                cout << "Impossible" << endl;
                return;
            }
        }
        cout << "Possible" << endl;
        for (u32 Row = 0; Row < R; ++Row)
        {
            cout << Painting[Row] << endl;
        }
        
    }
    else if (C == 1)
    {
        for (u32 Row = 0; Row < R; ++Row)
        {
            if (Painting[Row][0] == '^')
            {
                cout << "Impossible" << endl;
                return;
            }
        }
        
        cout << "Possible" << endl;
        for (u32 Row = 0; Row < R; ++Row)
        {
            cout << Painting[Row] << endl;
        }
        
    }
    else
    {
        for (u32 Row = 0; Row < R; ++Row)
        {
            for (u32 Column = 0; Column < C; ++Column)
            {
                if (Painting[Row][Column] == Tree)
                {
                    if (!TryPaintFriends(Painting, Row, Column))
                    {
                        cout << "Impossible" << endl;
                        return;
                    }
                }
            }
        }
        
        cout << "Possible" << endl;
        for (u32 Row = 0; Row < R; ++Row)
        {
            for (u32 Column = 0; Column < C; ++Column)
            {
                cout << ((Painting[Row][Column] == DeadZone)? '.' : Painting[Row][Column]);
            }
            cout << endl;
        }
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
    cout << "Done";
    return 0;
}
