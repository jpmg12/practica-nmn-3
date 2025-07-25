#include <iostream>
#include <vector>
using namespace std;


class Publicacion {
private:
    string titulo;
    string autor;
    int anoPublicacion;

public:
    Publicacion(string t, string a, int anio) : titulo(t), autor(a), anoPublicacion(anio) {}
    virtual ~Publicacion() {}

	void setTitulo(string t) { titulo = t; }
    void setAutor(string a) { autor = a; }
    void setAnoPublicacion(int ano) { anoPublicacion = ano; }
    
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    int getAnoPublicacion() { return anoPublicacion; }

    virtual void mostrarInfo() {
        cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nAno de Publicacion: " << anoPublicacion << endl;
    }
};


class Libro : public Publicacion {
private:
    int numPaginas;

public:
    Libro(string t, string a, int ano, int paginas) : Publicacion(t, a, ano), numPaginas(paginas) {}
	
	void setNumPaginas(int paginas) { numPaginas = paginas; }
    int getNumPaginas() { return numPaginas; }

    void mostrarInfo() override {
        Publicacion::mostrarInfo();
        cout << "Numero de Paginas: " << numPaginas << "\nTipo: Libro\n" << endl;
    }
};

class Revista : public Publicacion {
private:
    int numeroEdicion;

public:
    Revista(string t, string a, int ano, int edicion) : Publicacion(t, a, ano), numeroEdicion(edicion) {}

	void setNumeroEdicion(int edicion) { numeroEdicion = edicion; }
    int getNumeroEdicion() { return numeroEdicion; }
  
    void mostrarInfo() override {
        Publicacion::mostrarInfo();
        cout << "Numero de Edicion: " << numeroEdicion << "\nTipo: Revista\n" << endl;
    }
};

void agregarPublicacion(vector<Publicacion*>& biblioteca) {
    int opcion;
    cout << "Seleccione el tipo de publicacion:\n1. Libro\n2. Revista\nOpcion: ";
    cin >> opcion;
    cin.ignore();

    string titulo, autor;
    int anio;
    cout << "Ingrese el titulo: ";
    getline(cin, titulo);
    cout << "Ingrese el autor: ";
    getline(cin, autor);
    cout << "Ingrese el ano de publicacion: ";
    cin >> anio;

    if (opcion == 1) {
        int paginas;
        cout << "Ingrese el numero de paginas: ";
        cin >> paginas;
        biblioteca.push_back(new Libro(titulo, autor, anio, paginas));
    } else if (opcion == 2) {
        int edicion;
        cout << "Ingrese el numero de edicion: ";
        cin >> edicion;
        biblioteca.push_back(new Revista(titulo, autor, anio, edicion));
    } else {
        cout << "Opci�n no valida.\n";
    }
}

void mostrarPublicaciones(const vector<Publicacion*>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "No hay publicaciones registradas.\n";
        return;
    }
    for (size_t i = 0; i < biblioteca.size(); ++i) {
        cout << "\nIndice: " << i << endl;
        biblioteca[i]->mostrarInfo();
    }
}

void eliminarPublicacion(vector<Publicacion*>& biblioteca) {
    if (biblioteca.empty()) {
        cout << "No hay publicaciones para eliminar.\n";
        return;
    }
    int indice;
    cout << "Ingrese el indice de la publicacion a eliminar: ";
    cin >> indice;
    if (indice >= 0 && indice < biblioteca.size()) {
        delete biblioteca[indice];
        biblioteca.erase(biblioteca.begin() + indice);
        cout << "Publicacion eliminada correctamente.\n";
    } else {
        cout << "Indice no valido.\n";
    }
}

int main() {
    vector<Publicacion*> biblioteca;
    int opcion;

    do {
        cout << "\n Menu=Agregar Publicacion\n2. Mostrar Publicaciones\n3. Eliminar Publicacion\n4. Salir\nOpcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarPublicacion(biblioteca);
                break;
            case 2:
                mostrarPublicaciones(biblioteca);
                break;
            case 3:
                eliminarPublicacion(biblioteca);
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);

    for (size_t i = 0; i < biblioteca.size(); ++i) {
        delete biblioteca[i];
    }
    biblioteca.clear();

    return 0;
}

