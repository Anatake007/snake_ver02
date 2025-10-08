# Snake

## Denumirea jocului
Snake

## Descrierea jocului
Snake este un joc clasic în care jucătorul controlează un șarpe care se mișcă pe o tablă. Scopul este să mănânci mâncarea (food) pentru a crește în lungime fără a lovi pereții sau propriul corp.

## Regulile jocului
1. Șarpele se mișcă într-o direcție (sus, jos, stânga, dreapta).
2. La fiecare pas, capul avansează cu o celulă; restul corpului urmează.
3. Dacă șarpele mănâncă mâncarea, el crește (nu i se scade coada în acest pas).
4. Jocul se termină dacă șarpele iese din tabla de joc sau lovește o parte din corpul său.
5. Scorul crește cu 1 pentru fiecare mâncare consumată.

## Descrierea fiecărei structuri de date (rol / sarcină)
- **Position**: Reprezintă o poziție (x, y) pe tablă.
- **Direction**: Enumerație pentru direcții (Up, Down, Left, Right).
- **Board**: Reprezintă tabla de joc; verifică limitele și conține utilitare legate de poziții valide.
- **Snake**: Ține corpul șarpelui (deque de `Position`), direcția curentă și operații: `move`, `grow`, `occupies`.
- **Food**: Reprezintă mâncarea; are o poziție și poate fi plasată aleator pe tablă.
- **GameEngine**: Coordonează jocul — actualizează starea, detectează coliziuni, gestionează scorul și plasarea alimentelor.

## Cum să construiești și să rulezi (exemplu)
Acest exemplu folosește CMake (opțional). Pași corespunzători:
```bash
mkdir build
cd build
cmake ..
cmake --build .
./snake
```

## Cerințe pentru laborator
- Înregistrează-te pe GitHub și creează un repository nou (de ex. `snake-game`).
- Clonează repo local sau încarcă fișierele create aici.
- Creează un branch `lab01`, încarcă codul în `lab01` și creează un Pull Request către `main`.
