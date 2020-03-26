#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const int arraySize = 100;
int * ArrayValues(){
    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 500;
    }
    return array;
}
string ShowValues(int * array){
    string values = "";
    for (int i = 0; i < arraySize; ++i) {
        values += to_string((i + 1)) + ": " + to_string(array[i]) + "\n";
    }
    return values;
}
string SearchMax(int * array){
    string response = "";
    int maxPos = 0;
    int maxNumber = array[0];
    for (int i = 0; i < arraySize; ++i) {
        if(maxNumber < array[i]){
            maxPos = i;
            maxNumber = array[i];
        }
    }
    response += "Numero maximo: " + to_string(maxNumber) + "\n" + "Posicion: " + to_string(maxPos + 1) + "\n";
    return response;
}
string SearchMin(int * array){
    string response = "";
    int minPos = 0;
    int minNumber = array[0];
    for (int i = 0; i < arraySize; ++i) {
        if(minNumber > array[i]){
            minPos = i;
            minNumber = array[i];
        }
    }
    response += "Numero menor: " + to_string(minNumber) + "\n" + "Posicion: " + to_string(minPos + 1) + "\n";
    return response;
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
int main() {
    srand(time(NULL));
    int * array = nullptr;
    int opcion = 1;
    while(opcion > 0 && opcion < 6){
        system("clear"); //en windows seria cls
        cout<<"1 Para añadir valores aleatorios \n 2 Para mostrar valores \n 3 Para buscar el valor maximo \n 4 Para buscar el valor minimo \n 5 Para ordenar el arreglo \n 6 Para salir"<< endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                delete array;
                array = ArrayValues();
                break;
            case 2:
                if(array != nullptr)
                {
                    cout << ShowValues(array);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 3:
                if(array != nullptr)
                {
                    cout << SearchMax(array);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 4:
                if(array != nullptr)
                {
                    cout << SearchMin(array);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 5:
                if(array != nullptr)
                {
                    SortArray(array);
                    cout<<ShowValues(array);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 6:
                delete array;
                break;
        }
        cin.ignore();
        cout<<"Presione enter para continuar"<<endl; //en windows reemplazar por un system("pause")
        cin.get();
    }
    return 0;
}
