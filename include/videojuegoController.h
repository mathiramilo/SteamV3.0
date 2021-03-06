/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef VideojueGoController
#define VideojueGoController

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "handlerCatalogo.h"
#include "handlerEstadistica.h"
#include "handlerCategoria.h"
#include "handlerUsuario.h"
#include "iVideojuegoController.h"
#include "usuario.h"
#include "jugador.h"
#include "desarrollador.h"
#include "videojuego.h"
#include "categoria.h"
#include "dtCategoria.h"
#include "dtVideojuego.h"
#include "dtSuscripcion.h"
#include "suscripcion.h"
#include "dtEstadistica.h"
#include "partida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"

using std::vector;
using std::string;
using std::cout;
using std::map;
using std::set;

class DtCategoria;
class DtEstadistica;
enum class TipoSuscripcion;
enum class TipoPago;

class VideojuegoController: public IVideojuegoController{
private:
    DtVideojuego datos;
    DtCategoria catData;
    TipoPago tPago;
    TipoValido tSus; //SUS!?
    Usuario * loggedUser; //Player OR Dev. depening on usecase under execution.
    Videojuego * videoCache;
    std::map<std::string,Categoria *> * categoriaCache;
    bool exGen, exPlatf;

    VideojuegoController();
public:
    set<string> *obtenerNombreVideojuegosDesarrollados();
    set<string> *obtenerNombreVideojuegosInactivos();
    vector<set<DtVideojuego>> *obtenerSuscripcionesVideojuegos();
    set<DtCategoria> *obtenerCategoriasGenero();
    set<DtCategoria> *obtenerCategoriasPlataforma();
    set<DtCategoria> *obtenerCategoriasOtro();
    set<DtEstadistica> *obtenerEstadisticas(string);
    void ingresarDatosVideojuego(DtVideojuego);
    void ingresarSuscripcion(TipoValido,TipoPago);
    void seleccionarVideojuego(string);
    void seleccionarGenero(string);
    void seleccionarPlataforma(string);
    void seleccionarCategoriaOtro(string);
    void confirmarPublicacion();
    void confirmarSuscripcion();
    void confirmarEliminarVideojuego();
    void cancelarSuscripcion();
    void clearCache();
    
    void setLoggedUser(Usuario *);
    //setDatos // Equivalente a ingresarDatosvideojuego

    //Caso de uso PublicarVideojuego:
    bool existeVideojuego(string);  
    bool hayCategorias();
    
    //Caso de uso AgregarCategoria:
    set<string>* obtenerNombreCategorias();
    int cargarCategoria(DtCategoria);
    void confirmarAgregarCategoria();

    //Caso de uso VerInformacionVideojuego:
    set<string> * obtenerNombreCatVideojuego();
    vector<string> * obtenerInfoVideojuegoExtra();

    //Caso de uso PuntuarVideojuego
    set<DtVideojuego>* verVideojuegos();
    int puntuar(string,int);

    //Caso de uso SuscribirseVideojuego
    DtSuscripcion getSuscripcion(string);
    
    //Caso de uso seleccionarEstadisticas
    set<DtEstadistica> * obtenerEstadisticas();
    set<DtEstadistica> * obtenerEstadisticasInv();
    void cargarEstadisticas(set<string>);

    static VideojuegoController * getInstance();
    ~VideojuegoController();
};

#endif
