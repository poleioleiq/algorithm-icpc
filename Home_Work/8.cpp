//#pragma GCC optimize(2)
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>

#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define sca(a) scanf("%d",&a);
#define sca2(a, b) scanf("%d%d",&a,&b)
#define sca3(a, b, c) scanf("%d%d%d",&a,&b,&c)
#define scac(a) scanf("%c",a);
#define scacc(a, b) scanf("%c%c",a,b)
#define ms(a, b) memset(a,b,sizeof(a))
#define int long long
#define rint register int
using namespace std;
template<class T>void tomax(T &a, T b) { a = max(a, b); }
template<class T>void tomin(T &a, T b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pii;

// #define DEBUG 1  //调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc() {
#if DEBUG  //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x) {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }
    inline void read(char *s) {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c) {
#if DEBUG  //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');  // 负数输出
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;


#define MaxSize 100
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;               //栈指针
} SqStack;                 //顺序栈类型定义
void InitStack(SqStack *&s) {
    s = (SqStack *) malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyStack(SqStack *&s) {
    free(s);
}

bool StackEmpty(SqStack *s) {
    return (s->top == -1);
}

bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1)    //栈满的情况，即栈上溢出
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1)     //栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e) {
    if (s->top == -1)        //栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];
    return true;
}

bool Match3(char exp[], int n) {
    int i;
    char e;
    SqStack *st = NULL;
    InitStack(st);
    for (i = 0; i < n; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') Push(st, exp[i]);
        else if (exp[i] == ')') {
            if (GetTop(st, e) &&e== '(')
                Pop(st, e);
            else {
                DestroyStack(st);
                return false;
            }
        } else if (exp[i] == ']') {
            if (GetTop(st, e) &&e== '[')
                Pop(st, e);
            else {
                DestroyStack(st);
                return false;
            }
        } else if (exp[i] == '}') {
            if (GetTop(st, e) &&e== '{')
                Pop(st, e);
            else {
                DestroyStack(st);
                return false;
            }
        }
    }
    if (StackEmpty(st) == true) {
        DestroyStack(st);
        return true;
    } else {
        DestroyStack(st);
        return false;
    }
}

signed main() {
    char exp[] = "{}{}{[}]({})";
    if (Match3(exp, strlen(exp)))
        printf("true\n", exp);
    else
        printf("false\n", exp);
    return 0;
}