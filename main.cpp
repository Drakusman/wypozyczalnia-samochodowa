#include <iostream>
#include <windows.h>
//biblioteka potrzebna do obsluzenia vektorow - list z naszymi obiektami
#include <vector>

using namespace std;


// klasa obstrakcyjna Pojazd z ktorej dziedzicza inne klasy
class Pojazd
{
    //publiczne zmienne klasy Pojazd do ktorego maja dostep inne klasy dziedzicza po "rodzicu" wszystkie pola
public:
    int ID=0;
    string nazwa;
    float cena_za_km;
    float cena_za_godzine;
    string paliwo;
    float spalanie;
    string naped;
    float przebieg;
    float pojemnosc;
    bool wypozyczony;

    //konstruktor klasy Pojazd
    Pojazd()
    {
        ID++;
        nazwa = "brak";
        cena_za_godzine = 0;
        cena_za_km=0;
        paliwo = "Niedotyczy";
        spalanie = 0;
        naped = "Niedotyczy";
        przebieg = 0;
        pojemnosc = 0;
        wypozyczony=false;
    }
    //wirtualna metoda klasy pojazd z ktorej korzysta reszta klas oczywiscie na swoje potrzeby w kazdej klasie jest ona inna
    virtual void wyswietl_info()=0;
    //metody ustawienia wyporzoczyny na prawda lub falsz
    void wypozycz()
    {
        wypozyczony=true;
    }
    void oddaj()
    {
        wypozyczony=false;
    }
    //ciag metod do ustawiania danych mozemy wykozystac je np. Rower->set_nazwa
    void set_ID(int id)
    {
        ID=id;
    }
    void set_Nazwa(string name)
    {
        nazwa=name;
    }
    void set_cena_za_km(float cena)
    {
        cena_za_km=cena;
    }
    void set_cena_za_godzine(float cena)
    {
        cena_za_godzine=cena;
    }
    void set_paliwo(string fuel)
    {
        paliwo=fuel;
    }
    void set_spalanie(float spal)
    {
        spalanie=spal;
    }
    void set_naped(string nap)
    {
        naped=nap;
    }
    void set_przebieg(float przeb)
    {
        przebieg=przeb;
    }
    void set_pojemnosc(float poj)
    {
        pojemnosc=poj;
    }
    void set_wypozyczony(bool wyp)
    {
        wypozyczony=wyp;
    }
};
//klasa Samochod dziedziczaca publicznie z klasy Pojazd
class Samochod:public Pojazd
{
    //brak pol klasy Samochod - wszystkie pola sa dziedziczone po "rodziucu" - klasie Pojazd
    //konstruktor klasy Samochod
public:
    Samochod(int ID1,string nazwa1,
             int cena_za_km1,
             int cena_za_godzine1,
             string paliwo1,
             int spalanie1,
             string naped1,
             int przebieg1,
             float pojemnosc1,
             bool wypozyczony1)
    {
        ID=ID1;
        nazwa=nazwa1;
        cena_za_km=cena_za_km1;
        cena_za_godzine=cena_za_godzine1;
        paliwo=paliwo1;
        spalanie=spalanie1;
        naped=naped1;
        przebieg=przebieg1;
        pojemnosc=pojemnosc1;
        wypozyczony=wypozyczony1;
    }
    // odnosnik do metody wirtualnej z klasy Pojazd
    void wyswietl_info()
    {
        cout<<"Numer : "<<ID<<endl;
        cout<<"Nazwa : "<<nazwa<<endl;
        cout<<"Cena za km : "<<cena_za_km<<endl;
        cout<<"Cena za godzine : "<<cena_za_godzine<<endl;
        cout<<"paliwo : "<<paliwo<<endl;
        cout<<"naped : "<<naped<<endl;
        cout<<"przebieg : "<<przebieg<<endl;
        cout<<"pojemnosc : "<<pojemnosc<<endl;
        cout<<"Dostepny : ";
        if(wypozyczony==false)
        {
            cout<<"TAK"<<endl;
        }
        if(wypozyczony==true)
        {
            cout<<"NIE"<<endl;
        }
    }

};
class Rower:public Pojazd
{
public:
    Rower(int ID1,string nazwa1,
          int cena_za_godzine1,
          bool wypozyczony1)
    {
        ID=ID1;
        nazwa=nazwa1;
        cena_za_godzine=cena_za_godzine1;
        wypozyczony=wypozyczony1;
    }
    void wyswietl_info()
    {
        cout<<"Numer : "<<ID<<endl;
        cout<<"Nazwa : "<<nazwa<<endl;
        cout<<"Cena za godzine : "<<cena_za_godzine<<endl;
        cout<<"Dostepny : ";

        if(wypozyczony==false)
        {
            cout<<"TAK"<<endl;
        }
        if(wypozyczony==true)
        {
            cout<<"NIE"<<endl;
        }
    }
} ;
class Motor:public Pojazd
{
public:
    Motor(int ID1,string nazwa1,
          int cena_za_km1,
          int cena_za_godzine1,
          string paliwo1,
          int spalanie1,
          string naped1,
          int przebieg1,
          float pojemnosc1,
          bool wypozyczony1)
    {
        ID=ID1;
        nazwa=nazwa1;
        cena_za_km=cena_za_km1;
        cena_za_godzine=cena_za_godzine1;
        paliwo=paliwo1;
        spalanie=spalanie1;
        naped=naped1;
        przebieg=przebieg1;
        pojemnosc=pojemnosc1;
        wypozyczony=wypozyczony1;

    }
    void wyswietl_info()
    {
        cout<<"Numer : "<<ID<<endl;
        cout<<"Nazwa : "<<nazwa<<endl;
        cout<<"Cena za km : "<<cena_za_km<<endl;
        cout<<"Cena za godzine : "<<cena_za_godzine<<endl;
        cout<<"paliwo : "<<paliwo<<endl;
        cout<<"naped : "<<naped<<endl;
        cout<<"przebieg : "<<przebieg<<endl;
        cout<<"pojemnosc : "<<pojemnosc<<endl;
        cout<<"Dostepny : ";

        if(wypozyczony==false)
        {
            cout<<"TAK"<<endl;
        }
        if(wypozyczony==true)
        {
            cout<<"NIE"<<endl;
        }
    }
};

