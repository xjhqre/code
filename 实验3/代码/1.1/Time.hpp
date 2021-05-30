//DateTime.hpp
class DateTime{
public:
    void showTime();
    void setTime();
    double diff(const DateTime& T);
private:
    long normalize() const; 
    long countdays() const;
    int year;
    int mon;
    int day;
    int hour;
    int minute;
    int second;
};
