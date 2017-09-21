#include <iostream>
#include <armadillo>

using namespace std;

void max_k_l(mat A, int n, *l, *k){
    double max=0

    for(i=0,i<n, i++){
    for(j=0, j<n,j++){
            if(fabs(A(i,j))>max){max=fabs(A(i,j)); *l=i; *k=j}


    }

    }
}

void jacobi(){




    return 0
}

int main()
{


    // lage en matrise
    double n=3;
    mat A(n,n,fill::zeros);

    double l;
    double k;
    double t;
    double s;
    double c;
    //finne k og l
    max_k_l(A, n, *l, *k);

    double tau=(A(l,l)-A(k,k))/(2*A(k,l));

    if (tau>=0){
        t=-tau-sqrt(1+tau);

    }
    else{
        t=tau+sqrt(1+tau);
    }

    c=1/sqrt(1+tau**2);
    s=t*s;





    return 0;
}

