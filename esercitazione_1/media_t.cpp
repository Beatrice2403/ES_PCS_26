using namespace std;
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc<2) {
    cout << "Errore: nome del file non specificato";
  }

  ifstream ifs(argv[1]);
  if (ifs.is_open()) {
    string citta;
    double temp[4];
    double somma=0;
    double media=0;
    int x=4;

    while( ifs >> citta >> temp[0] >> temp[1] >> temp[2] >> temp[3]) {
      somma=0;
      for (int i=0; i<x; i++) {
        somma=somma+temp[i];
      }
      media=somma/x;
      cout << citta << " " << media << "\n";
    }
  } else {
    cout << "Errore nell'apertura del file";
  }
  return 0;
}