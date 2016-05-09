#include <iostream>
#include <vector>
#include <stdlib.h>



using namespace std;

int printv(vector<int> v) {
    cout << "[";
    for (int i=0 ; i<v.size() ; i++) {
        cout << v[i] << ",";
    }
    cout << "]" << endl;
}

void printF(vector<vector<int>> b){
    cout << "[";
    for (int i=0 ; i<b.size() ; i++) {
        printv(b[i]);
    }
    cout << "]" << endl;
}


void csort (vector<int> a , int k){

    vector<int> c(k,0);
    for(int i = 0; i< a.size(); i++)
    {
        c[a[i]]++;
    }
    printv(c);

    vector<int> b(a.size(),0);
    for(int i = 1; i< k; i++)
    {
        c[i] = c[i-1] + c[i];
    }

    printv(c);

    for(int i = 0; i< a.size(); i++)
    {   cout << "before: " << b[c[a[i]]] << endl;
        b[-- c[a[a.size()-i-1]]] = a[a.size()-i-1];
        cout << b[c[a[a.size()-i-1]]] << endl;
    }
    printv(b);

    for(int i = 0; i< a.size(); i++)
    {
        a[i] = b[i];
    }

}

void cVectorSort(vector<vector<int>>&  a, unsigned long long indice){

    vector<int> c(2,0);
    for(int i = 0; i< a.size(); i++)
    {
        c[a[i][indice]]++; //tipa
    }

    vector<vector<int>> b(a.size() ,vector<int>(a[0].size()));
    c[1] = c[0] + c[1]; //aca se sabe cuantos menores o iguales a 1 hay, idem para 0;
    for(int i = a.size() - 1; i >= 0; i--)
    {
        b[--c[a[i][indice]]] = a[i];
    }

    a = b;
    printF(a);

}


void radixSort(vector<vector<int>> bv ){
    for(int i = bv[0].size() - 1; i >= 0; i--){
        cVectorSort(bv,i);
    }
}

int maxim(vector<int> a){
    auto maximActual = a[0];
    for(int i =0; i < a.size(); i++){
        maximActual = max(maximActual,a[i]);
    }
    return maximActual + 1;
}

vector<int> nuevoN(int len) {
    srand(time(NULL));
    vector<int> n(len,0);
    for (int i=0 ; i<len ; i++) {
        n[i] = rand() % 2;
    }
    return n;
}

int main()
{
    //vector<int> a = {1,3,7,3,9,3,4,7,2};
    //csort(a, maxim(a));
//    vector<int> a1 = {1,0,0,0,0,1,0,1,1,0,1,0,0,1};
//    vector<int> a2 = {1,1,0,0,1,0,1,1,1,1,0,1,0,0};
//    vector<int> a3 = {0,0,0,1,1,0,0,0,0,0,0,0,0,1};
//    vector<int> a4 = {1,0,1,1,0,1,1,1,0,0,0,0,1,0};
//    vector<vector<int>> binarios = {a1,a2,a3,a4};
//    printF(binarios);
//    radixSort(binarios);
//

    int csm = 0;
    unsigned long long dosALaDiezYSeis = 65536;
    vector<vector<int>> s(dosALaDiezYSeis);
    for(int i = 0 ; i< dosALaDiezYSeis; i++){
        cout << i << endl;
        vector<int> aux(dosALaDiezYSeis);
        for(int i = 0 ; i< dosALaDiezYSeis; i++){
            aux[i] = rand() % 2;
            srand (time(NULL) + csm++);
        }
        s[i] = aux;
    }
//    int rand = rand() % 2;
//    vector<int> l = nuevoN(6);

//    printv(l);

    return 0;
}

