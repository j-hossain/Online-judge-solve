#include<iostream>
using namespace std;
//accepted
#define li long long int

void inline inout()
{
    #ifndef ONLINE_JUDGE
    freopen("D:/C programming/Online-judge-solve/input.txt","r",stdin);
    freopen("D:/C programming/Online-judge-solve/output.txt","w",stdout);
    #endif
}

typedef struct  
{
    /* nominator and denominator of a fraction */
    long long int nom;
    long long int denom;
}frac;

li gcd(li a, li b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

frac addFrac(frac a, frac b){
    frac ans;
    ans.denom = (a.denom*b.denom)/gcd(a.denom,b.denom);
    ans.nom = (ans.denom/a.denom)*a.nom+(ans.denom/b.denom)*b.nom;

    li gc = gcd(ans.denom,ans.nom);
    if(gc!=1){
        ans.nom/=gc;
        ans.denom/=gc;
    }

    return ans;
}

frac getMul(int nn, int n){
    frac a,b;
    a.denom = a.nom = (li)1;
    b.denom = (li)n;
    b.nom = (li)(-1)*nn;
    a = addFrac(a,b);
    b.denom = a.nom;
    b.nom = a.denom;
    return b;
}

int main(){
    inout();
    int n,nn,t,temp;
    frac num[105],mul,add;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cin>>n;
        nn=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp<0){
                nn++;
                temp*=(-1);
            }
            num[i].nom = temp;
            num[i].denom = n;
        }
        cout<<"Case "<<tt<<": ";
        if(nn==n){
            cout<<"inf\n";
            continue;
        }

        mul = getMul(nn,n);
        add.nom = num[0].nom;
        add.denom = num[0].denom;
        for(int i=1;i<n;i++){
            add = addFrac(add,num[i]);
        }
        mul.nom *=add.nom;
        mul.denom *=add.denom;
        li gc = gcd(mul.nom,mul.denom);
        if(gc!=1){
            mul.nom/=gc;
            mul.denom/=gc;
        }
        cout<<mul.nom<<"/"<<mul.denom<<"\n";
    }
}
