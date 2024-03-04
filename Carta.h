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
public:
    Carta() : Prefijo(""), Valor(0), Color(' ') {}
    Carta(int, std::string, char);
};
#endif //SOLITARIO_CARTA_H

