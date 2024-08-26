#include <iostream>
#include <string>

const int kAnimesQuantity = 1;

struct Estudio {
  std::string nombre;
  std::string pais;
};

struct Anime {
  std::string titulo;
  std::string fecha_estreno; 
  int temporadas;
  double calificacion;
  Estudio estudio;
};

Anime AddAnime(int index) {
    Anime nuevo_anime;

    std::cout << "Ingrese los datos para el anime #" << (index + 1) << ":\n";

    // Datos del anime
    std::cout << "Ingrese el título del anime: ";
    //getline --> Lee toda una línea de texto hasta encontrar un salto de línea
    // std::ws --> Elimina cualquier espacio en blanco inicial antes de leer la cadena de texto.
    std::getline(std::cin >> std::ws, nuevo_anime.titulo); 

    std::cout << "Ingrese la fecha de estreno del anime (DD/MM/YYYY): ";
    std::getline(std::cin, nuevo_anime.fecha_estreno);

    std::cout << "Ingrese la calificación del anime (1.0 - 10.0): ";
    std::cin >> nuevo_anime.calificacion;

    std::cout << "Ingrese la cantidad de temporadas del anime: ";
    std::cin >> nuevo_anime.temporadas;

    // Datos del estudio

    //cin.ignore <- se utiliza para limpiar cualquier carácter residual en el buffer de entrada
    std::cin.ignore();  
    std::cout << "Ingrese el nombre del estudio de animación: ";
    std::getline(std::cin, nuevo_anime.estudio.nombre);

    std::cout << "Ingrese el país del estudio de animación: ";
    std::getline(std::cin, nuevo_anime.estudio.pais);

    return nuevo_anime;
}

void IncreaseSeason(Anime animes[], int num_animes) {
    for (int i = 0; i < num_animes; ++i) {
        animes[i].temporadas++;
        std::cout << "\nEl anime \"" << animes[i].titulo << "\" ha aumentado a " << animes[i].temporadas << " temporadas.\n";
    }
}

double CalculateAverageRating(const Anime animes[], int num_animes) {
    double total_rating = 0;
    for (int i = 0; i < num_animes; ++i) {
        total_rating += animes[i].calificacion;
    }
    return total_rating / num_animes;
}

void ShowAnimes(const Anime animes[], int num_animes) {
    for (int i = 0; i < num_animes; ++i) {
        std::cout << "\nAnime #" << (i + 1) << ":\n";
        std::cout << "Título: " << animes[i].titulo << "\n";
        std::cout << "Fecha de estreno: " << animes[i].fecha_estreno << "\n";
        std::cout << "Temporadas: " << animes[i].temporadas << "\n";
        std::cout << "Calificación: " << animes[i].calificacion << "\n";
        std::cout << "Estudio: " << animes[i].estudio.nombre << " (" << animes[i].estudio.pais << ")\n";
        std::cout << "--------------------------\n";
    }
}

int main(int argc, char* argv[]) {
    Anime animes[kAnimesQuantity];
    int num_animes = 0;

    // Agregando los animes
    for (int i = 0; i < kAnimesQuantity; ++i) {
        animes[num_animes] = AddAnime(i);
        num_animes++;
    }

    //Mostrando los animes
    ShowAnimes(animes, num_animes);

    // Calculando promedio de rating
    CalculateAverageRating(animes, num_animes);


    //Incrementando temporadas
    IncreaseSeason(animes, num_animes);

    //Mostrando las temporadas de nuevo
    ShowAnimes(animes, num_animes);

    return 0;
}
