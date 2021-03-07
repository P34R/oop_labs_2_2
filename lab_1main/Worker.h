//
// Created by user on 28.02.2021.
//

#ifndef LAB_1MAIN_WORKER_H
#define LAB_1MAIN_WORKER_H
#include <iostream>
using namespace std;
/**Class worker contains information about workers (Cooks and waiters saved in separate files)*/
class worker {
public:/**Worker's id*/
    int id=0;/**Worker's type (cook or waiter)*/
    bool type=0;/**Worker's name*/
    string name;/**Workers experience (in years)*/
    double exp;/**Workers salary (can be saved in dollars/UAH/RUB/etc, but expected same currency for all workers*/
    int salary;/**variable responsible for worker existence*/
    bool is_exist = 1;

    void add_worker ();

    worker& get_worker (bool wtype, unsigned int wid);

    void edit_worker (bool wtype, unsigned int wid);

    void delete_worker(bool wtype,unsigned int wid);
    /**Overloaded opertor <<*/
    friend ostream &operator<< (ostream &out, const worker &work){
        out<< "ID: "<<work.id<<endl;
        out<< "Type: "<<work.id<<endl;
        out<< "Name: "<<work.id<<endl;
        out<< "Exp: "<<work.id<<endl;
        out<< "Salary: "<<work.id<<endl;
        return out;
    };
	/**Overloaded opertor <<*/
    friend istream &operator>> (istream &in,  worker &work){
        cout<< "ID: "; in>>work.id;
        cout<< "Type: "; in>>work.id;
        cout<< "Name: "; in>>work.id;
        cout<< "Exp: "; in>>work.id;
        cout<< "Salary: "; in>>work.id;
        return in;
    };

    bool FileExists( string *fname);
};


#endif //LAB_1MAIN_WORKER_H
