//
// Created by lucasmoreno on 5/04/20.
//

#ifndef UNTITLED3_CECLIPSE_H
#define UNTITLED3_CECLIPSE_H

#include <iostream>
#include <string>
using namespace std;
class CEclipse {
private:
    string tipo_eclipse;
    string fecha;
    string continente;
    int hora;
    bool sismos;
    bool lluvias;
public:
    CEclipse(string tipo_eclipse, string fecha, string continente, int hora, bool sismos, bool lluvias);
    ~CEclipse();

    string getTipoEclipse();
    string getFecha();
    string getContinente();
    int getHora();
    bool getSismos();
    bool getLuvias();

    void setTipoEclipse(string tipo_eclipse);
    void setFecha(string fecha);
    void setContinente(string continente);
    void setHora(int hora);
    void setSismos(bool sismos);
    void setLuvias(bool lluvias);
    void mostrarEclipse();
};

#endif //UNTITLED3_CECLIPSE_H
