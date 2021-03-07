//
// Created by user on 28.02.2021.
//
#pragma warning(disable : 4996) 
#include <iostream>
#include "User.h"
#include <io.h>
#include <string>
using namespace std;
using namespace std;
/*    User::User(string ulogin, string upassword){
        login=ulogin;
        password=upassword;
    }*/
/**Default log in function*/
    void User::enter(string ulogin, string upassword){
        string exe="..\\Users\\"+ulogin+".bin";
        FILE *opened;
        if (FileExists(&exe)) {

            opened = fopen(exe.c_str(), "rb");
            User read;
            fread(&read,sizeof(User),1,opened);
            while (true) {
                if (ulogin == read.login && upassword == read.password){ cout << "OK\n"; break;}
                else {
                    cout << "NE OK";
                    cin>>upassword;

                }

            }
            fclose(opened);
        }
        else {
            opened = fopen((exe).c_str(), "wb");
            fwrite(this,sizeof(User),1,opened);
            cout << "registered\n";
            fclose(opened);
        }

    }
/**Function only for admins. Edits user information (login/password/type). Doesn't work on other admins*/
    void User::edit_user(string ulogin){
        if (this->access_type==1){
            string exe="..\\Users\\"+ulogin+".bin";
            FILE *opened;
            if (FileExists(&exe)) {

                opened = fopen(exe.c_str(), "rb");
                User read;
                fread(&read,sizeof(User),1,opened);
                cout << "Login: "<< read.login<<endl;
                cout << "password: "<<read.password<<endl;
                cout << "Access Type: ";
                fclose(opened);
                if (!read.access_type){
                    cout << "User\n";
                    cout << "Enter new login if u want to change it (or enter 0)\n";
                    string new_log;
                    cin >>new_log;
                    if (new_log=="0");
                    else read.login=new_log;
                    cout << "Enter new password if u want to change it(or enter 0)\n";
                    string new_pass;
                    cin>>new_pass;
                    if (new_pass=="0");
                    else read.password=new_pass;
                    cout << "Enter user acces type (enter 0 for user, and 1 for admin)\n";
                    bool new_role;
                    cin>> new_role;
                    string will_be_deleted="..\\Users\\"+ulogin+".bin";
                    remove(will_be_deleted.c_str());
                    exe="..\\Users\\"+read.login+".bin";
                    opened=fopen(exe.c_str(),"wb");
                    fwrite(&read,sizeof(User),1,opened);
                }
                else cout << "Admin\nYou can't edit this user\n";
                fclose (opened);
            }
        }
        else return;
    }
/**Function only for admins. Adds new user with admin type*/
    void User::add_admin(string ulogin,string upassword){
        User new_user;
        new_user.login=ulogin;
        new_user.password=upassword;
        new_user.access_type=true;
        string exe="..\\Users\\"+ulogin+".bin";
        FILE *opened;
        if (!FileExists(&exe)) {

            opened = fopen((exe).c_str(), "wb");
            fwrite(&new_user,sizeof(User),1,opened);
            cout << "Successfuly added\n";
            fclose(opened);
        }
        else {
            cout << "ERROR. There is such user\n";
        }
    }
/*  string User::pass_hash(){
        const int a=1;
        const int m=1;
        const int p=1;
        string hashed;
        hashed.push_back(a);
        hashed.push_back(m);
        hashed.push_back(p);
        return hashed;
    }*/
/**Function that check is user file exists*/
bool User::FileExists( string *fname)
{
    return access(fname->c_str(), 0) != -1;
}


