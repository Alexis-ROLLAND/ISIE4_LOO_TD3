#include "Config.hpp"

//----------------------------------------------------------------------------
void Config::add(const pic24_register &reg, bool ChangeIfExists) {

    if (this->ConfigList.contains(reg.first) == false) {
        this->ConfigList.insert(reg); /**< The key doesn't exist in the map, ok, insert the new one   */
        std::println(std::clog, "Register {0:s} has been successfully inserted.", reg.first); /**< Affichage */
    } else {
        if (ChangeIfExists) {
            this->ConfigList.at(reg.first) = reg.second;                                         /**< update */
            std::println(std::clog, "Register {0:s} has been successfully changed.", reg.first); /**< Affichage */
        } else {
            throw std::invalid_argument("Register already exists."); /**< Throw Exception */
        }
    }
}

//----------------------------------------------------------------------------
void Config::remove(const std::string &key) {
    auto nbErased = this->ConfigList.erase(key);
    if (nbErased == 0) {
        throw std::invalid_argument("Register doesn't exist."); /**< Throw Exception */
    }
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
