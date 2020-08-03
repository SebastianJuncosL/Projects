#include "Persona.h"
#include "Streaming.h"
class Admin : private Persona
{
private:
public:
    Admin(string nombre);
    ~Admin();
    // Las siguientes funciones son para poder acceder a la administración del 
    // servicio de streaming, estas fucniones simplemente mandan a llamar los 
    // métodos privados que existen dentro de un objeto de tipo Streaming
    void agregarPelicula(Streaming *, string, float, string, float, string);
    void agregarSerie(Streaming *, string, string);
    void agregarCapitulos(Streaming *, string, string, int, float, float);
    void borrarSerie(Streaming *, string);
    void borrarPelicula(Streaming *, string);
    void borrarTodasLasPeliculas(Streaming *);
};
