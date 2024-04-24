#ifndef GPS_H_
#define GPS_H_
double GPS_convertToRad(double degValue); 
double GPS_getDistance(double currentLat,double currentLong,double previousLat,double previousLong);
void GPS_read (); 
#endif
