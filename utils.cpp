#include "../h/utils.hpp"

void tools_file::createJsonFile(std::string filename,json userData ){
    std::ofstream f(filename);
    if(f && f.is_open()){
       f<<userData.dump(2); //code  here
    }
    f.close();
   
}
json tools_file:: readJsonFile(std::string filename){

    std::ifstream f(filename);
    json dataUser;
    if(f && f.is_open()){
        f>>dataUser;
    }
     f.close();
    return dataUser;
}

bool validation::emaiExist(std::string email, json Data){

    return 0;
}
bool validation::numberExist(std::string number, json Data){
    return 0;
}
bool validation::passwordCheck(std::string password, json Data){
    return 0;
}
 bool validation:: idUnique(std::size_t userId,json Data){
    bool state;
   for( auto it=Data.cbegin();it!=Data.cend();++it){
    if(it->at("id")==userId){
        state= true;
    }else{
        state=  false;
    }
   }
    return state;
 }

std::size_t sql_extension::primaryKey(json data){
    if(data.is_array()&&!data.empty()){
        json lastElement=data.back();
        if(lastElement.contains("id")){
             std::size_t userId= lastElement.at("id").get<std::size_t>();
              userId++;
              return userId;
        }
         std::cout<<lastElement<<std::endl;
    }else{
        return 1;
    }
 }