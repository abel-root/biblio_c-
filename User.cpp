#include "../h/User.hpp"
#include "../h/utils.hpp"
#include <iostream>


 User::User():firstname("firstname"),lastname("lastname"),userType(type::reader){}
User::~User(){}

std:: string User::getFirstname(){
    return this->firstname;
}
std::string User::getLastname(){
    return this->lastname;
}

void User::setFistrname(std::string firstname){
    this->firstname=firstname;
}
void User::setLastname(std::string lastname){
    this->lastname=lastname;
}
 void User::setUserType(type userType){
    this->userType=userType;
 }
type User:: getUserType(){
    return this->userType;
}

void User::createUser(body dataUser){
    json userData=tools_file::readJsonFile("../db/user.json");
    std::cout<<userData.dump(1);
    //std::cin.ignore();
    std::string userType;

   if(dataUser.type==type::author) userType="Author";
   if(dataUser.type==type::reader) userType="Reader";

    if(!(validation::idUnique(dataUser.userId,userData))){
        userData.push_back({
            {"lastname",dataUser.lastname},
            {"firstname",dataUser.firstname},
            {"type",userType},
            {"id",dataUser.userId}
         });
        tools_file::createJsonFile("../db/user.json",userData);
    }
    
   

}