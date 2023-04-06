

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
    long long int phi = (p - 1) * (q - 1);

    //• Se comprueba que p y q son primos 

    if (isPrimeLehmanPeralta(p) && isPrimeLehmanPeralta(q)) {
        std::cout << "p y q son primos" << std::endl;
    } else {
        std::cout << "p y q no son primos" << std::endl;
        exit(0);
    }

    //Se comprueba que d es primo con phi(n)

    if (is_d_coprime(p, q, d)) {
        std::cout << "d es primo con phi(n)" << std::endl;
    } else {
        std::cout << "d no es primo con phi(n)" << std::endl;
        exit(0);
    }

    //• Se calcula e
    // e = inverso de d módulo φ(n)
    int e;
    int x, y;
    int gcd = gcdExtended(d, phi, x, y);
    if (x < 0) {
        e = phi + x;
    } else {
        e = x;
    }

    std::cout << "e = " << e << std::endl;

    //Se busca el valor de j 26^j-1<n<26^j

    int j = std::ceil(std::log(n+1)/std::log(26));
    std::cout << "j = " << j << std::endl;

    //Se pasa cada bloque a decimal para poder cifrar

    std::string encoded_text = encode(original_text, j-1);

    std::cout << encoded_text << std::endl;


    //Se calcula en decimal el texto cifrado
    std::vector<long long int> encoded_text_vector = splitString(encoded_text);

    for (int i = 0; i < encoded_text_vector.size(); i++) {
        std::cout << encrypt(encoded_text_vector.at(i), e, n)<< " ";
    }

    std::cout << std::endl;

    return 0;
}