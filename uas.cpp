#include <cmath>
#include <iostream>

using namespace std;

struct Data {
  float x;
  float y;
};

float determinasi(Data data[], int n) {
  float x_mean = 0, y_mean = 0, xy_mean = 0, x_kuadrat_mean = 0;
  for (int i = 0; i < n; i++) {
    x_mean += data[i].x;
    y_mean += data[i].y;
    xy_mean += data[i].x * data[i].y;
    x_kuadrat_mean += pow(data[i].x, 2);
  }
  x_mean /= n;
  y_mean /= n;
  xy_mean /= n;
  x_kuadrat_mean /= n;
  float r = (n * xy_mean - x_mean * y_mean) /
            sqrt((n * x_kuadrat_mean - pow(x_mean, 2)) *
                 (n * pow(y_mean, 2) - pow(y_mean, 2)));
  return r * r * 100;
}

int main() {
  int n;
  cout << "============= UAS ============" << endl;
  cout << "Matakuliah : Pemograman Dasar" << endl;
  cout << "Dosen      : Bpk. Galih Ashari Rakhmat, S.Si., M.T." << endl;
  cout << "NRP        : 15-2020-065" << endl;
  cout << "Nama       : David Ramadhan" << endl;
  cout << "\n\n";
  cout << "Masukkan jumlah pasangan data: ";
  cin >> n;

  Data data[n];

  for (int i = 0; i < n; i++) {
    cout << "Masukkan nilai x ke-" << i + 1 << ": ";
    cin >> data[i].x;
    while (data[i].x < 0) {
      cout << "Nilai x tidak boleh kurang dari 0. Silakan masukkan nilai x "
              "lagi: ";
      cin >> data[i].x;
    }

    cout << "Masukkan nilai y ke-" << i + 1 << ": ";
    cin >> data[i].y;
    while (data[i].y < 0) {
      cout << "Nilai y tidak boleh kurang dari 0. Silakan masukkan nilai y "
              "lagi: ";
      cin >> data[i].y;
    }
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << "Data ke-" << i + 1 << ": {" << data[i].x << ", " << data[i].y
         << "}" << endl;
  }
  cout << "\n";
  float nilai_determinasi = determinasi(data, n);
  cout << "Nilai koefisien determinasi (r² x 100%): " << nilai_determinasi
       << "%" << endl;

  cout << "\n";
  cout << "\n";
  cout << "Thank you, keep healthy Sir." << endl;
  return 0;
}
