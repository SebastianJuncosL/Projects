#include "Video.h"

class Capitulo : private Video
{
private:
    int *numeroCapitulo;

public:
    Capitulo(string, float, string, float, int);
    ~Capitulo();
    // Las siguientes funciones nos ayudan a regresar todos
    // los atributos heredados de la clase video, mas los atributos de la clase Capítulo.
    string getNombre();
    int getNumeroCapitulo();
    float getCalificacionCapitulo();
};
