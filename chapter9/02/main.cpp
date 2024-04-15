#include<iostream>
#include<fstream>

class Point
{

private:
    double m_x, m_y, m_z;

public:
    Point(double x=0.0, double y =0.0 , double z = 0.0)
    :m_x(x)
    ,m_y(y)
    ,m_z(z)
    {
    }

    double getX() const  { return m_x; }
    double getY() const  { return m_y; }
    double getZ() const  { return m_z; }

    void print()
    {
        std::cout <<m_x <<" " << m_y << " " << m_z <<" " << std::endl;
    }

    /// member로 불가..
    friend std::ostream& operator << ( std::ostream &out , Point &point)
    {
        out << point.m_x <<" " << point.m_y <<" " << point.m_z ; 

        return out;
    }

};

int main()
{
    std::ofstream of("out.txt");

    Point p1(0.0, 0.1, 0.2);

    std::cout << p1 << std::endl;
    of << p1 << std::endl;

    of.close();
}