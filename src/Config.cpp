#include "Config.hpp"

//----------------------------------------------------------------------------
void    Config::add(pic24_register reg, bool ChangeIfExists){
    auto it = this->ConfigList.find(reg.first);
    if ( it  == this->ConfigList.end()){
        this->ConfigList.insert(reg);   /**> The key doesn't exist in the map, ok, insert the new one   */
        std::println(std::clog,"Register {} has been successfully inserted.",reg.first);
    }
    else{
        if (ChangeIfExists){
            this->ConfigList.erase(it);         /**< First, erase the element */
            this->ConfigList.insert(reg);       /**< then add the new one */
            std::println(std::clog,"Register {} has been successfully changed.",reg.first);
        }
        else{
            throw std::invalid_argument("Register already exists.");
        }
    }


}
//----------------------------------------------------------------------------
void    Config::remove(const std::string &key){
    auto nbErased = this->ConfigList.erase(key);
    if (nbErased == 0){
        throw std::invalid_argument("Register doesn't exist.");
    }
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------




