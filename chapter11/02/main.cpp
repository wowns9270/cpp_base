#include "../include/Student.h"
#include "../include/Teacher.h"


int main()
{

    Student st("Jack Jack");
    Teacher tc("Dr. H");

   std::cout<< st.GetName() << std::endl;
   std::cout<< tc.GetName() << std::endl;

   std::cout << st << std::endl;
   std::cout << tc << std::endl;

   st.study();
   tc.teach();
}