#ifndef INVALIDRATEEXCEPTION_H
#define INVALIDRATEEXCEPTION_H
#include <stdexcept>
#include <string>
#include "genero.h"

class InvalidRateException : public std::exception
{
public:
    InvalidRateException(int rate) : rate(rate){
        MensajeError = "RANGO " + std::to_string(rate) + " no es un número válido para el review";
    }
private:
    int rate;
    std::string MensajeError;
};

#endif // INVALIDRATEEXCEPTION_H
