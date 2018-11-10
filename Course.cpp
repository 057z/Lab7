#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & course) : title (course.title), day (course.day), start_time (course.start_time), finish_time (course.finish_time)
{
}

Course & Course::operator =(const Course & course) = default;

bool Course::operator == (const Course & course) const {
    //TODO implement the operator
    return title == course.title && day == course.day && start_time == course.start_time && finish_time == course.finish_time;
}

bool Course::operator < (const Course & course) const
{
    //TODO implement the operator
    if(day == course.day) {
        if(start_time < course.start_time) {
            return true;
        }
    }
    return day < course.day;
}
string convertDayToString(Course::dayOfWeek day) {
    switch(day) {
        case Course::MON:
            return "M";
        case Course::TUE:
            return "T";
        case Course::WED:
            return "w";
        case Course::FRI:
            return "F";
        default:
            break;
    }
}
ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator

    os << m.title
       <<  " " << convertDayToString(m.day)
       << " " << m.start_time
       << " " << m.finish_time;
    return os;
}