#include <bits/stdc++.h>

using namespace std;

signed main(){
    long double pi = M_PI;
    long double g = 9.80665;
    long double masa = 7.26;
    long double coeficiente = 0.44;
    long double area_frontal = pi*0.06*0.06;
    long double paso_tiempo = 1000000; //Esto es 1/paso_tiempo, porque después lo divido.
    long double altura = 2.1;
    long double vel_salida = 14;
    long double ang = pi*(37)/180;
    long double distancia = 0;
    long double densidad = 1.155;
    long double vel_x = vel_salida*cos(ang);
    long double vel_y = vel_salida*sin(ang);
    long double cons_rozamiento = 0.5*coeficiente*area_frontal*densidad;
    bool subiendo = true;
    while(altura > 0){
        distancia += vel_x/paso_tiempo;
        altura += vel_y/paso_tiempo;
        long double vel_total = sqrt(vel_y*vel_y+vel_x*vel_x);
        long double fuerza_rozamiento = cons_rozamiento*vel_total*vel_total;
        long double aceleracion_rozamiento_x = (fuerza_rozamiento*vel_x/vel_total)/masa;
        long double aceleracion_rozamiento_y = (fuerza_rozamiento*abs(vel_y/vel_total))/masa;
        vel_x -= aceleracion_rozamiento_x/paso_tiempo;
        if(subiendo == true){
            vel_y -= (g+aceleracion_rozamiento_y)/paso_tiempo;
            if(vel_y <=0){
                subiendo = false;
            }
        }
        else{
            vel_y -= (g-aceleracion_rozamiento_y)/paso_tiempo;
        }
    }
    cout << fixed << setprecision(15) << distancia << endl;
}
