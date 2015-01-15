#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "config.h"
#include "PartArray.h"
#include <ctime>
#include <stdexcept>
#include <sstream>

using namespace std;

int spinExcess(PartArray* sys){
    int i = 0;
    vector<Part*>::iterator iter = sys->parts.begin();
    while (iter!=sys->parts.end()){
        if ((*iter)->state)
            i+=1;
        else i-=1;
        iter++;
    }
    return i;
}

int main()
{
    config::Instance()->set2D();
    config::Instance()->randmode_standart();
    config::Instance()->srand(time(NULL));

    //PartArray *a = new PartArray("10_10_20_1.dat");
    config::Instance()->ergGauss = 3e7 * 9274e-24; //3*10^-7 - намагниченность одной частицы (магн. Бора), 9274e-24 - эрг/Гс в обном Боре

    //cout<<"destiny - "<<a->destiny()<<endl;
    //cout<<"count - "<<a->count()<<endl;

    //поворачиваем все вверх
    //a->turnUp();
    //a->state->hardReset();

    //Считаем начальную энергию
    double Einit;// = a->calcEnergy1FastIncrementalFirst();

    /*ofstream f1,f2;
    for (int experiment=1;experiment<=10;experiment++){
        {
            stringstream fname;
            fname<<"energy"<<experiment<<".dat";

            const std::string& tmp = fname.str();
            f1.open(tmp.c_str());
        }
        for (int i=0;i<a->count();i++){

            //Обходим несколько вариантов переворачиваемой системы
            for (int j=0;j<1000;j++){
                a->state->randomize(i);

                //a->state->draw();
                //cout<<spinExcess(a)<<"\t"<<a->calcEnergy1FastIncremental(Einit)<<endl;
                f1<<spinExcess(a)<<"\t"<<a->calcEnergy1FastIncremental(Einit)<<endl;
                a->state->reset();
            }
        }
        f1.close();
    }*/
    PartArray *a;
    ofstream f1;
    for (int experiment=1;experiment<=10;experiment++){
        a = new PartArray(10,10,1,20);
        cout<<a->destiny()<<endl;
        a->turnUp();
        a->state->hardReset();
        Einit = a->calcEnergy1FastIncrementalFirst();
        {

            stringstream fname;
            fname<<"allEnergy"<<experiment<<"_1.dat";

            const std::string& tmp = fname.str();
            f1.open(tmp.c_str());
        }
        do {
            f1<<spinExcess(a)<<"\t"<<a->calcEnergy1FastIncremental(Einit)<<endl;
        } while (a->state->next());

        f1.close();
        delete a;
    }

    cout << "Ahoa!" << endl;
    return 0;
}

