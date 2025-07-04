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
