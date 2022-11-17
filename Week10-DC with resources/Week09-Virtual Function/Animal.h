#ifndef SDDS_ANIMAL_H__
#define SDDS_ANIMAL_H__
#include "Animalia.h"
namespace sdds {
    // abstract class 
    class Animal : public Animalia 
    {
        char m_name[41];
    public:
        Animal(const char* name = "Nameless");
        Animal(Animal&);
        const char* name()const;
        void name(const char* value);
      
        // no virtual keyword used because all these functions are already pure virtual in Anamalia class       
        void act()=0;
        void move()=0;
        void sound()=0;

        virtual Animal& operator=(Animal&); // with or without virtual
      
        ~Animal();
       
    };
 
    extern bool debug;
}
#endif
