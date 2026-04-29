#include <bits/stdc++.h>

using namespace std;

signed main(){
    long double pi = M_PI;
    long double g = 9.80665;
    long double masa = 7.26;
    long double coeficiente = 0.44;
    long double area_frontal = pi*0.06*0.06;
    long double paso_tiempo = 1.0/10000.0;
    long double altura = 3;
    long double vel_salida = 15;
    long double ang = pi*(41.6)/180;
    long double distancia = 0;
    long double densidad = 1.155;
    long double vel_x = vel_salida*cos(ang);
    long double vel_y = vel_salida*sin(ang);
    long double cons_rozamiento = 0.5*coeficiente*area_frontal*densidad;
    bool subiendo = true;
    bool ultimo_paso = false;
    while(altura > 0){
        if(subiendo == false && abs(altura/vel_y) < paso_tiempo){
            paso_tiempo = ((vel_y+sqrt(vel_y*vel_y+2*g*altura))/g);
            ultimo_paso = true;
        }
        long double copy_vel_x = vel_x;
        long double copy_vel_y = vel_y;
        long double vel_total = sqrt(vel_y*vel_y+vel_x*vel_x);
        long double fuerza_rozamiento = cons_rozamiento*vel_total*vel_total;
        long double aceleracion_rozamiento_x = (fuerza_rozamiento*vel_x/vel_total)/masa;
        long double aceleracion_rozamiento_y = (fuerza_rozamiento*abs(vel_y/vel_total))/masa;
        copy_vel_x -= aceleracion_rozamiento_x*paso_tiempo;
        if(subiendo == true){
            copy_vel_y -= (g+aceleracion_rozamiento_y)*paso_tiempo;
            if(copy_vel_y <=0){
                subiendo = false;
            }
        }
        else{
            copy_vel_y -= (g-aceleracion_rozamiento_y)*paso_tiempo;
        }
        distancia += ((vel_x+copy_vel_x)/2)*paso_tiempo;
        altura += ((vel_y+copy_vel_y)/2)*paso_tiempo;
        vel_y = copy_vel_y;
        vel_x = copy_vel_x;
        if(ultimo_paso == true){
            break;
        }
    }
    cout << fixed << setprecision(15) << distancia << endl;
}
