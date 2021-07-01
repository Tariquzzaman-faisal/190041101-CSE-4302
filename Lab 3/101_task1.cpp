#include<iostream>
using namespace std;

class Counter{
    private:
        int count, step;
    public:
    Counter():count(0), step(1)
    {

    }
    void setIncrementStep(int step_val){
        step = step_val;
    }
    int getCount(){
        return count;
    }
    void increment(){
        count += step;
    }
    void resetCount(){
        count = 0;
    }
};

void mainMenu(){
    cout<<"What do you want to do?\n1.Set increment step\n2.Get count\n3.Increment\n4.Reset Count\n5.Exit\nOption: ";
}

int main(){
    Counter c;
    int option;
    bool runProgram = true;
    while(runProgram){
        mainMenu();
        cin >> option;
        switch (option)
        {
        case 1:
            int i_step;
            cin >> i_step;
            c.setIncrementStep(i_step);
            break;
        case 2:
            cout<<"The counter is :"<<c.getCount()<<endl;
            break;
        case 3:
            c.increment();
            break;
        case 4:
            c.resetCount();
            break;
        default:
            runProgram = false;
            break;
        }
    }
}