#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define Sensor struct
struct Sensor {
    int id;
    double temperature;
    double voltage;
    char status[20]; // fixed-size char array
};

void print_sensor(int index, int id, double temperature, double voltage, const char* status) {
    cout << "Sensor[" << index << "]: "
         << "id=" << id << ", "
         << "temperature=" << temperature << ", "
         << "voltage=" << voltage << ", "
         << "status=" << status << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_sensors;
    input >> num_sensors;

    const int MAX_SENSORS = 10;
    if (num_sensors > MAX_SENSORS) {
        cerr << "Too many sensors in input (max " << MAX_SENSORS << ")" << endl;
        return 1;
    }

    // Create an array of Sensor
    Sensor sensors[MAX_SENSORS];

    // Read sensor data from input
    for (int i = 0; i < num_sensors; i++) {
        input >> sensors[i].id
              >> sensors[i].temperature
              >> sensors[i].voltage
              >> sensors[i].status;
    }

    // Iterate using a pointer and print sensor data
    Sensor* ptr = sensors;
    for (int i = 0; i < num_sensors; i++, ptr++) {
        print_sensor(i, ptr->id, ptr->temperature, ptr->voltage, ptr->status);
    }

    return 0;
}
