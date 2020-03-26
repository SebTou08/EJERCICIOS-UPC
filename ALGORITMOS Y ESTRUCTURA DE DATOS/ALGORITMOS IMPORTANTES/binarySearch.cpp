//
// Created by lucasmoreno on 25/03/20.
//
#include <iostream>
#include <vector>
using namespace std;
template <class T>
void binarySearch(vector<T>*v, T search, short inicio, short final){
    T pivote = v->at((inicio + final)/2);
    cout<<"inicio: "<<inicio<<endl<<"final: "<<final<<endl;
    if(pivote == search){
        cout<<"encontrado"<<endl;
    }
    if(pivote != search && (inicio + final)/2 <= 1){
        cout<<"no encontrado"<<endl;
    }
    else if(pivote > search){
        binarySearch(v, search,  inicio, (inicio + final)/2);
    }
    else if(pivote < search){
        binarySearch(v, search, (inicio + final)/2, final);
    }
}
int main() {
    vector<int>*a = new vector<int>();
    for (int i = 0; i < 100; ++i) {
        a->push_back(i);
    }
    binarySearch(a, 98, 0, a->size()-1);
    return 0;
}