//zmienne globalne
vector<Pojazd*> Rowery;
vector<Pojazd*> Samochody;
vector<Pojazd*> Motory;
vector<Pojazd*> Wszystko;
//zmienna pomocnicza do zatwierdzenie czy chce sie wypozyczyc wybrany poazd
char tak;
//zmienne wyboru opcji
int wybor,wybor2;
//wybor na jak dlugo wypozyczyc pojazd
int na_jak_dlugo;
//naglowki funkcji
void przypisanie_obiektow_Rowery();
void przypisanie_obiektow_Samochody();
void przypisanie_obiektow_Motory();
void przypisanie_obiektow_Wszystko();

int menu();
//wyswietlenie menu dla jednosladu
void menu_kategori_jednoslad();
//wyswietlenie menu dla samochodu
void menu_kategori_samochod();
void menu_kategori_wszystko();

int main()
{
    przypisanie_obiektow_Rowery();
    przypisanie_obiektow_Samochody();
    przypisanie_obiektow_Motory();
    przypisanie_obiektow_Wszystko();

    //nieskonczona petla wypozyczania pojazdow
    while(1)
    {
        //przypisanie wartosci wyboru z funkcji menu
        wybor=menu();
        switch(wybor)
        {
        case 1:
        {
            menu_kategori_jednoslad();
            break;
        }
        case 2:
        {
            menu_kategori_samochod();
            break;
        }
        case 3:
        {
            menu_kategori_wszystko();
            break;
        }
        case 4:
        {
            return 0;
        }
        }
    }

    return 0;
}
void przypisanie_obiektow_Rowery()
{
    //przypisanie nowych 5 obiektow klasy Rower do listy wskaznikow obiektow typu Rower
    Pojazd *rower=new Rower(0,"Rower zwykly",20,false);
    Rowery.push_back(rower);
    rower = new Rower(1,"BMX",50,true);
    Rowery.push_back(rower);
    rower = new Rower(2,"Skladak",25,false);
    Rowery.push_back(rower);
    rower = new Rower(3,"Damka",30,false);
    Rowery.push_back(rower);
    rower = new Rower(4,"Szosowka",100,true);
    Rowery.push_back(rower);
}
void przypisanie_obiektow_Samochody()
{
    Pojazd *samochod = new Samochod(5,"Ford Mondeo",2,50,"Benzyna",10,"Tyl",100000,2.0f,false);
    Samochody.push_back(samochod);
    samochod = new Samochod(6,"Ford Mondeo",2,50,"Benzyna",10,"Tyl",100000,2.0,false);
    Samochody.push_back(samochod);
    samochod = new Samochod(7,"Ford Mondeo",2,50,"Benzyna",10,"Tyl",100000,2.0,false);
    Samochody.push_back(samochod);
    samochod = new Samochod(8,"Ford Mondeo",2,50,"Benzyna",10,"Tyl",100000,2.0,false);
    Samochody.push_back(samochod);
    samochod = new Samochod(9,"Ford Mondeo",2,50,"Benzyna",10,"Tyl",100000,2.0,false);
    Samochody.push_back(samochod);
}
void przypisanie_obiektow_Motory()
{
    Pojazd * motor=new Motor(10,"Motor 1",2,100,"Benzyna",5,"Tyl",50000,125,false);
    Motory.push_back(motor);
    motor = new Motor(11,"Motor 2",2,100,"Benzyna",5,"Tyl",50000,125,false);
    Motory.push_back(motor);
    motor = new Motor(12,"Motor 3",2,100,"Benzyna",5,"Tyl",50000,125,false);
    Motory.push_back(motor);
    motor = new Motor(13,"Motor 4",2,100,"Benzyna",5,"Tyl",50000,125,false);
    Motory.push_back(motor);
    motor = new Motor(14,"Motor 5",2,100,"Benzyna",5,"Tyl",50000,125,false);
    Motory.push_back(motor);
}
void przypisanie_obiektow_Wszystko()
{
    //przypisanie wszyskich obiektow do jednej listy typu Pojazd
    for(int i=0; i<5; i++)
    {
        Wszystko.push_back(Rowery.at(i));
    }
    for(int i=5; i<10; i++)
    {
        Wszystko.push_back(Samochody.at(i-5));
    }
    for(int i=10; i<15; i++)
    {
        Wszystko.push_back(Motory.at(i-10));
    }
}
int menu()
{
    cout<<"Witaj w naszej wypozyczalni :)\n\nSwiadczymy uslugi wypozyczania:\nJednosladow\nSamochodow\nCzym jest Pan/Pani zainteresowany/na\n\n";
    cout<<"1. Jednoslad\n2. Samochod\n3. Wszystko\n4. Zamknij\n";

    cin>>wybor;

    //sprawdzenie czy uzytkownik wprowadzil niepoprawna liczbe czy text
    while(cin.get()!='\n' || wybor<1 || wybor>4)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>wybor;
    }
    system("cls");
    return wybor;
}
void menu_kategori_jednoslad()
{
    cout<<"1. Rowery\n";
    cout<<"2. Motory\n";
    cin>>wybor;

    while(cin.get()!='\n' || wybor<1 || wybor>3)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>wybor;
    }

    system("cls");

    if(wybor==1)
    {
        for(int i=0; i<5; i++)
        {
            Rowery.at(i)->wyswietl_info();
            cout<<endl;
        }

        cout<<endl<<"Ktory numer Cie interesuje? "<<endl;
        cin>>wybor2;
        while(cin.get()!='\n' || wybor2<0 || wybor2>5)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>wybor2;
        }
        system("cls");

        Wszystko.at(wybor2)->wyswietl_info();
        if(Wszystko.at(wybor2)->wypozyczony)
        {
            cout<<endl<<"Przepraszamy wybrany pojazd jest juz wypozyczony, prosimy wybrac inny"<<endl;
            Sleep(3000);
            return;
        }
        cout<<"Czy chcesz wypozyczyc ten pojazd ?\n[t]-tak\n[n]-nie"<<endl;

        cin>>tak;

        while(tak!='t' && tak!='n')
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>tak;
        }

        if(tak=='t')
        {
            cout<<"Na jak dlugo? (godz.)"<<endl;
            cin>>na_jak_dlugo;
            while(cin.get()!='\n' || na_jak_dlugo<1)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Popraw swoj wybor"<<endl;
                cin>>na_jak_dlugo;
            }
            cout<<"Koszt : "<<na_jak_dlugo*Wszystko.at(wybor2)->cena_za_godzine<<" zl";
            Wszystko.at(wybor2)->wypozycz();
        }
        Sleep(3000);
        wybor=0;
    }
    if(wybor==2)
    {
        for(int i=0; i<5; i++)
        {
            Motory.at(i)->wyswietl_info();
            cout<<endl;
        }
        cout<<endl<<"Ktory numer Cie interesuje? "<<endl;
        cin>>wybor2;
        while(cin.get()!='\n' || wybor2<10 || wybor2>15)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>wybor2;
        }
        system("cls");
        Wszystko.at(wybor2)->wyswietl_info();
        if(Wszystko.at(wybor2)->wypozyczony)
        {
            cout<<endl<<"Przepraszamy wybrany pojazd jest juz wypozyczony, prosimy wybrac inny"<<endl;
            Sleep(3000);
            return;
        }
        cout<<"Czy chcesz wypozyczyc ten pojazd ?\n[t]-tak\n[n]-nie"<<endl;
        cin>>tak;
        while(tak!='t' && tak!='n')
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>tak;
        }
        if(tak=='t')
        {
            cout<<"Na jak dlugo? (godz.)"<<endl;
            cin>>na_jak_dlugo;
            while(cin.get()!='\n' || na_jak_dlugo<1)
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Popraw swoj wybor"<<endl;
                cin>>na_jak_dlugo;
            }
            cout<<"Koszt : "<<na_jak_dlugo*Wszystko.at(wybor2)->cena_za_godzine<<" zl";
            Wszystko.at(wybor2)->wypozycz();

        }
        Sleep(3000);
        wybor=0;

    }
}
void menu_kategori_samochod()
{
    for(int i=0; i<5; i++)
    {
        Samochody.at(i)->wyswietl_info();
        cout<<endl;
    }
    cout<<endl<<"Ktory numer Cie interesuje? "<<endl;
    cin>>wybor2;
    while(cin.get()!='\n' || wybor2<5 || wybor2>10)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>wybor2;
    }
    system("cls");
    Wszystko.at(wybor2)->wyswietl_info();
    if(Wszystko.at(wybor2)->wypozyczony)
    {
        cout<<endl<<"Przepraszamy wybrany pojazd jest juz wypozyczony, prosimy wybrac inny"<<endl;
        Sleep(3000);
        return;
    }
    cout<<"Czy chcesz wypozyczyc ten pojazd ?\n[t]-tak\n[n]-nie"<<endl;
    cin>>tak;
    while(tak!='t' && tak!='n')
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>tak;
    }
    if(tak=='t')
    {
        cout<<"Na ile?"<<endl;
        cin>>na_jak_dlugo;
        while(cin.get()!='\n' || na_jak_dlugo<1)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>na_jak_dlugo;
        }
        cout<<"Koszt : "<<na_jak_dlugo*Wszystko.at(wybor2)->cena_za_godzine<<" zl";
        Wszystko.at(wybor2)->wypozycz();

    }
    Sleep(3000);
    system("cls");
    wybor=0;
}
void menu_kategori_wszystko()
{
    for(int i=0; i<15; i++)
    {
        Wszystko.at(i)->wyswietl_info();
        cout<<endl;
    }
    cout<<endl<<"Ktory numer Cie interesuje? "<<endl;
    cin>>wybor2;
    while(cin.get()!='\n' || wybor2<0 || wybor2>15)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>wybor2;
    }
    system("cls");
    Wszystko.at(wybor2)->wyswietl_info();
    if(Wszystko.at(wybor2)->wypozyczony)
    {
        cout<<endl<<"Przepraszamy wybrany pojazd jest juz wypozyczony, prosimy wybrac inny"<<endl;
        Sleep(3000);
        return;
    }
    cout<<"Czy chcesz wypozyczyc ten pojazd ?\n[t]-tak\n[n]-nie"<<endl;
    cin>>tak;
    while(tak!='t' && tak!='n')
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Popraw swoj wybor"<<endl;
        cin>>tak;
    }
    if(tak=='t')
    {
        cout<<"Na jak dlugo? (godz.)"<<endl;
        cin>>na_jak_dlugo;
        while(cin.get()!='\n' || na_jak_dlugo<1)
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Popraw swoj wybor"<<endl;
            cin>>na_jak_dlugo;
        }
        cout<<"Koszt : "<<na_jak_dlugo*Wszystko.at(wybor2)->cena_za_godzine<<" zl";
        Wszystko.at(wybor2)->wypozycz();

    }
    Sleep(3000);
    system("cls");
    wybor=0;
}
