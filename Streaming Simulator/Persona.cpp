#include "Persona.h"

Persona::Persona(string nombre) : nombre(new string(nombre)) {}

Persona::~Persona()
{
    // Borramos todas las variables de la clase persona que se encuentran en heap
    delete nombre;
}