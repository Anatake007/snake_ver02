# README - Laboratorul 4

## Modificări efectuate

În cadrul laboratorului 4, codul jocului „Snake” a fost rescris pentru a utiliza biblioteca standard C++ (STL) în locul structurilor și pointerilor tradiționali.

### Schimbări principale:
1. **Containere STL**  
   În loc de tablouri sau structuri personalizate, s-au utilizat containere STL precum `std::deque`, `std::vector` și `std::string`.

2. **Smart Pointers**  
   În locul alocării dinamice cu `new` și `delete`, s-au folosit pointeri inteligenți (`std::unique_ptr` și `std::shared_ptr`) pentru o gestionare sigură a memoriei.

3. **Fluxuri de intrare/ieșire (I/O)**  
   Afișarea și citirea datelor se face prin `std::cout` și `std::cin` din biblioteca `<iostream>`, în loc de funcții tradiționale C.

4. **Algoritmi STL**  
   Au fost folosiți algoritmi standard precum `std::find`, `std::sort`, `std::copy`, `std::any_of` pentru a simplifica logica jocului.

5. **Șiruri de caractere**  
   Tipul `std::string` a înlocuit toate șirurile de caractere C (`char[]` sau `char*`), oferind siguranță și flexibilitate.

6. **Generalizare și siguranță**  
   Codul a fost modernizat conform standardului C++17+, folosind referințe constante și inițializatori de listă.
