#include "position.hpp"
#include <iostream>
#include <math.h>
using namespace std;

void position::set(double x, double y){
    m_x = x;
    m_y = y;
}

void position::show(){
    cout << m_x << ' ' << m_y << endl;
}

void position::move(double x, double y){
    m_x += x;
    m_y += y;
}

void position::move(double x){
    m_x += x;
}

double position::slope(position& p){
    double slope = 0;
    return slope = (m_y - p.m_y) / (m_x - p.m_x);
}

double position::slope(){
    double slope = 0;
    return slope = m_y / m_x;
}

double position::distance(position& p){
    return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}

double position::distance(){
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}
