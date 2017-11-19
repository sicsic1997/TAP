#include<fstream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#define INF 1000000001
#define Nmax 100001
using namespace std;
ifstream f("cmap.in");
ofstream g("cmap.out");
struct punct{int x,y;} V[Nmax];
struct solutie{int nod; double Dmax;} S;
int N,p1,p2,A[Nmax];
bool cmp(const punct &A,const punct &B)
{
    return A.x<B.x;
}
bool cmp2(const int a,const int b)
{
    return V[a].x<V[b].x;
}
void citire()
{
    f>>N;
    for(int i=1;i<=N;++i) f>>V[i].x>>V[i].y;
}
double dist(punct A,punct B)
{
    return sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
}
solutie calc(int st,int dr)
{
    if(st>=dr) //cazul in care am mai putin de un punct
    {
        solutie P;
        P.Dmax=INF;
        return P;
    }
    if(dr-st<=2) // cazul in care am 2 sau 3 puncte
    {
        solutie P; P.Dmax=INF;
        for(int i=st;i<=dr;++i)
            for(int j=i+1;j<=dr;++j) if(dist(V[i],V[j])<P.Dmax) P.Dmax=dist(V[i],V[j]),P.nod=i;
        return P;
    }
    //prelucrez solutiile din cele doua parti ale dreptei
    int m=(st+dr)/2;
    solutie P; P.Dmax=INF;
    solutie P1=calc(st,m);
    solutie P2=calc(m,dr);
    // g<<P1.Dmax<<" "<<P2.Dmax<<'\n';
    if(P1.Dmax<P.Dmax) P=P1;
    if(P2.Dmax<P.Dmax) P=P2;
    //prelucram sirul de care se situeaza la distanta maxima P.Dmax la stanga si la dreapta dreptei
    int l=0;
    for(int i=m;i>=st&&V[m].x-V[i].x<=P.Dmax;i--) A[++l]=i;
    for(int i=m+1;i<=dr&&V[i].x-V[m].x<=P.Dmax;i++) A[++l]=i;
    sort(A+1,A+l+1,cmp2);
    for(int i=1;i<l;++i)
        for(int j=i+1;j<=i+7&&j<=l;++j) if(dist(V[A[i]],V[A[j]])<P.Dmax) P.Dmax=dist(V[A[i]],V[A[j]]),P.nod=A[i];
    //g<<st<<" * "<<dr<<" * "<<P.Dmax<<'\n';
    return P;
}
int main()
{
    citire();
    sort(V+1,V+N+1,cmp);
    //  for(int i=1;i<=N;++i) g<<V[i].x<<" "<<V[i].y<<'\n';
    S=calc(1,N);
    g<<fixed<<setprecision(7)<<S.Dmax<<'\n';
    // g<<S.nod<<'\n';
    return 0;
}
