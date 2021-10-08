#include <iostream>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <process.h>
using namespace std;
const int LEN = 32;  
const int MAX = 100;

enum pokemon_type{
    fire,water
};

class Pokemon
{
private:
    char Name[LEN];
    char trainerName[LEN];
    char speciality[LEN];
    static int n;
    static Pokemon *list[MAX];

public:
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout << " Enter Pokemon name : ";
        cin >> Name;
        cout << " Enter Trainer name : ";
        cin >> trainerName;
        cout << " Enter Speciality : ";
        cin >> speciality;
    }
    virtual void putdata()
    {
        cout << "\n Pokename : " << Name<<" Trainer: "<<trainerName;
        cout << "\n Speciality : " << speciality;
    }
    virtual pokemon_type get_type();
    static void add();                
    static void display();            
    static void read();               
    static void write();              
};
int Pokemon::n;
Pokemon *Pokemon::list[MAX];


class Fire: public Pokemon
{
private:
    int hp;
    int fireAttack;

public:
    void getdata()
    {
        Pokemon::getdata();
        cout << " Enter HP: ";
        cin >> hp;
        cout << " Enter Fire Attack level: ";
        cin >> fireAttack;
    }
    void putdata()
    {
        Pokemon::putdata();
        cout << "\n Hp: " << hp;
        cout << "\n Fire Attack level: " << fireAttack;
    }
  
};

class Water: public Pokemon
{
private:
    int hp;
    int waterAttack;

public:
    void getdata()
    {
        Pokemon::getdata();
        cout << " Enter HP: ";
        cin >> hp;
        cout << " Enter Water attack level: ";
        cin >> waterAttack;
    }
    void putdata()
    {
        Pokemon::putdata();
        cout << "\n Hp : " << hp;
        cout << "\n Water Attack level: " << waterAttack;
    }
  
};

pokemon_type Pokemon::get_type()
{
    if (typeid(*this) == typeid(Fire))
        return fire;
    else if (typeid(*this) == typeid(Water))
        return water;
    else
    {
        cerr << "\nBad Pokemon type";
        exit(1);
    }
}

void Pokemon::add()
{
    char ch;
    cout << "'f' to add fire"
    "\n'w' to add a water"
    "\nEnter selection : ";
    cin >> ch;
    switch (ch)
    { //create specified Pokemon type
    case 'f':
        list[n] = new Fire;
        break;
    case 'w':
        list[n] = new Water;
        break;
    default:
        cout << "\nUnknown Pokemon type\n";
        return;
    }
    list[n++]->getdata();
}

void Pokemon::display()
{
    for (int j = 0; j < n; j++)
    {
        cout << (j + 1);              
        switch (list[j]->get_type())
        {
        case fire:
            cout << ".Type : Fire";
            break;
        case water:
            cout << ".Type : Water";
            break;
        default:
            cout << ".Unknown type";
        }
        list[j]->putdata();
        cout << endl;
    }
}

void Pokemon::read()
{
    int size;            
    pokemon_type ptype;
    ifstream inf;       
    inf.open("POKEMON.DAT", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    { 
        inf.read((char *)&ptype, sizeof(ptype));
        if (inf.eof()) 
            break;
        if (!inf)
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (ptype)
        {              
        case fire: 
            list[n] = new Fire;
            size = sizeof(Fire);
            break;
        case water:
            list[n] = new Water;
            size = sizeof(Water);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } 
        inf.read((char *)list[n], size);
        if (!inf) 
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++; 
    }        
    cout << "Reading " << n << " Pokemon(s)\n";
}

void Pokemon::write()
{
    int size;
    cout << "Writing " << n << " Pokemon.\n";
    ofstream ouf;
    pokemon_type ptype; 
    ouf.open("POKEMON.DAT", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++) //for every Pokemon object
    {                           //get its type
        ptype = list[j]->get_type();
        //write type to file
        ouf.write((char *)&ptype, sizeof(ptype));
        switch (ptype) //find its size
        {
        case fire:
            size = sizeof(Fire);
            break;
        case water:
            size = sizeof(Water);
            break;
        }
        ouf.write((char *)(list[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}

int main()
{
    char ch;
    while (true)
    {
        cout << "'a' -- add data for a Pokemon"
                "\n'd' -- display data for all Pokemons"
                "\n'w' -- write all Pokemon data to file"
                "\n'r' -- read all Pokemon data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a':
            Pokemon::add();
            break;
        case 'd':
            Pokemon::display();
            break;
        case 'w':
            Pokemon::write();
            break;
        case 'r':
            Pokemon::read();
            break;
        case 'x':
            exit(0);
        default:
            cout << "\nUnknown command";
        }
    }     
    return 0;
}