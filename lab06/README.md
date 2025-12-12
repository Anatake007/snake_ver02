# 🐍 Snake Game — Lucrare de laborator Nr. 6

## 📘 Descrierea proiectului
Acest proiect este o implementare simplificată a jocului clasic **„Snake”**, realizată în **C++17** (OOP).
În lab06 au fost adăugate:
- documentația codului cu **Doxygen** (în fișierele antet);
- directorul **tests/** cu teste unitare pentru clasele de date;
- actualizarea fișierelor de construire (CMake) pentru compilare/rulare teste și generare documentație.

## 🎮 Regulile jocului
- Șarpele se deplasează pe tabla de joc în una din direcțiile: **Up/Down/Left/Right**.
- Dacă șarpele mănâncă mâncarea, **scorul crește** și șarpele **se mărește**.
- Jocul se termină dacă șarpele iese din tablă sau se lovește de propriul corp.

## 🧩 Dependențe
- **CMake** 3.15+
- Compilator cu suport **C++17** (g++, clang, MSVC)
- **Catch2** pentru teste (se descarcă automat prin CMake FetchContent)
- **Doxygen** (opțional, pentru generarea documentației)

## 🏗️ Construire și rulare (CMake)
### Build aplicație
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Rulare aplicație
```bash
./game
```
Pe Windows:
```bat
game.exe
```

### Rulare teste
```bash
ctest --output-on-failure
```

### Generare documentație
Dacă Doxygen este instalat:
```bash
cmake --build . --target docs
```
Documentația HTML: `build/docs/html/index.html`

## 🧾 Autor
- Autor: Lilia Miсușa
- An: 2025
