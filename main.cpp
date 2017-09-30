#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma ;


int max_k_l(mat A, int n, int *k, int *l){
    double max=0;

    for(int i=0;i<n; i++){
    for(int j=0; j<n;j++){
            if(fabs(A(i,j))>max&&i!=j)
    {max=fabs(A(i,j)); *k=i; *l=j;
            //cout<<"her er jeg"<<i<<j<<l<<endl;
            }

    }

    }

return 0;
}
/*
void jacobi(mat A,int n, double k, double l){
    // find t,s and c
    double t,s,c;
    double tau=(A(l,l)-A(k,k))/(2*A(k,l));

    if (tau>=0){
        t=-tau-sqrt(1+tau);
    }
    else{
        t=tau+sqrt(1+tau);
    }
    c=1/sqrt(1+tau*tau);
    s=t*s;

//

    double a_kk, a_ll, a_ik, a_il;
    a_kk=A(k,k); a_ll=A(l,l);

    A(k,k)=c*c*a_kk-2*c*s*A(k,l)+s*s*a_ll;
    A(l,l)=s*s*a_kk+2*c*s*A(k,l)+c*c*a_ll;

    A(l,k)=0;
    A(k,l)=0;

    for (int i=0;i<n;i++){
    a_ik=A(i,k);
    a_il=A(i,l);

    if(i!=k && i!=l){

        A(i,k)=a_ik*c-a_il*s;
        A(k,i)=A(i,k);
        A(i,l)=a_il*c+a_ik;
        A(l,i)=A(i,l);
    cout<<i<<endl;
    A.print();
    }
    }

return;
}
*/
int main()
{


    // lage en matrise
    int n=5;
    mat A(n,n,fill::randn);
/*    for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        A(i,j)=rand() %10;
    }
    }
*/


    cout<< "forste"<<endl;
    A.print();
    int l=0;
    int k=0;
    int * pk=&k; int * pl=&l;
    double mini=pow(10,-10);
    int h=0;
    int h_max=pow(10,5);
    //finne k og l
//    for(int j=0;j<;j++){
    double max=1;
    double a_kk, a_ll, a_ik, a_il;
    double t,s,c;
    while(max>mini && h<h_max){
        h++; //antall ganger
    max_k_l(A, n, pk, pl);
    max=fabs(A(k,l));
//    cout<<" k,l= "<<k<<"  "<<l<<"max= "<< max<<endl;
    // find t,s and c

    double tau=float((A(l,l)-A(k,k)))/(2*A(k,l));
//    t=-tau+sqrt(1+tau*tau);

   if (tau>=0){
        t=1/(tau+sqrt(1+tau*tau));
    }
    else{
        t=-1/(-tau+sqrt(1+tau*tau));
    }


    c=1/sqrt(1+t*t);
    s=t*c;
//    cout<< "t= "<<t<<" s= "<< s<< " c= "<<c<<" tau= "<<tau<<" cos og sin = " <<s*s+c*c<<endl;

//


    a_kk=A(k,k); a_ll=A(l,l);

    A(k,k)=c*c*a_kk-2*c*s*A(k,l)+s*s*a_ll;
    A(l,l)=s*s*a_kk+2*c*s*A(k,l)+c*c*a_ll;

    A(l,k)=0;
    A(k,l)=0;

    for (int i=0;i<n;i++){
;

    if(i!=k && i!=l){
        a_ik=A(i,k);
        a_il=A(i,l);
        A(i,k)=a_ik*c-a_il*s;
        A(k,i)=A(i,k);
        A(i,l)=a_il*c+a_ik*s;
        A(l,i)=A(i,l);
//    cout<<i<<"a_ik "<<a_ik<<" a_il "<<a_il<<endl;
    //A.print();
    }
    }
//A.print();
}
A.print();
cout<<h<<" max= "<<max<< endl;
    return 0;
}

