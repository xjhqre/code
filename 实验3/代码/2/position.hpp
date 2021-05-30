class position{
public:
	void set(double x = 0, double y = 0);
    void show();
    void move(double x, double y);
    void move(double x);
    double slope(position& p);
    double slope();
    double distance(position& p);
    double distance();
private:
	double m_x;
	double m_y;
}; 
