#include <iostream>
#include <ctime>
using namespace std;
/*----------------IMPORTANTE----------------------------*/
int N;
void eliminarValor(int* &arreglo, int posicion){
    int * nuevoArreglo = new int[N - 1];
    for (int i = 0; i < N; ++i) {
        if(i < posicion){
            nuevoArreglo[i] = arreglo[i];
        }
        if(i > posicion){
            nuevoArreglo[i - 1] = arreglo[i];
        }
    }
    delete arreglo;
    arreglo = nuevoArreglo;
    N--;
}
void agregarAlFinal(int* & arreglo, int nuevoValor){
    int  * nuevoArreglo = new int[N + 1];
    for(int i = 0; i < N; ++i){
        nuevoArreglo[i] = arreglo[i];
    }
    nuevoArreglo[N] = nuevoValor;
    delete arreglo;
    arreglo = nuevoArreglo;
    ++N;
}
void ordenarArreglo(int * &arreglo){
    cout<<"Ordenando ";
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N ; ++j) {
            if(arreglo[i] < arreglo[j]){
                int aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
        cout<< ".";
    }
    cout<<endl<<"Ordenamiento finalizado"<<endl;
}
/*-------------------IMPORTANTE---------------------------*/
void eliminarMultiplosDeTres(int* &arreglo){
    for (int i = 0; i < N; ++i) {
        if(arreglo[i] % 3 == 0){
            eliminarValor(arreglo, i);
            --i;
        }
    }
}
void listarArreglo(int*arreglo){
    cout << "Pos  | \t Val"<<endl;
    cout<<"-----------------"<<endl;
    if(arreglo != nullptr){
        for (int i = 0; i < N; ++i) {
            cout << i + 1 << "\t | \t" << arreglo[i] << endl;
        }
    } else{
        cout<<"No a generado valores al arreglo, porfavor generelos"<<endl;
    }
}
int * generarArreglo(){
    do{
        cout<<"Ingrese el tamaño del arreglo"<<endl;
        cin>>N;
    }while(N < 40 || N > 50);
    int * arregloGenerado = new int[N];
    for (int i = 0; i < N; ++i) {
        arregloGenerado[i] = (rand()%50) + 1;
    }
    return arregloGenerado;
}
int main(){
    srand(time(NULL));
    int *arreglo = generarArreglo();
    listarArreglo(arreglo);
    eliminarMultiplosDeTres(arreglo);
    listarArreglo(arreglo);
    ordenarArreglo(arreglo);
    listarArreglo(arreglo);
    int nuevoValor;
    do{
        cout<<"Ingrese el nuevo valor"<<endl;
        cin>>nuevoValor;
    }while(nuevoValor < 1 || nuevoValor > 50);
    agregarAlFinal(arreglo, nuevoValor);
    ordenarArreglo(arreglo);
    listarArreglo(arreglo);
//AGREGAR UN system("pause>0");
    return 0;
}
