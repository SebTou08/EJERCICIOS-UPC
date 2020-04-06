//
// Created by lucasmoreno on 5/04/20.
//

#include "CSistema.h"
CSistema::CSistema(){
    this->eclipses = nullptr;
    this->tamanho = 0;
};
CSistema::~CSistema(){
    for (int i = 0; i < this->tamanho; ++i) {
        delete[] this->eclipses[i];
    }
    delete this->eclipses;
};
void CSistema::setEclipseInPosition(int pos, CEclipse *eclipse){
    if(pos >= this->tamanho || pos < 0){
        cout<<"Pon una posicion correcta, no seas bestia"<<endl;
    } else{
        this->eclipses[pos] = eclipse;
    }
};

CEclipse** CSistema::getEclipses(){
    return this->eclipses;
};
CEclipse* CSistema::getEclipseInPosition(int pos){
    if(pos >= this->tamanho || pos < 0){
        return new CEclipse("", "", "", 0, 0,0);
    } else{
        return this->eclipses[pos];
    }
};

void CSistema::registroDatosDeEclipse(CEclipse *nuevo_eclipse){
    CEclipse ** auxiliar = new CEclipse*[this->tamanho + 1];

    for (int i = 0; i < this->tamanho; ++i) {
        auxiliar[i] = this->eclipses[i];
    }
    auxiliar[this->tamanho] = nuevo_eclipse;
    delete this->eclipses;
    this->eclipses = auxiliar;
    ++this->tamanho;
};
void CSistema::modificarEclipse(int pos){
    if(pos >= this->tamanho || pos < 0){
        cout<<"Pon una posicion correcta, no seas bestia"<<endl;
    } else{
        CEclipse* a_modificar = this->getEclipseInPosition(pos);
        string texto;
        int numero;
        bool booleano;

        cout<<"Ingrese el tipo de eclipse a modificar";
        cin>>texto;
        a_modificar->setTipoEclipse(texto);

        cout<<"Ingrese la fecha del eclipse a modificar";
        cin>>texto;
        a_modificar->setFecha(texto);

        cout<<"Ingrese el continente donde se visualizo el eclipse a modificar";
        cin>>texto;
        a_modificar->setContinente(texto);

        cout<<"Ingrese la hora del eclipse a modificar";
        cin>>numero;
        a_modificar->setHora(numero);

        cout<<"Ingrese si hubo sismo en el eclipse a modificar";
        cin>>booleano;
        a_modificar->setSismos(booleano);

        cout<<"Ingrese si hubo lluvias en el eclipse a modificar";
        cin>>booleano;
        a_modificar->setLuvias(booleano);

        this->setEclipseInPosition(pos, a_modificar);
    }
};
void CSistema::eliminarEclipse(int pos){
    if(pos < 0 || pos >=this->tamanho){
        cout<<"Pon una posicion valida, no seas bestia"<<endl;
    }
    else{
        CEclipse ** auxiliar = new CEclipse*[this->tamanho - 1];
        for (int i = 0; i < this->tamanho; ++i) {
            if(i < pos){
                auxiliar[i] = this->eclipses[i];
            }
            if(i > pos){
                auxiliar[i-1] = this->eclipses[i];
            }
        }
        delete this->eclipses;
        this->eclipses = auxiliar;
        --this->tamanho;
    }
};

int CSistema::eclipsesEnEuropa(){
    int contador = 0;
    for (int i = 0; i < tamanho; ++i) {
        if(this->eclipses[i]->getContinente() == "europa"){
            ++contador;
        }
    }
    return contador;
};
int CSistema::eclipsesOcasionaronSismos(){
    int contador = 0;
    for (int i = 0; i < tamanho; ++i) {
        if(this->eclipses[i]->getSismos() == true){
            ++contador;
        }
    }
    return contador;
};
int CSistema::eclipsesEnLaNoche(){
    int contador = 0;
    for (int i = 0; i < tamanho; ++i) {
        if(this->eclipses[i]->getHora() >= 1900 && this->eclipses[i]->getHora() <= 2400){
            ++contador;
        }
    }
    return contador;
};
void CSistema::iniciarSistema(){
    int n;
    cout<<"Ingrese el numero de eclipses a registrar" << endl;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        this->registroDatosDeEclipse(new CEclipse("kajdkjadn", "01/03/2020", "europa", rand()%(2400 - 100 + 1) + 100, true, true));
    }
    for(int i = 0; i < this->tamanho; ++i){
        cout<<i<<endl;
        this->getEclipses()[i]->mostrarEclipse();
    }
    cout<<"Ingrese el numero de registro que desea eliminar"<<endl;
    cin>>n;
    this->modificarEclipse(n);
    cout<<"Ingrese la posicion del eclipse a eliminar"<<endl;
    cin>>n;
    this->eliminarEclipse(n);
    cout<<"Los eclipses que se registraron en europa son: "<<this->eclipsesEnEuropa()<<endl;
    cout<<"Los eclipses que ocasionaron sismos son: "<<this->eclipsesOcasionaronSismos()<<endl;
    cout<<"Los eclipses en la noche fueron: "<<this->eclipsesEnLaNoche()<<endl;
    for(int i = 0; i < this->tamanho; ++i){
        cout<<i<<endl;
        this->getEclipses()[i]->mostrarEclipse();
    }
};