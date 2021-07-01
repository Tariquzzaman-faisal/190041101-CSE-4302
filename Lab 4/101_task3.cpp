#include<iostream>
#include<cstring>
using namespace std;
class ZooAnimal
{
    private:
    char name[50];
    int birthY, cageNo, height;
    float weight;
    public:
    ZooAnimal():name("Null"), birthY(2021), cageNo(9999), height(9999), weight(9999.9)
    {

    }
    void setName(char _name[]){
        strcpy(name, _name);
    }
    char* getName(){
        return name;
    }
    void setBirthY(int _year){
        if(_year<=2021) birthY = _year;
        else cout<<"Birth Year cannot be greater than 2021"<<endl;
    }
    int getBirthY(){
        return birthY;
    }
    void setCage(int _cage){
        cageNo = _cage;
    }
    int getCage(){
        return cageNo;
    }
    void setWeight(float _weight){
        weight = _weight;
    }
    float getWeight(){
        return weight;
    }
    void setHeight(int _height){
        height = _height;
    }
    int getHeight(){
        return height;
    }
    int getAge(){
        return 2021-getBirthY();
    }
    void getInformation(){
        cout<<"Animal Information: "<<endl;
        cout<<"Name Of Animal: "<<getName()<<endl;
        cout<<"BirthYear: "<<getBirthY()<<endl;
        cout<<"Cage No: "<<getCage()<<endl;
        cout<<"Weight: "<<getWeight()<<endl;
        cout<<"Height: "<<getHeight()<<endl;
    }
};

int main(){
    ZooAnimal anim;
    char name[] = "Zozo";
    anim.setName(name);
    anim.setBirthY(2026);
    anim.setBirthY(2012);
    anim.setCage(1);
    anim.setHeight(10);
    anim.setWeight(70.0);
    anim.getInformation();
    return 0;
}