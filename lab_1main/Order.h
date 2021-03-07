//
// Created by user on 28.02.2021.
//

#ifndef LAB_1MAIN_ORDER_H
#define LAB_1MAIN_ORDER_H
#include "worker.h"
/**
Order class is used to save information and functions about orders
*/
class Order {
public:/**Order id (there can be 2 orders with same id if first deleted)*/
    int id=0; /**Order price*/
    unsigned int price;/**Cook id who will cook this order*/
    int cook;/**waiter id who in charge of the order*/
	int waiter;/**variable responsible for order existence*/
    bool is_exist = 1;
//    int next=-1;

    void delete_order (int oid);

    void get_order (int oid);

    void add_order ();

    bool FileExists( string *fname);
};


#endif //LAB_1MAIN_ORDER_H
