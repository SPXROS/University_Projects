#include <iostream>
#include <string.h>

using namespace std;
using std::ostream;

class Foitites{
private:
    char *AM;
    string Onomateponumo;
    char fulo;
    unsigned int Eksamino;

public:
    
//Constructors
    Foitites(const char *In_AM, string In_Onomateponumo);
    Foitites(const char *In_AM, string In_Onomateponumo, char In_fulo, unsigned int In_Eksamino);
    
//Copy Constructor
    Foitites(const Foitites &Foitiths);

//Destructor
    ~Foitites();

//Getters
    string getOnoma(){
        return Onomateponumo;
    }
    unsigned int getEksamino(){
        return Eksamino;
    }
    char getFulo(){
        return fulo;
    }
    char *getAM(){
        return AM;
    }

//Setters
    void setEksamino(unsigned int In_Eksamino);
    void setFulo(char In_fulo);
    void setOnoma(string In_Onomateponumo);
    void setAM(const char *In_AM);

//Functions
    void print(ostream& outStream);
    void operator++();
    void operator++(int);
    void operator+=(unsigned int n);
    void operator-=(unsigned int n);
    void operator-();
};

Foitites::Foitites(const char *In_AM, string In_Onomateponumo){
    int len = 0;

    while (In_AM[len] != '\0')
    {
        len++;
    }

    AM = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        AM[i] = In_AM[i];
    }
    AM[len] = '\0';

    Onomateponumo = In_Onomateponumo;
    Eksamino = 1;
};

Foitites::Foitites(const char *In_AM, string In_Onomateponumo, char In_fulo, unsigned int In_Eksamino){
    int len = 0;

    while(In_AM[len] != '\0'){
        len++;
    }

    AM = new char[len + 1];
    for(int i = 0; i<len; i++){
        AM[i] = In_AM[i];
    }
    AM[len] = '\0';

    Onomateponumo = In_Onomateponumo;

    if(In_fulo == 'M' || In_fulo == 'F'){
        fulo = In_fulo;
    } else{
        cout << "Εδωσες λαθος φυλο. Male ( M ) η Female ( F )";
    }

    if(In_Eksamino <= 16 && In_Eksamino > 0){
        Eksamino = In_Eksamino;
    }
};

Foitites::Foitites(const Foitites &Foitiths){
    int len = 0;

    while(Foitiths.AM[len] != '\0'){
        len++;
    }

    AM = new char[len + 1];
    for(int i = 0; i < len; i++){
        AM[i] = Foitiths.AM[i];
    }

    AM[len] = '\0';

    Onomateponumo = Foitiths.Onomateponumo;
    fulo = Foitiths.fulo;
    Eksamino = Foitiths.Eksamino;
}

void Foitites::setEksamino(unsigned int In_Eksamino){
    if(In_Eksamino > 0 && In_Eksamino <= 16){
        Eksamino = In_Eksamino;
    }
}
void Foitites::setFulo(char In_fulo){
    if(In_fulo == 'M' || In_fulo == 'F'){
        fulo = In_fulo;
    }
}
void Foitites::setOnoma(string In_Onomateponumo){
    Onomateponumo = In_Onomateponumo;
}

void Foitites::setAM(const char *In_AM){

    delete[] AM;

    int len = 0;
    while(In_AM[len] != '\0'){
        len++;
    }

    AM = new char[len + 1];

    for(int i = 0; i < len; i++){
        AM[i] = In_AM[i];
    }

    AM[len] = '\0';

}
void Foitites::print(ostream& outStream){
    
    outStream<<"ΑΜ: "<< AM;
    outStream<<" Ονοματεπωνυμο: "<<Onomateponumo<<"( "<< Onomateponumo.length() << " ) ";
    outStream<<" Φυλο: "<<fulo;
    outStream<<" Εξαμηνο: "<<Eksamino;

}

void Foitites::operator++(){
    Eksamino++;
}

void Foitites::operator++(int){
    Eksamino++;
}

void Foitites::operator+=(unsigned int n){
    Eksamino += n;
}

void Foitites::operator-=(unsigned int n){
    Eksamino -= n;
}

void Foitites::operator-(){
    if(fulo == 'F'){
        fulo = 'M';
    } else{
        fulo = 'F';
    }
}

Foitites::~Foitites(){
    delete[] AM;
}

int main() {

    int n = 5;
    Foitites** pin = new Foitites*[n];

    pin[0] = new Foitites("25390124","John Doe");
    pin[1] = new Foitites("25390126","Θεοδωρα Παπαδοπουλου",'F',4);
    pin[2] = new Foitites("25390127","Helen Antoniou",'F',2);
    pin[3] = new Foitites("25390128","Μανωλης Ιωαννιδης",'M',6);
    pin[4] = new Foitites("25390129","Bill Kolovos",'F',4); 

    for(int i = 0;  i<n; i++){
        cout << "Φοιτητης " << i << ". : ";
        (*pin[i]).print(cout);
        cout << "\n";
    }

    Foitites* pin_antigrafh = new Foitites(*pin[4]);
    (*pin_antigrafh).setAM("25390030");
    -(*pin_antigrafh);

    (*pin[0]).setFulo('M');
    (*pin[0]).setEksamino(3);
    (*pin[0]).setAM("25390125");
    (*pin[0]).setOnoma("Johny Doe");
    
    ++(*pin[0]);
    (*pin[0])++;

    *pin[1] += 4;
    *pin[1] -= 2;

    -(*pin[2]);
    -(*pin[4]);

    (*pin[3]).getOnoma(); 
    (*pin[3]).getEksamino();
    (*pin[3]).getFulo();
    (*pin[3]).getAM();

    cout<<"\n";

    for(int i = 0; i<n; i++){
        cout << "Φοιτητης " << i << ". : ";
        (*pin[i]).print(cout);
        cout << "\n";
    }

    cout << "Φοιτητης " << n<< ". : ";
    (*pin_antigrafh).print(cout);

    for(int i = 0; i<n; i++){
        delete pin[i];
    }

    delete pin_antigrafh;
 
    delete [] pin;

    return 0;
}
