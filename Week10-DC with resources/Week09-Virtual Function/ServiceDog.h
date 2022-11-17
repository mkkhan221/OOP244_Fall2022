#pragma once
#include "Dog.h"
namespace sdds {
    class ServiceDog :
        public Dog

    {
        char m_type;
    public:
        ServiceDog(const char* name = "Charlie", int s = 3, const char type='a');
        ServiceDog(ServiceDog&);
        ServiceDog& operator=(ServiceDog d);
        char skillset();
        
        ~ServiceDog();
    };
}

