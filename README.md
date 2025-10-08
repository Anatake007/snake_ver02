
🐍 Snake Game — Lucrare de laborator Nr. 2

📘 Descrierea proiectului
Acest proiect reprezintă o implementare simplificată a jocului clasic „Snake”, realizată în limbajul C++ utilizând principiile programării orientate pe obiecte.
Scopul lucrării este de a evidenția utilizarea claselor, metodelor și interacțiunii dintre obiecte, precum și procesul de construire a proiectului din linia de comandă.

🧩 Structura proiectului
lab02_snake_project/
├── Board.hpp / Board.cpp        - Clasa pentru tabla de joc
├── Direction.hpp                - Enumerație pentru direcții
├── Food.hpp / Food.cpp          - Clasa pentru mâncare
├── Position.hpp                 - Structură pentru coordonate
├── Snake.hpp / Snake.cpp        - Clasa pentru șarpe
├── GameEngine.hpp / GameEngine.cpp  - Motorul principal al jocului
├── main.cpp                     - Punctul de intrare în program
└── README.txt                   - Descrierea proiectului

⚙️ Funcționalitate
- Control prin tastatură: W, A, S, D
- Deplasare automată a șarpelui
- Generarea aleatorie a mâncării
- Calcularea scorului
- Detectarea coliziunilor (cu pereții sau cu propriul corp)

🧠 Clase utilizate
- Board — gestionează dimensiunea și limitele tablei de joc.
- Position — reține coordonatele (x, y).
- Direction — definește direcțiile posibile de mișcare.
- Food — reprezintă obiectul „mâncare” din joc.
- Snake — gestionează corpul șarpelui și creșterea acestuia.
- GameEngine — controlează logica principală a jocului.

🎮 Controale
W - Mișcare în sus
S - Mișcare în jos
A - Mișcare la stânga
D - Mișcare la dreapta

🧾 Autor
Nume: Lilia Miсușa
Facultate: Informatică / Game Design
Proiect: Lucrare de laborator Nr. 2 — Snake Game
Anul: 2025
