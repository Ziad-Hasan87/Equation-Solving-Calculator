#include <bits/stdc++.h>
using namespace std;
vector <int> * gaus(vector <int> ara[], int n){
    int i = n-1, j = 0;
    //Start:
    while(1){
        if(ara[i][j] != 0) {
            int k = 1;
            /*
            if(ara[i][i] == 0){
                for(int k = 0; ara[i][k] != 0 && ara[k][i] != 0;k++){
                    swap(ara[i],ara[k]);
                    goto Start;
                }
            }
            */
            while(ara[i-k][j] == 0) {
                k++;
            }
            int temp1 = ara[i][j];
            for(int l = 0; l <= n; l++) {
                    ara[i][l] *= ara[i-k][j];
            }
            for(int l = 0; l <= n; l++) {
                ara[i-k][l] *= temp1;
            }
            for(int x = 0; x <= n;x++) {
                ara[i][x] -= ara[i-k][x];
            }
        }
        i--;
        if(i == j) {
            j++; i = n-1;
        }
        if(j == n-1) break;
    }
    return ara;
}
vector <int> * Jordan(vector <int> ara[], int n){
    int i = 0, j = n-1;
    while(1){
        if(ara[i][j] != 0){
            int k = 1;
            while(ara[i+k][j] == 0) {
                k++;
            }
            int temp1 = ara[i][j];
            for(int l = 0; l <= n; l++) {
                    ara[i][l] *= ara[i+k][j];
            }
            for(int l = 0; l <= n; l++) {
                ara[i+k][l] *= temp1;
            }
            for(int x = 0; x <= n;x++) {
                ara[i][x] -= ara[i+k][x];
            } 
        }
        i++;
        if(i == j) {
            j--; i = 0;
        }
        if(j == 0) break;
    }
    return ara;
}
void Jordan_solver(vector <int> ara[], int n){
    Jordan(ara, n);
    for(int i = 0; i < n; i++){
        ara[i][n] = ara[i][n]/ara[i][i];
        ara[i][i] = ara[i][i]/ara[i][i];
    }
    for(int i = 0; i < n; i++){
        cout << "x" << i+1 << " = " << ara[i][n] << endl;
    }
}
void gaus_solver(vector <int> ara[], int n){
    int ans[n] = {};
    ans[n-1] =ara[n-1][n] / ara[n-1][n-1];
    for(int i = n - 2; i >= 0; i--){
        ans[i] = ara[i][n];
        for(int j = i+1; j < n; j++){
            ans[i] -= ara[i][j]*ans[j];
        }
        ans[i] /= ara[i][i];
    }
    for(int i = 0 ; i < n; i++){
        cout << "x"<< i+1 << " = " << ans[i] << endl;
    }
}
double fx(double x, double y){
    return x-y;
}
double ffx(double x){
    return x = x - 1.0 + 2.0/exp(x);
}
void rungekutta(){
    vector <double> arax;
    vector <double> aray;
    vector <double> araye;
    int i = 0;
    double x = 0, y = 1, step = 0.1;
    araye.push_back(1);
    while(x <= 10){
        cout << i++ << endl;
        arax.push_back(x);
        aray.push_back(y);
        double k1 = step*fx(x,y);
        double k2 = step*fx(x+step/2.0,y+k1/2.0);
        double k3 = step*fx(x+step/2.0,y+k2/2.0);
        double k4 = step*fx(x+step,y+k3); 
        y = y + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0;
        x +=  step;
        araye.push_back(ffx(x));
    }
    for(auto it: arax){
        cout << it << endl;
    }
    for(auto it: aray){
        cout << it << endl;
    }
    
}

int main()
{
    int OPcode = 0, method = 0;
    printf("Please choose your desired operation mode:\n\n");
    printf("  0 - Solution of System of Linear equations:\n");
    printf("  1 - Solution of non linear equations:\n");
    printf("  2 - Solution of differential equations:\n");
    printf("  3 - Matrix inversion:\n");
    cin >> OPcode;
    if(OPcode == 0){
        printf("Choose the desired method: \n");
        printf("\t0 - Jacobi Iteration\n");
        printf("\t1 - Gauss-Seidel Iterative method\n");
        printf("\t2 - Gauss elimination\n");
        printf("\t3 - Gauss-Jordan elimination\n");
        printf("\t4 - LU Factorization\n\n");
        cin >> method;
        printf("Please enter the number of equations: ");
        int n, temp;
        cin >> n;
        vector <int> ara[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                cin >> temp;
                ara[i].push_back(temp);
            }
        }
        if(method == 0){
            
        }
        else if(method == 1){

        }
        else if(method == 2){
            gaus(ara, n);
            gaus_solver(ara, n);
            
        }
        else if(method == 3){
            gaus(ara, n);
            Jordan(ara, n);
            Jordan_solver(ara, n);
        }
        else if(method == 4){

        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                cout << ara[i][j] << " ";
            }
            cout << endl;
        }
    }
    if(OPcode  == 1){
        printf("Choose the desired method: \n");
        printf("\t4 - Bisection method\n");
        printf("\t5 - False position method\n");
        printf("\t6 - Secant method\n");
        printf("\t7 - Newton Raphson method\n\n");
        cin >> method;
    }
    return 0;
}
/*
4
1 2 -1 1 6
-1 1 2 -1 3
2 -1 2 2 14
1 1 -1 2 8
 */
// Solved
