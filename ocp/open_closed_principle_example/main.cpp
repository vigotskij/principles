/**
* Copyright (c) 2015 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include "include/ComponentFactory.h"
#include "include/ComponentInterface.h"
#include "include/ApplicationInterface.h"

int main()
{
    ComponentFactory* componentFactoryObject = new ComponentFactory();
    componentFactoryObject->setInterfaceName("ApplicationInterface");
    ComponentInterface* applicationComponent = componentFactoryObject->createFrom("./Application");
    delete componentFactoryObject;

    ApplicationInterface* applicationObject = ( (ApplicationInterface*) applicationComponent->getInstance() );
    applicationObject->run();
    applicationComponent->release();

    return 0;
}