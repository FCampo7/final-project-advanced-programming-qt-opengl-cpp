#include "metadato.h"

void Metadato::CargarMetadato(string f, string s){
    contenido.insert(make_pair(f, s) );
}

unsigned int Metadato::TamMet(){
    return contenido.size();
}

void Metadato::VaciarMetadato(){
    contenido.clear();
}

void Metadato::ModifMeta(string clave, string valor){
    contenido[clave]=valor;
}

string Metadato::VerMetadatos(){
    string s="";
    for(map<string, string>::iterator it=contenido.begin(); it!=contenido.end(); it++){
        s+=it->first + ": " + it->second + "\n";
	}
	s=s.substr(0, s.length()-1);//Eliminar el ultimo caracter
    return s;
}

string Metadato::GuardarMetadatos(){
    string s="";
    for(map<string, string>::iterator it=contenido.begin(); it!=contenido.end(); it++){
        s+=it->first + ":" + it->second + ";";
    }
	s=s.substr(0, s.length()-1);//Eliminar el ultimo caracter
    return s;
}
