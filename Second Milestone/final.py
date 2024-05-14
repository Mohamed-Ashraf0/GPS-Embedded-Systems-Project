import folium
import serial
out = open("outt.txt", 'w')
ser = serial.Serial('/dev/ttyUSB0')
def read_until_char(serial_port, char):
    #with serial.Serial(serial_port) as ser:
    while True:
        print("got until "+char+" char \n")
        data = ser.read().decode('utf-8')
        print(data, end='')  # Print the received data
        if data == char:
            break

def plot_coordinates_from_file(input_file, output_file):
    # Read latitude and longitude from the text file
    with open(input_file, 'r') as file:
        lines = file.readlines()

    latitudes = []
    longitudes = []
    for line in lines:
        lat, lon = map(float, line.strip().split(','))
        latitudes.append(lat)
        longitudes.append(lon)

    # Create a map centered around the mean of latitudes and longitudes
    m = folium.Map(location=[sum(latitudes)/len(latitudes), sum(longitudes)/len(longitudes)], zoom_start=13)

    # Create a polyline connecting the points
    points = list(zip(latitudes, longitudes))
    folium.PolyLine(points, color="red", weight=2.5, opacity=1).add_to(m)

    # Save the map to an HTML file
    m.save(output_file)
    print(f"Map saved as {output_file}")



def main():
    serial_port = '/dev/ttyUSB0'  # Specify the serial port here
    print("serial port done \n")
    ser.write(b'U')
    print("Done U \n")
    res = ""
    while(1):
        lat_str = ''
        lat_str += res
        print("waiting for lat \n")
        while True:
            data = ser.read().decode('utf-8')
            print(data, end='')  # Print the received data
            if data == 'L':
                break
            if data =='\n':
                continue
            lat_str += data

        # Convert the received string to a float (latitude)
        Lat = float(lat_str)
        print("\n done for lat \n")
        out.write(lat_str)
        out.write(", ")
        # Read input until 'L' is received (excluding 'L')
        lon_str = ''
        print("\n waiting for lon \n")
        while True:
            data = ser.read().decode('utf-8')
            print(data, end='')  # Print the received data
            if data == 'L':
                break
            if data =='\n':
                continue
            lon_str += data

        # Convert the received string to a float (longitude)
        Lon = float(lon_str)
        print("\n Done for lon \n")
        out.write(lon_str)
        out.write("\n")

        print("Latitude:", Lat)
        print("Longitude:", Lon)

        # Check if 'E' is received to stop the loop
        data = ser.read().decode('utf-8')
        print("at the end got : "+data+"\n")
        if data == 'E':
            break
        else:
            res = data
    out.close()
    input_file = 'outt.txt'
    output_file = 'coordinates_map.html'
    plot_coordinates_from_file(input_file, output_file)
if __name__ == "__main__":
    main()
