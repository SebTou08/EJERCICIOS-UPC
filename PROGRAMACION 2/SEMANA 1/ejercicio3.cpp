#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int arraySize = 30;
int * ArrayValues(){
    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % (100)  + 1;
    }
    return array;
}
void ShowValues(int*array){
    for (int i = 0; i < arraySize; ++i) {
        cout<<array[i]<<endl;
    }
}
void SortArray(int * array){
    int temporal;
    for (int i = 0;i < arraySize; i++){
        for (int j = 0; j< arraySize-1; j++){
            if (array[j] > array[j+1]){
                temporal = array[j];
                array[j] = array[j+1];
                array[j+1] = temporal;
            }
        }
    }
}
void ShowRepeat(int *array){
    int NumbersRepeat;
    int indexFinal;
    for (int i = 0; i < arraySize; ++i) {
        NumbersRepeat = 1;
        indexFinal = i;
        for (int j = i + 1; j < arraySize; ++j) {
            if(array[i] != array[j]){
                break;
            }
            else{
                indexFinal = j;
                ++NumbersRepeat;
            }
        }
        cout<<"El numero "<<array[i]<<" se repitio "<<NumbersRepeat <<" veces"<<endl;
        if(indexFinal > i){
            i = indexFinal;
        }
    }
}
void DeleteRepeat(int * array){
    for (int i = 0; i < arraySize; ++i) {
        int next = i + 1;
        if(array[i] == array[next] && next < arraySize){
            int * Auxiliar = new int[arraySize - 1];
            for (int j = 0; j < arraySize - 1; ++j) {
                if(j < next){
                    Auxiliar[j] = array[j];
                }
                if(j >= next){
                    Auxiliar[j] = array[j + 1];
                }
            }
            delete array;
            array = Auxiliar;
            --arraySize;
            --i;
        }
    }
    ShowValues(array);
}
int main() {
    srand(time(NULL));
    int * array = nullptr;
    array = ArrayValues();
    cout<<"Valores del array: "<<endl;
    ShowValues(array);
    cout<<"Array ordenado: "<<endl;
    SortArray(array);
    ShowValues(array);
    cout<<"Mostrando repeticiones: "<<endl;
    ShowRepeat(array);
    cout<<"Eliminando repeticiones: "<<endl;
    DeleteRepeat(array);
    return 0;
}
