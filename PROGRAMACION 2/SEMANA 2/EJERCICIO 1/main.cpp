#include "CSistema.h"

int main() {
    CSistema *sistema = new CSistema();
    sistema->iniciarSistema();
    delete sistema;
    return 0;
}
