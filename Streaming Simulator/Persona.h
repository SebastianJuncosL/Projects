#include <string>
using namespace std;

#pragma once
class Persona
{
private:
    // Le damos el nombre a la persona
    string *nombre;

public:
    Persona(string nombre);
    ~Persona();
};

