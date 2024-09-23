
#include <iostream>
#include "../h/User.hpp"
#include "../h/utils.hpp"

int main(){
    
    User *user=new User();

    json database=tools_file::readJsonFile("../db/user.json");

    body dataUser;

    dataUser.firstname="KONAN";
    dataUser.userId=sql_extension::primaryKey(database);
    dataUser.lastname="Kouakou Abel";
    dataUser.type=type::author;

    user->createUser(dataUser);


    return 0 ;
}