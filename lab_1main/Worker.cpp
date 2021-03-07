//
// Created by user on 28.02.2021.
//
#pragma warning(disable : 4996) 
#include "Worker.h"
#include "Order.h"
#include <string>
#include <vector>
#include <io.h >
using namespace std;
/**Function that add worker to the file*/
    void worker::add_worker (){
        FILE *workers;
        string f;
        string input;
        cout << "Who do you want to add\n Cook or Waiter\n";
        while (true){
            cin >> input;
            if (input=="Cook" || input=="cook"){
                this->type=false;
                f="..\\cooks.bin";
                break;
            }
            else if (input=="waiter"|| input=="Waiter"){
                this->type=true;
                f="..\\waiters.bin";
                break;
            }
            else cout << "Enter waiter or cook\n";
        }
        if (FileExists(&f)){
            workers=fopen(f.c_str(),"ab+");
            worker temp;
            while(!feof(workers)){
                fread(&temp,sizeof(worker),1,workers);
                if (temp.is_exist)
                    id++;
            }
            cout << "OK FILE"<<endl;
        }
        else {
            workers=fopen(f.c_str(),"wb");
            cout << "FILE CREATED\n";
        }
        int num=-1;

        input.clear();
        cout << "Name: ";
        cin >> input;

        cout << "Experience: ";
        while (num<0){
            cin>> num;
            if (num<0) cout << "Experience must be >=0\n";
        }
        num=0;
        cout << "Salary: ";
        while (num<=0) {
            cin >> num;
            if (num<=0) cout<< "Nobody works for free\n";
        }
        fwrite(this,sizeof(worker),1,workers);
        fclose(workers);
        cout << this->id<<endl;
    }
/**Function that get worker with such id=wid and type=wtype from the file (if there is no worker with such id - ERROR)*/
    worker& worker::get_worker (bool wtype, unsigned int wid){
        string f;
        if (!wtype) f="..\\cooks.bin";
        else f="..\\waiters.bin";
        FILE *workers=fopen(f.c_str(),"rb");
        fseek(workers,wid*sizeof(worker),0);
        if (!feof(workers)) {
            fread(this, sizeof(worker), 1, workers);
            cout<< this;
        }
        else cout << "there is no such worker\n";
        fclose(workers);
        return *this;
    }
/**Function that edits worker with such id=wid and type=wtype from the file (if there is no worker with such id - ERROR)*/
    void worker::edit_worker (bool wtype, unsigned int wid){
        worker temp=get_worker(wtype,wid);
        string f;
        cout << temp;
        cin>>temp;
        if (!wtype) f="..\\cooks.bin";
        else f="..\\waiters.bin";
        FILE *workers=fopen(f.c_str(),"ab+");
        fseek(workers,wid*sizeof(worker),0);
        fwrite(&temp,sizeof(worker),1,workers);
        fclose(workers);
    }
/**Function that delete worker with such id=wid and type=wtype from the file (if there is no worker with such id - ERROR)*/
    void worker::delete_worker(bool wtype,unsigned int wid){
        string f;
        if (!wtype) f="..\\cooks.bin";
        else f="..\\waiters.bin";
        FILE *workers=fopen(f.c_str(),"ab+");
        worker temp;
        fseek(workers,wid*sizeof(worker),0);
        fread(&temp,sizeof(worker),1,workers);
        if (!feof(workers)) {
            fseek(workers, wid * sizeof(worker), 0);
            temp.is_exist = 0;
            fwrite(&temp, sizeof(worker), 1, workers);
            string ord = "..\\orders.bin";
            FILE *orders=fopen(ord.c_str(),"rb");
            Order temp_order;
            vector<int> orders_to_delete;
            while (!feof(orders)){
                fread(&temp_order,sizeof(Order),1,orders);
                if (temp_order.cook==wid) orders_to_delete.push_back(temp_order.id);
            }
            fclose(orders);
            for (int i=0;i<orders_to_delete.size();i++){
                temp_order.delete_order(orders_to_delete[i]);
            }
            cout<< "DELETED\n";
        }
        fclose(workers);
    }
/**Function that check is orders file exists*/
bool worker::FileExists( string *fname)
{
    return access(fname->c_str(), 0) != -1;
}
