#ifndef STUDENTASH
#define STUDENTASH

#include <string>
#include <vector>
using namespace std;

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double vidurkis;
public:
    Studentas() : vidurkis(0) { }
    Studentas(string vardas, string pavarde, int egzaminas, vector<int> pazymiai);

    Studentas(const Studentas& a) : egzaminas(a.getEgzaminas()), vidurkis(a.getVidurkis()) {        // copy constructorius
        vardas = a.getVardas();
        pavarde = a.getPavarde();

        pazymiai.reserve(a.getPazymiai().size());
        for (int i : a.getPazymiai()) {
            pazymiai.push_back(i);
        }
    }

    Studentas& operator=(const Studentas& a) {          // copy assignment 
        if (&a == this) return *this;

        vardas = a.getVardas();
        pavarde = a.getPavarde();
        egzaminas = a.getEgzaminas();
        vidurkis = a.getVidurkis();
        pazymiai.clear();
        pazymiai.shrink_to_fit();
        pazymiai.reserve(a.getPazymiai().size());
        for (int i : a.getPazymiai()) {
            pazymiai.push_back(i);
        }
        return *this;
    }

    ~Studentas() {}         // obj destruktorius

   
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline vector<int> getPazymiai() const { return pazymiai; }
    inline int getEgzaminas() const { return egzaminas; }
    inline double getVidurkis() const { return vidurkis; }
    
    inline void setVardas(string vardas) { Studentas::vardas = vardas; }
    inline void setPavarde(string pavarde) { Studentas::pavarde = pavarde; }
    inline void setPazymiai(vector<int> pazymiai) { Studentas::pazymiai = pazymiai; }
    inline void setEgz(int egz) { Studentas::egzaminas = egz; }
    inline void setVidurkis(double vidurkis) { Studentas::vidurkis = vidurkis; }
    inline void setPazymys(int pazymys) { pazymiai.push_back(pazymys); }
};

#endif
