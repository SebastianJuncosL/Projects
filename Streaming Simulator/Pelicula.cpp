#include "Pelicula.h"

Pelicula::Pelicula(string nombre, float duracion, string genero, float calificacion, string director) : Video(nombre, duracion, genero, calificacion), director(new string(director)) {}

Pelicula::~Pelicula()
{
    // Borramos las variables que maneja la clase pelicula que se encuentran en heap
    delete director;
}

string Pelicula::getNombre()
{
    return *nombre;
}

string Pelicula::getDirector()
{
    return *director;
}

string Pelicula::getGenero()
{
    return *genero;
}

float Pelicula::getCalificacion()
{
    return *calificacion;
}

void Pelicula::getInfoPelicula()
{
    for (int i = 0; i < nombre->size(); i++)
    {
        cout << "-";
    }
    cout << "----\n";
    std::cout << "¦ " << *nombre << " ¦" << std::endl;
    for (int i = 0; i < nombre->size(); i++)
    {
        cout << "-";
    }
    std::cout << "----" << std::endl;
    std::cout << "Rating: " << *calificacion << std::endl;
    std::cout << "Director: "<< *director << std::endl;
}