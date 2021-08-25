#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    string name;//FOR task 3
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p=0,double d=0,Material m=Material::Wood):price(p),discount(d),madeof(m)
    {

    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double percent)
    {
        if(percent < 100)
        {
            discount = price*percent/100.0;
        }
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setItemName(string _name)//FOR task 3
    {
        name = _name;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    double getDiscount()
    {
        return price-discount;
    }
    // FOR TASK 2
    void get()
    {
        cout<<"Product Name: "<<name<<endl;//FOR task 3
        cout<<"Regular Price: "<<price<<endl;
        cout<<"Discounted Price: "<<getDiscount()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
    }
    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize BedSz;
public:
    Bed(double p,double d,Material m, BedSize b):Furniture(p, d, m), BedSz(b)
    {

    }
    ~Bed()
    {

    }
    // For TASK 2
    void productDetails()
    {
        cout<<"-----------------------------------\n";
        get();
        cout<<"Bed Size: "<<getBedSize()<<endl;
        cout<<"###################################\n";
        
    }
    string getBedSize()
    {
        if(BedSz==BedSize::Single)
            return string("Single");
        else if(BedSz==BedSize::SemiDouble)
            return string("SemiDouble");
        else if(BedSz==BedSize::Double)
            return string("Double");
        else
            return string("");
    }
};

enum class SofaSize{One, Two, Three, Four, Five};
class Sofa:public Furniture
{
private:
    SofaSize sz;
public:
    Sofa(double p,double d,Material m, SofaSize _sz): Furniture(p, d, m), sz(_sz)
    {

    }
    ~Sofa()
    {

    }
    // For TASK 2
    void productDetails()
    {
        cout<<"-----------------------------------\n";
        get();
        cout<<"Sofa Size: "<<getSeats()<<endl;
        cout<<"###################################\n";
        
    }
    string getSeats()
    {
        if(sz==SofaSize::One)
            return string("One");
        else if(sz==SofaSize::Two)
            return string("Two");
        else if(sz==SofaSize::Three)
            return string("Three");
        else if(sz==SofaSize::Four)
            return string("Four");
        else if(sz==SofaSize::Five)
            return string("Five");
        else
            return string("");
    }

};

enum class AlmirahSize{Two=2,Three,Four};
class Almirah:public Furniture
{
private:
    AlmirahSize dr;
public:
    Almirah(double p,double d,Material m, AlmirahSize _dr):Furniture(p, d, m), dr(_dr)
    {

    }
    ~Almirah()
    {

    }
    // For TASK 2
    void productDetails()
    {
        cout<<"-----------------------------------\n";
        get();
        cout<<"Almirah Size: "<<getDoors()<<endl;
        cout<<"###################################\n";
        
    }
    string getDoors()
    {
        if(dr==AlmirahSize::Two)
            return string("Two");
        else if(dr==AlmirahSize::Three)
            return string("Three");
        else if(dr==AlmirahSize::Four)
            return string("Four");
        else
            return string("");
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/

void sort_furniture_discount(Furniture** b, int n) ;


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);
    f_list[0]->setItemName("Bahari Bed");
    
    /**task 1 ends here*/

    /**`
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    // /**task 2 ends here*/
    // /**task 3 ends here*/

    // *task 4
    // So that following lines can be executed without error
    
    sort_furniture_discount(f_list,4);
    cout<<"\nSorted array:\n";
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/
    for (int i = 0; i < 4; ++i)
    {
        delete f_list[i];
    }

    return 0;
}
// TASK 4
void order(Furniture** b1, Furniture** b2) {
  if ((*b1)->getDiscount() < (*b2)->getDiscount()) {
    Furniture* temp = *b1;
    *b1 = *b2;
    *b2 = temp;
  }
}

void sort_furniture_discount(Furniture** b, int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      order(b + i, b + j);
    }
  }
}