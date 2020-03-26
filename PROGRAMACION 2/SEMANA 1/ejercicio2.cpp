#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int * ArrayValues(int arraySize){
    int *array = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 20;
    }
    return array;
}
string ShowValues(int * array, int arraySize){
    string values = "";
    for (int i = 0; i < arraySize; ++i) {
        values += to_string((i + 1)) + ": " + to_string(array[i]) + "\n";
    }
    return values;
}
string SearchMax(int * array, int arraySize){
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
string SearchMin(int * array, int arraySize){
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
void SortArray(int * array, int arraySize){
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
int AverageNumber(int * array, int arraySize){
    int suma = 0;
    int resultado = 0;
    for (int i = 0; i < arraySize; ++i) {
        suma += array[i];
    }
    resultado = suma/arraySize;
    return resultado;
}
string Percent(int * array, int arraySize){
    float cantAprovados = 0;
    float cantJalados = 0;
    string response = "";
    for (int i = 0; i < arraySize; ++i) {
        if(array[i] >= 11){
            ++cantAprovados;
        }
        else{
            ++cantJalados;
        }
    }
    response = "Porcentaje de jalados: " + to_string((cantJalados/float(arraySize))*100) + "%" + "\n" + "Porcentaje de aprobados: " + to_string((cantAprovados/float(arraySize))*100) + "%" + "\n";
    return response;
}
int main() {
    srand(time(NULL));
    int arraySize;
    cout<<"Ingrese el numero de alumnos que desea registrar: "<<endl;
    cin>>arraySize;
    int * array = nullptr;
    int opcion = 1;
    while(opcion > 0 && opcion < 8){
        system("clear"); //en windows seria cls
        cout<<"1 Para generar nuevas las notas \n 2 Para listar las notas \n 3 Para mostrar la mayor nota \n 4 Para mostrar la menor nota \n 5 Para mostrar la nota promedio \n 6 Para mostrar porcentaje de aprobados y desaprobados \n 7 Para ordenar las notas \n 8 para salir"<< endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                delete array;
                array = ArrayValues(arraySize);
                break;
            case 2:
                if(array != nullptr)
                {
                    cout << ShowValues(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 3:
                if(array != nullptr)
                {
                    cout << SearchMax(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 4:
                if(array != nullptr)
                {
                    cout << SearchMin(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 5:
                if(array != nullptr)
                {
                    cout << "La nota promedio es: " <<AverageNumber(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 6:
                if(array != nullptr)
                {
                    cout << Percent(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 7:
                if(array != nullptr)
                {
                    SortArray(array, arraySize);
                    cout<<ShowValues(array, arraySize);
                }
                else{
                    cout<<"Añade valores al arreglo"<<endl;
                }
                break;
            case 8:
                delete array;
                break;
        }
        cin.ignore();
        cout<<"Presione enter para continuar"<<endl; //en windows reemplazar por un system("pause")
        cin.get();
    }
    return 0;
}
