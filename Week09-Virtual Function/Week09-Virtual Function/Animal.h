#ifndef SDDS_ANIMAL_H__
#define SDDS_ANIMAL_H__
#include "Animalia.h"
namespace sdds {
    class Animal// : public Animalia 
    {
        char m_name[41];
    public:
        Animal(const char* name = "Nameless");
        Animal(Animal&);
        const char* name()const;
        // for ensuring recent implementation being called using dynamic binding
        void name(const char* value);

      /*
        virtual void act();
        virtual void sound();
        virtual void move();
      //virtual Animal& operator=(Animal&); 
        virtual ~Animal();
        */
 
        
        void act();
        void move();
        void sound();
       virtual Animal& operator=(Animal&); // with or without virtual
      
        ~Animal();
       
    };
 
    extern bool debug;
}
#endif
