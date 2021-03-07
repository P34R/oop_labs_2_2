//
// Created by user on 28.02.2021.
//
#pragma warning(disable : 4996) 
#include "Order.h"
#include "Worker.h"
#include <iostream>
#include <vector>
#include <string>
#include <io.h>

using namespace std;
/**Get and return order from the file with id=oid (if there is no order with such id - ERROR)*/
    void Order::add_order () {
        FILE *orders;
        string f;
        f = "..\\orders.bin";
        if (FileExists(&f)) {
            orders = fopen(f.c_str(), "ab+");
            Order temp;
            while (!feof(orders)) {
                fread(&temp, sizeof(Order), 1, orders);
                id++;
            }
        } else orders = fopen(f.c_str(), "wb");
        int input = -1;
        cout << "Price: ";
        while (input <= 0)
            cin >> input;
        this->price=input;
        input = -1;
        cout << "Cook id: ";
        FILE *cooks= fopen("..\\cooks.bin", "rb");
        worker temp;
        while (true){
            cin >> input;
            fseek(cooks, input * sizeof(worker), 0);
            fread(&temp, sizeof(worker), 1, cooks);
            if (input == temp.id) break;
        }
        this->cook=input;
        fwrite(this,sizeof(Order),1,orders);
        fclose(cooks);
        fclose(orders);
    }
/**Add order to the file*/
    void Order::get_order (int oid){
        string f="..\\orders.bin";
        FILE *orders=fopen(f.c_str(),"rb");
        fseek(orders,oid*sizeof(Order),0);
        if(!feof(orders)) {
            fread(this, sizeof(Order), 1, orders);
            cout << "Price: " << this->price<<endl;
            cout << "Cook id: " << this->id<<endl;
        }
        else cout << "there is no such order\n";
    }
    /**Delete order from the file with id=oid (if there is no order with such id - ERROR)*/
    void Order::delete_order (int oid){
        FILE *orders;
        string f;
        f = "..\\orders.bin";
        orders=fopen(f.c_str(),"ab+");
        fseek(orders,oid*sizeof(Order),0);
        Order read;
        fread(&read,sizeof(Order),1,orders);
        if (!feof(orders)){
            read.is_exist=0;
            fseek(orders,oid*sizeof(Order),0);
            fwrite(&read,sizeof(Order),1,orders);
            cout << "DELETED\n";
        }
        else cout <<"THERE IS NO SUCH ORDER\n";
        fclose(orders);
    }
/**Function that check is orders file exists*/
bool Order::FileExists( string *fname)
{
    return access(fname->c_str(), 0) != -1;
}
