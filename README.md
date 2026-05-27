# Proiect Programarea Algoritmilor 

Acest proiect analizează date financiare și prețuri ale acțiunilor de pe bursă, fiind împărțit în 4 task-uri diferite. Programul își dă seama singur ce are de făcut în funcție de formatul datelor din fișierul de intrare.

##  Structura proiectului

* **`biblioteci.h`** – conține structurile de date și prototipurile funcțiilor.
* **`functii.c`** – conține implementarea efectivă a funcțiilor utilizate.
* **`interviu1.c`** – conține funcția `main`, unde citesc argumentele, identific task-ul, deschid fișierele și pornesc rezolvarea.


### Compilare în terminal:
```bash
gcc -g *.c -o proiect -lm
```

### Rulare:
```bash
./proiect fisier_intrare.txt fisier_iesire.txt
```

##### Proiectul este împărțit în 4 cerințe mari:


* Task 1 : Citesc prețurile unei acțiuni și le salvez într-o listă simplu înlănțuită. Calculez randamentul zilnic, media randamentelor și volatilitatea , iar la final scorul Sharpe.



* Task 2 : Citesc datele pentru 3 acțiuni. Deoarece în fișier ele sunt puse invers cronologic, le bag mai întâi într-o stivă ca să le pot scoate în ordinea corectă a zilelor. Apoi compar prețurile ca să văd care acțiune diferă prea mult de restul.



* Task 3 : Clasific 10 companii în funcție de cum le evoluează prețul. Fac un arbore binar: dacă prețul scade față de ziua trecută o iau pe nodul din stânga, dacă crește o iau pe dreapta. Companiile care au același istoric de creșteri/scăderi vor ajunge în același nod.



* Task 4 : Împart prețurile în niște "stări" și calculez probabilitățile de trecere dintr-o stare în alta. Am făcut o structură Fractie (cu numărător și numitor) și fac toate calculele, simplificând mereu cu CMMDC.


##### Ce se mai poate îmbunătăți la cod:

---

* Problema cu Overflow-ul la Task 4:La numere foarte mari de zile, numitorul și numărătorul fracțiilor cresc extrem de mult și pot depăși capacitatea unui long long. S-ar putea utiliza o structura pentru numere mari;



* Citirea din fișier în main: Deschid fișierul o dată ca să văd ce task am, îl închid și îl redeschid ca să citesc datele. S-ar putea optimiza citind totul într-un buffer de la început.





