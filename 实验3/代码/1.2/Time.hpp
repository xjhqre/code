class Date;
class Time{
public:
    void showTime();
    void setTime();
    double diff(Time& T);
private:
    long normalize(); 
    class Date *m_date;
    int hour;
    int minute;
    int second;
};
