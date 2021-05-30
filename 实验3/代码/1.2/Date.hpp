class Date{
public:
    void showDate();
    void setDate();
    long normalize(); //年份月份转天数
private:
    int year;
    int mon;
    int day;
};
