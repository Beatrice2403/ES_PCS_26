#include <iostream>
#include "Eigen/Eigen"
#include "gradiente_coniugato.hpp"



int main() 
{
    const double tol = 1.0e-15;
    unsigned int n = 5;

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    if (abs(B.determinant()) < tol)
    return -1;
    Eigen::MatrixXd A = B.transpose() * B;

    /*stampo il condizionamento di A*/
    std::cout.precision(2);
    std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;

    Eigen::VectorXd x_esatta = Eigen::VectorXd::Ones(n);

    /*Ora scelgo come x0 un vettore di tutti zeri, perchè più vantaggioso 
    per il ciclo while all'interno della funzione gradiente_coniugato, 
    ma potrei sceglierlo anche randomico con:
    Eigen::VectorXd x0 = Eigen::VectorXd::Random(n)*/
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    Eigen::VectorXd b = A * x_esatta;

    Eigen::VectorXd r = b - A * x0;
    double r_norm_0 = r.norm();
    const double r_tol = 1.0e-12;

    /*uso la funzione gradiente coniugato per calcolarmi la x soluzione, 
    partendo da una x0 di input randomica*/
    Eigen::VectorXd x = gradiente_coniugato(A,x0,b,r,r_tol);

    
    std::cout.precision(4);
    /*stampo x0 iniziale*/
    std::cout<< std::scientific<< "x0:"<< std::endl;
    std::cout<< std::scientific<< x0 << std::endl;
    /*stampo la misura relativa della riduzione del residuo*/
    std::cout<< std::scientific<< "r"<< "/"<< "r_tol: "<<r.norm() / r_norm_0<< "/"<< r_tol<< std::endl;
    /*stampi la soluzione finale del metodo del gradiente*/
    std::cout<< std::scientific<< "soluzione:"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;
    /*mi calcolo l'errore relativo tra x_esatta e la soluzione, e lo stampo*/
    const auto err_rel = (x_esatta.norm() == 0.0) ? (x - x_esatta).norm() : (x - x_esatta).norm() / x_esatta.norm();
    std::cout<< std::scientific << "err_rel: "<< err_rel << std::endl;


    return 0;
}
