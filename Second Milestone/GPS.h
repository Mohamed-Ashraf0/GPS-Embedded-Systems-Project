
#ifndef GPS_H_
#define GPS_H_
double GPS_convertToRad(double degValue); 
//double GPS_getDistance(double currentLat,double currentLong,double previousLat,double previousLong);
double computeDistance(double lat1, double long1, double lat2, double long2);
void GPS_read (); 
#endif
