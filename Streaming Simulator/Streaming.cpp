#include "Streaming.h"

Streaming::Streaming(string nombre) : nombre(new string(nombre)) {}

Streaming::~Streaming()
{
    // Borramos todos los atributos de un servicio de Streaming que se encutran en heap
    delete nombre;
}

void Streaming::getInfoPelicula(string nombre)
{
    // Iteramos sobre la lista de películas
    for (int i = 0; i < peliculas.size(); i++)
    {
        // Si el nombre de una pelúcla es el mismo que el que estamos buscando entonces:
        if (peliculas[i]->getNombre() == nombre)
        {
            // Mostramos la información reelevante para el usuario sobre esa película y
            // rompemos el ciclo ya que no necesitamos seguir buscando
            peliculas[i]->getInfoPelicula();
            break;
        }
    }
}

void Streaming::agregarPelicula(string nombre, float duracion, string genero, float calificacion, string director)
{
    // Agregamos películas a nuestro vector, les pasamos todos los atributos que necesita
    // un objeto de tipo película, la cual hereda los atributos de video
    peliculas.push_back(new Pelicula(nombre, duracion, genero, calificacion, director));
}

void Streaming::quitarPelicula(string nombre)
{
    // Iteramos sobre el vector de películas
    for (int i = 0; i < peliculas.size(); i++)
    {
        // Si el nombre de la película en la posicion i es igual al nombre de la
        // película que estamos buscando, entonces:
        if (peliculas[i]->getNombre() == nombre)
        {
            // Le hacemos saber al Administrador que la pelicula se ha borrado
            std::cout << "Se ha borrado la pelicula '" << peliculas[i]->getNombre() << "'" << std::endl;
            // Borramos la película de heap
            delete peliculas[i];
            // Asi como del vector de películas
            peliculas.erase(peliculas.begin() + i);
        }
    }
}

void Streaming::quitarTodasLasPeliculas()
{
    // Iteramos sobre el vector que contiene las películas
    for (int i = 0; i < peliculas.size(); i++)
    {
        // Borramos todas las películas
        delete peliculas[i];
    }
    // Y se lo hacemos saber al Administrador
    std::cout << "Todas las peliculas han sido borradas" << std::endl;
}

void Streaming::agregarSerie(string nombre, string genero)
{
    // Agregamos una serie al vector de series
    series.push_back(new Serie(nombre, genero));
}

void Streaming::getInfoSerie(string nombre)
{
    // Iteramos sobre la lista de series
    for (int i = 0; i < series.size(); i++)
    {
        // Si el nombre de una serie es el mismo que el que estamos buscando entonces:
        if (series[i]->getNombreSerie() == nombre)
        {
            // Mostramos la información reelevante para el usuario sobre esa serie y
            // rompemos el ciclo ya que no necesitamos seguir buscando
            series[i]->getInfoSerie();
            break;
        }
    }
}

void Streaming::agregarCapitulos(string nombreSerie, string nombreCapitulo, int numCap, float duracion, float calificacion)
{
    // generamos un avariable para el genero del capítulo
    string genero;
    // Generamos u aputnador que va a acceder a la dirección de la serie
    // donde vamos a meter el capítulo
    Serie *serieDeConsulta;
    // Iteramos sobre la lista de series
    for (int i = 0; i < series.size(); i++)
    {
        // Si el nombre de una serie es el mismo que el que estamos buscando entonces:
        if (series[i]->getNombreSerie() == nombreSerie)
        {
            // Asignamos esa serie a nuestro apuntador
            serieDeConsulta = series[i];
            // Actualizamos el ratin gde la serie
            series[i]->updateRating();
            // Le asignamos el género de la serie al capítulo
            genero = serieDeConsulta->getGenero();
            // Llamamos la funcion que agrega capítulos desde la serie
            serieDeConsulta->agregarCapitulo(numCap, nombreCapitulo, genero, duracion, calificacion);
            // Rompemos el ciclo ya que no necesitamos seguir buscando
            break;
        }
    }
}

