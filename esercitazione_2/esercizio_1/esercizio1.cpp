# include <iostream>

int main() 
{
  double ad[4] = {0.0, 1.1, 2.2, 3.3};
  float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  int ai[3] = {0,1,2};
  
  int x = 1;
  float y = 1.1;

  (&y)[1] = 0;
  
  std::cout <<"VARIABILE X: "<< x << "\n";
  
  std::cout <<"ARRAY DOUBLE: "<< "\n";
  for (int i=0; i<4; i+=1) {
    std::cout <<"indirizzo del componente "<< i << " di ad:" << &ad[i] << "\n";
  }

  std::cout <<"ARRAY FLOAT: "<< "\n";
  for (int i=0; i<8; i+=1) {
    std::cout <<"indirizzo del componente "<< i << " di af: " << &ad[i] << "\n";
  }
  
  std::cout <<"ARRAY INT: "<< "\n";
  for (int i=0; i<3; i+=1) {
    std::cout <<"indirizzo del componente "<< i << " di ai: " << &ad[i] << "\n";
  }
  
  std::cout << "indirizzo variabile x: "<<&x << "\n";
  std::cout << "indirizzo variabile y: "<<&y << "\n";
  return 0; 
}
