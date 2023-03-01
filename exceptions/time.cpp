#include <iostream>
#include <stdexcept>
#include <exception>

class Time
{
    protected:
    int hours, minutes, seconds;

    public:

    void setHours(int nhours)
    {
        if(nhours < 0 || nhours > 23) throw std::invalid_argument("setHours: invalid argument");
        hours = nhours;
    }
    void setMinutes(int nminutes)
    {
        if(nminutes < 0 || nminutes > 59) throw std::invalid_argument("setMinutes: invalid argument");
        minutes = nminutes;
    }
    void setSeconds(int nseconds)
    {
        if(nseconds < 0 || nseconds > 59) throw std::invalid_argument("setSeconds: invalid argument");
        seconds = nseconds;
    }
    Time(const int& nhours = 0, const int& nminutes = 0, const int& nseconds = 0)
    {
        hours = 0, minutes = 0, seconds = 0;
        setHours(nhours);
        setMinutes(nminutes);
        setSeconds(nseconds);
    }

    int Hours() const {return hours;}
    int Minutes() const {return minutes;}
    int Seconds() const {return seconds;}
};

Time operator+(const Time& lhs, const Time& rhs)
{
    int nseconds = (lhs.Seconds() + rhs.Seconds()) % 60;
    int carry = (lhs.Seconds() + rhs.Seconds()) / 60;

    int nminutes = (lhs.Minutes() + rhs.Minutes() + carry) % 60;
    carry = (lhs.Minutes() + rhs.Minutes() + carry) / 60;

    int nhours = (lhs.Hours() + rhs.Hours() + carry) % 24;

    return Time(nhours, nminutes, nseconds);
}

bool operator>(const Time& lhs, const Time& rhs)
{
    if(lhs.Hours() != rhs.Hours())      return lhs.Hours() > rhs.Hours();
    if(lhs.Minutes() != rhs.Minutes())  return lhs.Minutes() > rhs.Minutes();
    if(lhs.Seconds() != rhs.Seconds())  return lhs.Seconds() > rhs.Seconds();
    return false;
}

std::ostream& operator<<(std::ostream& stream, const Time& obj)
{return stream << obj.Hours() << ":" << obj.Minutes() << ":" << obj.Seconds(); }

int main(void)
{
    Time t1 = Time(7, 42, 12);
    Time t2 = Time(22, 27, 30);
    std::cout << t1 << "+\n" << t2 << "=\n" << t1 + t2 << std::endl;
    return 0;
}