void Streaming::borrarSerie(string nombre)
{
    // Iteramos en el vector de series
    for (int i = 0; i < series.size(); i++)
    {
        // Si el nombre de una serie es el mismo que el que estamos buscando entonces:
        if (series[i]->getNombreSerie() == nombre)
        {
            // Le hacemos saber al Administrador que la serie ser ha borrado
            std::cout << "Se ha borrado la serie '" << series[i]->getNombreSerie() << "'" << std::endl;
            // Mandamos a llamar la funcion de borrar capítulos para liberar el espacio en heap
            series[i]->borrarTodosLosCapitulos();
            // Borramos la serie de heap y del vector
            delete series[i];
        }
    }
}

void Streaming::getCapitulosDeSerie(string serie)
{
    // Itermaos en el vector de series
    for (int i = 0; i < series.size(); i++)
    {
        // Si el nombre de una serie es el mismo que el que estamos buscando entonces:
        if (series[i]->getNombreSerie() == serie)
        {
            // Llamamos la función que muestra todos los capítulos de una serie
            series[i]->listaDeCapitulos();
            break;
        }
    }
}

void Streaming::buscarPorNombre(string nombre)
{
    // Varaible donde vamos a guardar el nombre de las series y películas en minúsculas
    string current;
    int count = 0;
    // Busqueda para las peliculas
    std::cout << "\nPeliculas que contienen '" << nombre << "':" << std::endl;
    // Iteramos en el vector de películas
    for (int i = 0; i < peliculas.size(); i++)
    {
        // Le damos el nombre de la película a la variable current
        current = peliculas[i]->getNombre();
        // Usamos transform para convertir el nombre en minúsculas
        transform(current.begin(), current.end(), current.begin(), ::tolower);
        // Si encontramos la secuencia dentro de algun nombre de las películas:
        size_t found = current.find(nombre);
        if (found != string::npos)
        {
            // Llamamos la función de imprimir el nombre de esta película
            cout << peliculas[i]->getNombre() << endl;
            count++;
        }
    }
    // Si no encontramos películas, queire decir que count fue = 0
    if (count == 0)
    {
        // Con esto le decimos al usuario que no existen películas con esa secuencia de caracteres
        cout << "No hay peliculas con ese nombre\n\n";
    }
    else
        cout << "\n";
    count = 0;
    // Busqueda para las series
    std::cout << "Series que contienen '" << nombre << "':" << std::endl;
    // Iteramos en el vector de series
    for (int i = 0; i < series.size(); i++)
    {
        // Le damos el nombre de la serie a la variable current
        current = series[i]->getNombreSerie();
        // Usamos transform para convertir el nombre en minúsculas
        transform(current.begin(), current.end(), current.begin(), ::tolower);
        size_t found = current.find(nombre);
        // Si encontramos la secuencia dentro de algun nombre de las series:
        if (found != string::npos)
        {
            // Llamamos la función de imprimir el nombre de esta serie
            cout << series[i]->getNombreSerie() << endl;
            count++;
        }
    }
    // Si no encontramos películas, queire decir que count fue = 0
    if (count == 0)
    {
        // Con esto le decimos al usuario que no existen series con esa secuencia de caracteres
        cout << "No hay series con ese nombre\n\n";
    }
    else
        cout << "\n";
}
// Para la búsqueda por géneros es lo mismo que por nombre, pero en vez de acceder al 
// nombre de una serie o película, accedemos al género de estas
void Streaming::buscarPorGenero(string nombre)
{
    string current;
    int count = 0;
    //Para las peliculas
    std::cout << "\nPeliculas del genero '" << nombre << "':" << std::endl;
    for (int i = 0; i < peliculas.size(); i++)
    {
        current = peliculas[i]->getGenero();
        transform(current.begin(), current.end(), current.begin(), ::tolower);
        size_t found = current.find(nombre);
        if (found != string::npos)
        {
            cout << peliculas[i]->getNombre() << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No hay peliculas con ese genero\n\n";
    }
    count = 0;
    //Para las series
    std::cout << "Series que contienen '" << nombre << "':" << std::endl;
    for (int i = 0; i < series.size(); i++)
    {
        current = series[i]->getGenero();
        transform(current.begin(), current.end(), current.begin(), ::tolower);
        size_t found = current.find(nombre);
        if (found != string::npos)
        {
            cout << series[i]->getNombreSerie() << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "No hay series con ese genero\n\n";
    }
    else
        cout << "\n";
}