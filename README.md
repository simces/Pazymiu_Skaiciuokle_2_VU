# Pažymių skaičiuoklė

Ši programa geba apskaičiuoti studentų pažymių vidurkį arba medianą pagal Jūsų įvestus duomenis. Taip pat yra galimybė pažymius generuoti **atsitiktinai**.

## Programos funkcijos

Programa nuskaito šiuos vartotojo įvestus duomenis:
- Vardą ir pavardę;
- **n** atliktų namų darbų rezultatus;
- **egzamino** rezultatą.

 Programa taip pat gali nuskaityti duomenis iš failo.

## Programos rezultatas

Su gautais duomenimis programa apskaičiuoja galutinį pažymį, arba vartotojui pasirinkus, medianą. Galutinis pažymys skaičiuojamas pagal šią formulę:

𝕲𝖆𝖑𝖚𝖙𝖎𝖓𝖎𝖘 = 𝟎,𝟒 ⋅ 𝐯𝐢𝐝𝐮𝐫𝐤𝐢𝐬 + 𝟎,𝟔 ⋅ 𝐞𝐠𝐳𝐚𝐦𝐢𝐧𝐚𝐬

## Programos pavyzdys

```
Vardas      Pavarde         Galutinis (Vidurkis)
------------------------------------------------------------
Vardas      Pavarde              5.00
Vardenis    Pavardenis           6.75
```

## Programos įdiegimas

### (1 būdas) Atsisiuntę pasirinktą programos versiją .zip formatu ją išarchyvuokite.    Programos kodą sukompiliuokite per komandinę eilutę arba per Jums patinkantį IDE (VSCode, Visual Studio, CodeBlocks, etc.)

### (2 būdas) Antran būdui naudosime programą CMake. Programoje ``` Where is the source code: ``` pasirinksime aplanką su visais programos failais, o eilutėje ``` Where to build binaries``` pasirinksime aplanką, kuriame atsiras mūsų programa.

![image](https://user-images.githubusercontent.com/78842398/122346664-e4a12a00-cf51-11eb-8e77-f095ad5e75b9.png)

* Toliau paspaudę ``` Configure ``` pasirenkame mums tinkančius nustatymus. 

![image](https://user-images.githubusercontent.com/78842398/122346745-f97dbd80-cf51-11eb-855b-3b6581bd7097.png)

* Galiausiai spaudžiame ``` Generate ``` ir truputį palaukiame kol visi reikiami failai atsiras mūsų anksčiau pasirinktame aplanke.



## Programos veikimo sparta

|               | 1000     | 10000    | 100000   | 1000000  | 10000000 |
| ------------- |----------| ---------|----------|----------|----------|
|   Vector      |          |          |          |          |          |
| Nuskaitymas   | 0.016s   |  0.095s  |  1.02s   |  8.87s   | 64.654s  |
| Rūšiavimas    | 0.122s   |  0.01s   |  0.059s  |  0.776s  | 8.522s   |
|    List       |          |          |          |          |          |
| Nuskaitymas   | 0.014s   | 0.148s   | 1.232s   | 7.529s   | 87.119s  |
| Rūšiavimas    | 0.001s   | 0.009s   | 0.079s   | 0.661s   | 6.954s   |
|    Deque      |          |          |          |          |          |
| Nuskaitymas   | 0.012s   | 0.102s   | 1.113s   | 8.552s   | 87.766s  |
| Rūšiavimas    | 0.001s   | 0.009s   | 0.071s   | 0.606s   | 6.246s   |

Naudoto kompiuterio specifikacijos: i5-9300h 2.40 - 4.10 GHz, 16GB DDR4 RAM @2660 MHz, SSD;

## Programos veikimo spartos dvejomis strategijomis palyginimas

|                      | 1000     | 10000    | 100000   | 1000000  | 10000000 |
| -------------------- |----------| ---------|----------|----------|----------|
| 	**Vector**          |          |          |          |          |          |
| Dviejų konteinerių   | 0.152s   | 0.119s   | 1.261s   | 10.276s  | 78.135s  |
| Vieno konteinerio    | 0.015s   | 0.159s   | 1.744s   | 17.342s  | 112.154s |
| 	**Deque**           |          |          |          |          |          |
| Dviejų konteinerių   | 0.013s   | 0.111s   | 1.184s   | 9.158s   | 94.012s  |
| Vieno konteinerio    | 0.013s   | 0.158s   | 1.825s   | 18.163s  | 99.578s  |
|	 **List**            |          |          |          |          |          |
| Dviejų konteinerių   | 0.015s   | 0.157s   | 1.311s   | 8.19s    | 94.073s  |
| Vieno konteinerio    | 0.013s   | 0.123s   | 1.281s   | 12s      | 98.204s  |

Realizuojant rūšiavimo algoritmą naudojant vieną konteinerį vietoj dviejų, ženkliai sulėtėjo ```vector``` ir ```deque``` konteinerių rūšiavimo sparta. ```list``` konteineriui tai neturėjo įtakos. Norint stabilizuoti ir paspartinti ```vector``` ir ```deque``` konteinerių rūšiavimus, buvo panaudotas ```partition``` algoritmas.

## Programos veikimo spartos palyginimas naudojant "Studentas" klasę vietoj struktūros

| **Vector**           | 100000   | 1000000  |
| -------------------- |----------| ---------|
| Struct               | 1.744s   | 17.342s  |
| Class                | 2.155s   | 19.861s  |
| Class(O1 flag)       | 1.212s   | 8.892s   |
| Class(O2 flag)       | 1.296s   | 8.688s   |
| Class(O3 flag)       | 1.287s   | 8.756s   |


## Versijos

* [v0.1](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.1) Įgyvendintas esminis programos funkcionalumas.


* [v0.1.5](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.1.5) Minimaliai patobulinta pradinė programos versija.


* [v0.2](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.2) Pridėta galimybė skaityti duomenis iš failo.


* [v0.3](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.3) Pridėtas išimčių valdymas. (Exception handling)


* [v0.4](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.4) Pridėta galimybė generuoti studentų sąrašų failus, studentų rikiavimas pagal pažymius, sukurti funkcijos.cpp ir funkcijos.h failai

    
* [v0.5](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v0.5) Programos spartumo patikrinimas  

* [v1.0](https://github.com/simces/Pazymiu_Skaiciuokle/releases/tag/v1.0) Pridėta galimybė paleisti programą naudojant CMake, ištestuota veikimo sparta naudojant vieną konteinerį rūšiavimo algoritme vietoj dviejų.

* [v1.1](https://github.com/simces/Pazymiu_Skaiciuokle_2/releases/tag/v1.1) Vietoj ``` struct ``` buvo pradėta naudoti ``` class ``` tipas. Įvykdytas spartos palyginimas naudojant ``` flag'us. ```
