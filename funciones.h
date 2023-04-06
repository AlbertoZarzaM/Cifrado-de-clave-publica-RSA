
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

std::vector<long long int> splitString(std::string input) {
    std::vector<long long int> values;
    std::stringstream ss(input);
    long long int temp;
    while (ss >> temp) {
        values.push_back(temp);
    }
    return values;
}

long long int exponenciacionRapida(long long int a, long long int b, int n) {
    
  long long int x = 1;
  long long int y = a % n;
    while ((b > 0) && (y > 1)) {
        if (b % 2 == 1) {
            x = (x * y) % n;
        }
        y = (y * y) % n;
        b = b / 2;
    }
    return x % n;
}

std::string encode(std::string text, int j) {
    //eliminar espacios de text
    text.erase(std::remove_if(text.begin(), text.end(), [](char c) { return std::isspace(c); }), text.end());
    std::string encoded = "";
    int block_size = j;
    int num_blocks = ceil((double)text.length() / (double)block_size);
    int padding = block_size - text.length() % block_size;
    
    // Add padding X's if necessary
    if (padding != block_size) {
        for (int i = 0; i < padding; i++) {
            text += 'X';
        }
    }
    
    // Encode each block of the text
    for (int i = 0; i < num_blocks; i++) {
        int block_value = 0;
        for (int j = 0; j < block_size; j++) {
            char c = text[i*block_size+j];
            int char_value = c - 'A';
            block_value += char_value * pow(26, block_size-j-1);
        }
        encoded += std::to_string(block_value) + " ";
    }
    
    return encoded;
}


//comprobar son números primos (con el test de Lehman-Peralta)

bool isPrimeLehmanPeralta(long long int p) {
 
    // Comprobar que p no es divisible por ningún primo pequeño
    if (p == 2 || p == 3 || p == 5 || p == 7 || p == 11) {
        return true;
    } 
    else if ( p % 2 == 0 || p % 3 == 0 || p % 5 == 0 || p % 7 == 0 || p % 11 == 0) {
            return false;
    }

    else {
        // Elegir enteros aleatorios ai entre 2 y p-1
        srand(time(NULL));
        for (int i = 0; i < 50; i++) {
            long long a = 2 + rand() % (p - 2);

            // Si ai (P-1)/2 != 1 (mod p), p es compuesto
            long long exp = (p - 1) / 2;
            long long result = exponenciacionRapida(a, exp, p);
            if (result != 1 && result != p - 1) {
                return false;
            }

            // Si ai (p-1)/24-1 (mod p), p es compuesto
            exp = (p - 1) / 24;
            result = exponenciacionRapida(a, exp, p);
            if (result == p - 1) {
                return true;
            }
        }

        // Si no se encontró ningún i tal que ai (p-1)/24-1 (mod p), p tal vez es primo
        return true;
    }
}

int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcdExtended(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return gcd;
}

bool is_d_coprime(int p, int q, int d) {
    int phi = (p-1)*(q-1);
    int x, y;
    int gcd = gcdExtended(d, phi, x, y);
    return (gcd == 1);
}


long long int encrypt(long long int m, int e, int n) {
    return exponenciacionRapida(m, e, n);
}


