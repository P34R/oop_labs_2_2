//
// Created by user on 20.02.2021.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include "Order.h"
#include "Worker.h"
#include "User.h"
/*
int main(){
    string log;
    string pass;
    cout << "Login: ";
    cin>>log;
    cout << "Password: ";
    cin >> pass;
    worker asd;
    User you(log,pass);
    you.enter(log,pass);
    asd.add_worker();
    return 0;
}
*/
TEST_CASE("get order and check info") {
	Order k;
	k.get_order(0);
	CHECK(k.add_order == 1);
	CHECK(k.id == 3);
	CHECK(k.is_exist == 1);
	CHECK(k.price == 500);
}
TEST_CASE("add order and then check info") {
	Order k;
	Order s;
	CHECK(s.add_order(0, 1500)==1);
	k.get_order(1);
	CHECK(k.cook == 0);
	CHECK(k.id == 1);
	CHECK(k.is_exist == 1);
	CHECK(k.price == 1500);
}
TEST_CASE("u can't add order to cook who doesn't exists") {
	Order k;
	CHECK(k.add_order(5000, 5) == 0);
}
TEST_CASE("logged in user is admin") {
	User test;
	test.enter("admin", "admin");
	CHECK(test.access_type == 1);
}