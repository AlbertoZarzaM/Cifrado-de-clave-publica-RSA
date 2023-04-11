

#include "funciones.h"


int main() {
   std::string original_text;
    std::cout << "Introduce el texto original: ";
    std::getline(std::cin, original_text);
    std::cout << std::endl;

    long long int p;
    std::cout << "Introduce el valor de p: ";
    std::cin >> p;
    std::cout << std::endl;

    long long int q;
    std::cout << "Introduce el valor de q: ";
    std::cin >> q;
    std::cout << std::endl;

    int d;
    std::cout << "Introduce el valor de d: ";
    std::cin >> d;
    std::cout << std::endl;

    long long int n = p * q;
    long int phi = (p - 1) * (q - 1);

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "phi = " << phi << std::endl;

    //• Se comprueba que p y q son primos 

    if (isPrimeLehmanPeralta(p) && isPrimeLehmanPeralta(q)) {
        std::cout << "p y q son primos" << std::endl;
    } else {
        std::cout << "p y q no son primos" << std::endl;
    }



    //• Se calcula e
    // e = inverso de d módulo φ(n)
    //int e;
    long int x, y;
   // std::cout << "phi1: " << phi << " d1: " << d << std::endl;
    long int gcd = euclides_extendido(phi, d);

    //Se comprueba que d es primo con phi(n)
    if (gcd != -1) {
        std::cout << "d es primo con phi(n)" << std::endl;
    } else {
        std::cout << "d no es primo con phi(n)" << std::endl;
    }
    
    std::cout << "e = " << gcd << std::endl;

    //Se busca el valor de j 26^j-1<n<26^j

    int j = std::ceil(std::log(n+1)/std::log(26));
    std::cout << "j = " << j << std::endl;

    //Se pasa cada bloque a decimal para poder cifrar

    std::string encoded_text = encode(original_text, j-1);

    std::cout << encoded_text << std::endl;


    //Se calcula en decimal el texto cifrado
    std::vector<long long int> encoded_text_vector = splitString(encoded_text);

    for (int i = 0; i < encoded_text_vector.size(); i++) {
        std::cout << encrypt(encoded_text_vector.at(i), gcd, n)<< " ";
    }

    std::cout << std::endl;

    return 0;
}