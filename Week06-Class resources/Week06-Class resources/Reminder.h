
namespace sdds {
	class Reminder
	{
	public:
		char* title;
		
		Reminder() = default;
		Reminder(const char*);
		//Reminder(Reminder&); // copy constructor
		~Reminder();
		Reminder* getReminder() ;
		//Reminder& operator= (const Reminder& n);
		void deAllocSafely();
	};
}

