#pragma once
#include<iostream>
#include<string>

class Person
{

protected:
   std::string m_name;

public:
   Person(const std::string &name_in = "No name") 
   :m_name(name_in)
   {
   }

    
    void SetName(const std::string &name_in)
    {
        m_name = name_in;
    }

    std::string GetName() const
    {
        return m_name;
    }



};