/**
 *	@file	Config.hpp
 * 	@brief 	Config class header file
 * 	@author	Alexis ROLLAND
 * 	@date	2024-06
 * 
 */

/** Code Guards : empêche les inclusions multiples - Idem C */
#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <unordered_map>
#include <string>
#include <cstdint>
#include <utility>  //*< for std::pair  */
#include <print>
#include <iostream>
#include <exception>

using   pic24_register = std::pair<std::string, uint16_t>;  /**< Create a new type called pic24_register, as a pair of string:uint16_t */

class Config{
    		
    private:
    std::unordered_map<std::string, uint16_t> ConfigList{};  
        
    public:
        Config() = default;                 /**< constructeur par défaut - defaulted */ 
        virtual ~Config() = default;        /**< Destructeur par défaut */   

        /**
         * @brief : adds a register:value pair into the ConfigList
         * 
         * @param pic24_register reg : pair to add
         * @param bool ChangeIfExists : true to change value if register is already in the ConfigList, false (default) to make sure
         *                              an existing register value won't be touched.
         * 
         * @throw : std::invalid_argument("Register already exists.") if ChangeIfExits is false and the register is already listed.  
         */
        void    add(pic24_register reg, bool ChangeIfExists = false);    
        
        /**
         * 
         */
        void    remove(const std::string &key);
        
        /**
         * 
         */
        void    remove(pic24_register reg) {this->remove(reg.first);};  /**< Simple call to the std::string based remove function */
        
        /**
         * 
         */
        [[nodiscard]]   bool    isEmpty() const noexcept {return this->ConfigList.empty();};
        
        /**
         * 
         */
        [[nodiscard]]   auto    getSize() const noexcept {return this->ConfigList.size();};
        
        /**
         * 
         */
        void    dump() const noexcept {for (auto elt : this->ConfigList) std::println("{0:s} : 0x{1:04X}",elt.first,elt.second);};
        


};



#endif  /*  __CONFIG_HPP__ */
