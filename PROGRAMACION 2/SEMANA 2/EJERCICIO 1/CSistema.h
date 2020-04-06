//
// Created by lucasmoreno on 5/04/20.
//

#ifndef UNTITLED3_CSISTEMA_H
#define UNTITLED3_CSISTEMA_H

#include "CEclipse.h"

class CSistema {
private:
    CEclipse** eclipses;
    int tamanho;
    void setEclipseInPosition(int pos, CEclipse *eclipse);
public:
    CSistema();
    ~CSistema();

    CEclipse** getEclipses();
    CEclipse* getEclipseInPosition(int pos);

    void registroDatosDeEclipse(CEclipse* nuevo_eclipse);
    void modificarEclipse(int pos);
    void eliminarEclipse(int pos);
    int eclipsesEnEuropa();
    int eclipsesOcasionaronSismos();
    int eclipsesEnLaNoche();
    void iniciarSistema();
};


#endif //UNTITLED3_CSISTEMA_H
