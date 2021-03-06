/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - 
 * Autores (por nombre):
 * 	Alexis Baladon 
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef IALTAUsuario
#define IALTAUsuario

#include <string>

using std::string;

class DtUsuario;

class IAltaUsuarioController{
public:
    virtual int ingresarUsuario(DtUsuario)=0;
    virtual void ingresarEmpresa(string)=0;
    virtual bool ingresarNickname(string)=0;
    virtual void ingresarDescripcion(string)=0;
    virtual void confirmarDarDeAltaUsuario()=0;
    virtual int iniciarSesion()=0;
    virtual string getLoggedName()=0;
    virtual void clearCache()=0;
    virtual bool hayUsuarios()=0; // Devuelve true si existen usuarios registrados en el sistema.
    
    virtual ~IAltaUsuarioController(){}
};

#endif
