//
// Created by branp on 2/03/2024.
//

#include "Manejador.h"
#include "Carta.h"
Manejador::Manejador() {

};
Carta* Manejador::InsertarCartas() {
    Carta* Baraja = new Carta[52];
    int cRepes = 1;
    int cArreglo = 0;
    std::string pre = "";
    char color = 'n';
    while (cRepes <= 4) {
        if (cRepes == 1) {
            pre = "E3";
            color = 'n';
        } else if (cRepes == 2) {
            pre = "!!";
            color = 'n';
        } else if (cRepes == 3) {
            pre = "<>";
            color = 'r';
        } else if (cRepes == 4) {
            pre = "<3";
            color = 'r';
        }
        for (int i = 0; i < 12; ++i) {
            Baraja[cArreglo] = Carta(i, pre, color);
            cArreglo++;
        }
        cRepes++;
    }
    return Baraja;
}