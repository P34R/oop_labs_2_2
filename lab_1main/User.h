//
// Created by user on 28.02.2021.
//

#ifndef LAB_1MAIN_USER_H
#define LAB_1MAIN_USER_H

#include <string>
using namespace std;
/**Class User contains information about user (login, password and type of user (admin or default)). Information saved in files*/
class User {
public:
 //   User(string ulogin, string upassword);
    /**User login*/
    string login;/**User password*/
    string password;/**User type (Admin or default user)*/
    bool access_type=0;

    void enter(string ulogin, string upassword);

    void edit_user(string ulogin);

    void add_admin(string ulogin,string upassword);
	
 //   string pass_hash();

    bool FileExists( string *fname);
};


#endif //LAB_1MAIN_USER_H
