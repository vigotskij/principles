/**
* Copyleft (c) 2018 Boris Sortino <boris.sortino@gmail.com>.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <string>
#include <MessengerInterface.h>
#include <ComponentInterface.h>

class Messeger : public MessengerInterface, public ComponentInterface
{
    public:
        Messeger() ;
        virtual ~Messeger() ;
        std::string say( void ) ;

        //ComponentInterface:
        bool implements( std::string interfaceName ) ;
        void* getInstance() ;
        void release() ;

    private:
        int referenceCounter ;
        bool implemented ;
} ;

Messeger::Messeger() : referenceCounter(0){}

Messeger::~Messeger(){}

std::string Messeger::say(){
  return "Hello! I am a string and I came from the say() function in the Messeger class." ;
}

//ComponentInterface:
bool Messeger::implements( std::string interfaceName )
{
    return (interfaceName == "ComponentInterface" || interfaceName == "Messeger") ?
        implemented = true
            : implemented = false ;
}

void* Messeger::getInstance()
{
    if( implemented ) {  referenceCounter++ ;  return this ; }
    return NULL ;
}

void Messeger::release()
{
    referenceCounter-- ;
    if( referenceCounter <= 0 ) delete this ;
}

extern "C" ComponentInterface* create() ;

ComponentInterface* create()
{
    return (ComponentInterface*) new Messeger ;
}
