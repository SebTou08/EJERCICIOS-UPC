//
// Created by lucasmoreno on 5/04/20.
//

#include "CEclipse.h"

CEclipse::CEclipse(string tipo_eclipse, string fecha, string continente, int hora, bool sismos, bool lluvias){
    this->tipo_eclipse = tipo_eclipse;
    this->fecha = fecha;
    this->continente = continente;
    this->hora = hora;
    this->sismos = sismos;
    this->lluvias = lluvias;
}
CEclipse::~CEclipse(){
    this->tipo_eclipse.clear();
    this->fecha.clear();
    this->continente.clear();
};
string CEclipse::getTipoEclipse(){
    return this->tipo_eclipse;
};
string CEclipse::getFecha(){
    return this->fecha;
};
string CEclipse::getContinente(){
    return this->continente;
};
int CEclipse::getHora(){
    return this->hora;
};
bool CEclipse::getSismos(){
    return this->sismos;
};
bool CEclipse::getLuvias(){
    return this->lluvias;
};

void CEclipse::setTipoEclipse(string tipo_eclipse){
    this->tipo_eclipse = tipo_eclipse;
};
void CEclipse::setFecha(string fecha){
    this->fecha = fecha;
};
void CEclipse::setContinente(string continente){
    this->continente = continente;
};
void CEclipse::setHora(int hora){
    this->hora = hora;
};
void CEclipse::setSismos(bool sismos){
    this->sismos = sismos;
};
void CEclipse::setLuvias(bool lluvias){
    this->lluvias = lluvias;
};
void CEclipse::mostrarEclipse(){
    cout<<"Tipo: "<<this->getTipoEclipse() << endl;
    cout<<"Fecha: "<<this->getFecha()<<endl;
    cout<<"Continente visible: "<<this->getContinente()<<endl;
    cout<<"Hora: "<<this->getHora()<<endl;
    cout<<"Sismos: "<<this->getSismos()<<endl;
    cout<<"Lluvias: "<<this->getLuvias()<<endl;
}