#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Registro {
private:
  string mes;
  string dia;
  string horas;
  string minutos;
  string segundos;
  string ip;
  string puerto;
  string falla;

  vector<string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  // https://cplusplus.com/reference/ctime/tm/
  struct tm dateStruct;
  // Linux timestamp (segundos transcurridos desde el 1 de enero de 1970)
  time_t fechaHora;

public:
  Registro();
  Registro(string _mes, string _dia, string _horas, string _minutos, string _segundos, string _ip, string _puerto, string _falla);
  string getAll();
  // sobrecarga de operadores de comparacion
  bool operator==(const Registro &other) const;
  bool operator!=(const Registro &other) const;
  bool operator>(const Registro &other) const;
  bool operator<(const Registro &other) const;
  bool operator>=(const Registro &other) const;
  bool operator<=(const Registro &other) const;
};

#endif // _REGISTRO_H_
