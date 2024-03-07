//
// Created by branp on 2/03/2024.
//

#ifndef SOLITARIO_CARTA_H
#define SOLITARIO_CARTA_H
#include <string>


class Carta{
private:
    std::string Prefijo;
    int Valor;
    char Color;
    bool Ocultar;
public:
    Carta() : Prefijo(""), Valor(0), Color(' ') {}
    Carta(int, std::string, char);
    // Métodos "getter"
    std::string getPrefijo() const;
    int getValor() const;
    char getColor() const;
    std::string getDatos() const;
    bool getOcultar() const;

    void setOcultar(bool siguiente);
};
#endif //SOLITARIO_CARTA_H

