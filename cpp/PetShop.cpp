#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

// Base class PetShop
class PetShop {
private:
    string id;
    string nama_produk;
    int harga_produk;
    int stok_produk;

public:
    // Constructors
    PetShop() {
        this->id = "";
        this->nama_produk = "";
        this->harga_produk = 0;
        this->stok_produk = 0;
    }

    PetShop(string id, string nama_produk, int harga_produk, int stok_produk) {
        this->id = id;
        this->nama_produk = nama_produk;
        this->harga_produk = harga_produk;
        this->stok_produk = stok_produk;
    }

    // Getters
    string getId() {
        return this->id;
    }

    string getNama() {
        return this->nama_produk;
    }

    int getHarga() {
        return this->harga_produk;
    }

    int getStok() {
        return this->stok_produk;
    }

    // Setters
    void setId(string id) {
        this->id = id;
    }

    void setNama(string nama_produk) {
        this->nama_produk = nama_produk;
    }

    void setHarga(int harga_produk) {
        this->harga_produk = harga_produk;
    }

    void setStok(int stok_produk) {
        this->stok_produk = stok_produk;
    }

    // Destructor
    ~PetShop() {}
};

// Child class Aksesoris inherits from PetShop
class Aksesoris : public PetShop {
private:
    string jenis;
    string bahan;
    string warna;

public:
    // Constructors
    Aksesoris() : PetShop() {
        this->jenis = "";
        this->bahan = "";
        this->warna = "";
    }

    Aksesoris(string id, string nama_produk, int harga_produk, int stok_produk, 
              string jenis, string bahan, string warna) 
              : PetShop(id, nama_produk, harga_produk, stok_produk) {
        this->jenis = jenis;
        this->bahan = bahan;
        this->warna = warna;
    }

    // Getters
    string getJenis() {
        return this->jenis;
    }

    string getBahan() {
        return this->bahan;
    }

    string getWarna() {
        return this->warna;
    }

    // Setters
    void setJenis(string jenis) {
        this->jenis = jenis;
    }

    void setBahan(string bahan) {
        this->bahan = bahan;
    }

    void setWarna(string warna) {
        this->warna = warna;
    }

    // Destructor
    ~Aksesoris() {}
};

// Grandchild class Baju inherits from Aksesoris
class Baju : public Aksesoris {
private:
    string untuk;
    string size;
    string merk;

public:
    // Constructors
    Baju() : Aksesoris() {
        this->untuk = "";
        this->size = "";
        this->merk = "";
    }

    Baju(string id, string nama_produk, int harga_produk, int stok_produk, 
         string jenis, string bahan, string warna, 
         string untuk, string size, string merk) 
         : Aksesoris(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna) {
        this->untuk = untuk;
        this->size = size;
        this->merk = merk;
    }

    // Getters
    string getUntuk() {
        return this->untuk;
    }

    string getSize() {
        return this->size;
    }

    string getMerk() {
        return this->merk;
    }

    // Setters
    void setUntuk(string untuk) {
        this->untuk = untuk;
    }

    void setSize(string size) {
        this->size = size;
    }

    void setMerk(string merk) {
        this->merk = merk;
    }

    // Destructor
    ~Baju() {}
};

// Function to find the maximum length of a string in an array of strings
int findMaxLength(string arr[], int size) {
    int maxLength = 0;
    for (int i = 0; i < size; i++) {
        maxLength = max(maxLength, (int)arr[i].length());
    }
    return maxLength;
}

int main() {
    // Arrays to store objects of each class
    PetShop listProduk[100];
    Aksesoris listAksesoris[100];
    Baju listBaju[100];
    
    int countProduk = 0;
    int countAksesoris = 0;
    int countBaju = 5; // Start with 5 initial Baju objects

    // Initialize 5 hardcoded Baju objects
    listBaju[0] = Baju("B001", "Kemeja Kucing", 75000, 10, "Formal", "Katun", "Biru", "Kucing", "S", "CatStyle");
    listBaju[1] = Baju("B002", "Sweater Anjing", 120000, 8, "Casual", "Wol", "Merah", "Anjing", "M", "DogFashion");
    listBaju[2] = Baju("B003", "Romper Kelinci", 85000, 15, "Casual", "Flanel", "Pink", "Kelinci", "XS", "BunnyWear");
    listBaju[3] = Baju("B004", "Jaket Husky", 150000, 5, "Outdoor", "Polyester", "Hitam", "Anjing", "L", "HuskyGear");
    listBaju[4] = Baju("B005", "Piyama Hamster", 60000, 20, "Tidur", "Katun", "Kuning", "Hamster", "XXS", "SmallPet");

    int choice;
    
    do {
        // Display menu
        cout << "\n===== MENU PETSHOP =====\n";
        cout << "1. Tampilkan Semua Data\n";
        cout << "2. Tambah Data Baru\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        
        if (choice == 1) {
            // Collect all strings for each column to determine max widths
            string allIds[countProduk + countAksesoris + countBaju];
            string allNames[countProduk + countAksesoris + countBaju];
            string allJenis[countAksesoris + countBaju];
            string allBahan[countAksesoris + countBaju];
            string allWarna[countAksesoris + countBaju];
            string allUntuk[countBaju];
            string allSize[countBaju];
            string allMerk[countBaju];
            
            int totalCount = 0;
            
            // Add PetShop products
            for (int i = 0; i < countProduk; i++) {
                allIds[totalCount] = listProduk[i].getId();
                allNames[totalCount] = listProduk[i].getNama();
                totalCount++;
            }
            
            // Add Aksesoris products
            for (int i = 0; i < countAksesoris; i++) {
                allIds[totalCount] = listAksesoris[i].getId();
                allNames[totalCount] = listAksesoris[i].getNama();
                allJenis[i] = listAksesoris[i].getJenis();
                allBahan[i] = listAksesoris[i].getBahan();
                allWarna[i] = listAksesoris[i].getWarna();
                totalCount++;
            }
            
            // Add Baju products
            for (int i = 0; i < countBaju; i++) {
                allIds[totalCount] = listBaju[i].getId();
                allNames[totalCount] = listBaju[i].getNama();
                allJenis[countAksesoris + i] = listBaju[i].getJenis();
                allBahan[countAksesoris + i] = listBaju[i].getBahan();
                allWarna[countAksesoris + i] = listBaju[i].getWarna();
                allUntuk[i] = listBaju[i].getUntuk();
                allSize[i] = listBaju[i].getSize();
                allMerk[i] = listBaju[i].getMerk();
                totalCount++;
            }
            
            // Find max widths for each column
            int idWidth = max(2, findMaxLength(allIds, totalCount));
            int nameWidth = max(11, findMaxLength(allNames, totalCount));
            int hargaWidth = 7; // "Harga" + some padding
            int stokWidth = 6;  // "Stok" + some padding
            int jenisWidth = max(5, findMaxLength(allJenis, countAksesoris + countBaju));
            int bahanWidth = max(5, findMaxLength(allBahan, countAksesoris + countBaju));
            int warnaWidth = max(5, findMaxLength(allWarna, countAksesoris + countBaju));
            int untukWidth = max(5, findMaxLength(allUntuk, countBaju));
            int sizeWidth = max(4, findMaxLength(allSize, countBaju));
            int merkWidth = max(4, findMaxLength(allMerk, countBaju));
            
            // Display all data in a dynamic table
            cout << "\n==== Data Semua Produk PetShop ====\n";
            
            // Print header with dynamic widths
            cout << "+" << string(idWidth + 2, '-') << "+"
                 << string(nameWidth + 2, '-') << "+"
                 << string(hargaWidth + 2, '-') << "+"
                 << string(stokWidth + 2, '-') << "+";
                 
            if (countAksesoris + countBaju > 0) {
                cout << string(jenisWidth + 2, '-') << "+"
                     << string(bahanWidth + 2, '-') << "+"
                     << string(warnaWidth + 2, '-') << "+";
            }
            
            if (countBaju > 0) {
                cout << string(untukWidth + 2, '-') << "+"
                     << string(sizeWidth + 2, '-') << "+"
                     << string(merkWidth + 2, '-') << "+";
            }
            cout << "\n";
            
            // Print column headers
            cout << "| " << left << setw(idWidth) << "ID" << " | "
                 << left << setw(nameWidth) << "Nama Produk" << " | "
                 << left << setw(hargaWidth) << "Harga" << " | "
                 << left << setw(stokWidth) << "Stok" << " |";
                 
            if (countAksesoris + countBaju > 0) {
                cout << " " << left << setw(jenisWidth) << "Jenis" << " | "
                     << left << setw(bahanWidth) << "Bahan" << " | "
                     << left << setw(warnaWidth) << "Warna" << " |";
            }
            
            if (countBaju > 0) {
                cout << " " << left << setw(untukWidth) << "Untuk" << " | "
                     << left << setw(sizeWidth) << "Size" << " | "
                     << left << setw(merkWidth) << "Merk" << " |";
            }
            cout << "\n";
            
            // Print separator line
            cout << "+" << string(idWidth + 2, '-') << "+"
                 << string(nameWidth + 2, '-') << "+"
                 << string(hargaWidth + 2, '-') << "+"
                 << string(stokWidth + 2, '-') << "+";
                 
            if (countAksesoris + countBaju > 0) {
                cout << string(jenisWidth + 2, '-') << "+"
                     << string(bahanWidth + 2, '-') << "+"
                     << string(warnaWidth + 2, '-') << "+";
            }
            
            if (countBaju > 0) {
                cout << string(untukWidth + 2, '-') << "+"
                     << string(sizeWidth + 2, '-') << "+"
                     << string(merkWidth + 2, '-') << "+";
            }
            cout << "\n";
            
            // Print PetShop products
            for (int i = 0; i < countProduk; i++) {
                cout << "| " << left << setw(idWidth) << listProduk[i].getId() << " | "
                     << left << setw(nameWidth) << listProduk[i].getNama() << " | "
                     << right << setw(hargaWidth) << listProduk[i].getHarga() << " | "
                     << right << setw(stokWidth) << listProduk[i].getStok() << " |";
                
                // Print empty cells for other columns
                if (countAksesoris + countBaju > 0) {
                    cout << " " << left << setw(jenisWidth) << "-" << " | "
                         << left << setw(bahanWidth) << "-" << " | "
                         << left << setw(warnaWidth) << "-" << " |";
                }
                
                if (countBaju > 0) {
                    cout << " " << left << setw(untukWidth) << "-" << " | "
                         << left << setw(sizeWidth) << "-" << " | "
                         << left << setw(merkWidth) << "-" << " |";
                }
                cout << "\n";
            }
            
            // Print Aksesoris products
            for (int i = 0; i < countAksesoris; i++) {
                cout << "| " << left << setw(idWidth) << listAksesoris[i].getId() << " | "
                     << left << setw(nameWidth) << listAksesoris[i].getNama() << " | "
                     << right << setw(hargaWidth) << listAksesoris[i].getHarga() << " | "
                     << right << setw(stokWidth) << listAksesoris[i].getStok() << " | "
                     << left << setw(jenisWidth) << listAksesoris[i].getJenis() << " | "
                     << left << setw(bahanWidth) << listAksesoris[i].getBahan() << " | "
                     << left << setw(warnaWidth) << listAksesoris[i].getWarna() << " |";
                
                // Print empty cells for Baju columns
                if (countBaju > 0) {
                    cout << " " << left << setw(untukWidth) << "-" << " | "
                         << left << setw(sizeWidth) << "-" << " | "
                         << left << setw(merkWidth) << "-" << " |";
                }
                cout << "\n";
            }
            
            // Print Baju products
            for (int i = 0; i < countBaju; i++) {
                cout << "| " << left << setw(idWidth) << listBaju[i].getId() << " | "
                     << left << setw(nameWidth) << listBaju[i].getNama() << " | "
                     << right << setw(hargaWidth) << listBaju[i].getHarga() << " | "
                     << right << setw(stokWidth) << listBaju[i].getStok() << " | "
                     << left << setw(jenisWidth) << listBaju[i].getJenis() << " | "
                     << left << setw(bahanWidth) << listBaju[i].getBahan() << " | "
                     << left << setw(warnaWidth) << listBaju[i].getWarna() << " | "
                     << left << setw(untukWidth) << listBaju[i].getUntuk() << " | "
                     << left << setw(sizeWidth) << listBaju[i].getSize() << " | "
                     << left << setw(merkWidth) << listBaju[i].getMerk() << " |\n";
            }
            
            // Print closing line
            cout << "+" << string(idWidth + 2, '-') << "+"
                 << string(nameWidth + 2, '-') << "+"
                 << string(hargaWidth + 2, '-') << "+"
                 << string(stokWidth + 2, '-') << "+";
                 
            if (countAksesoris + countBaju > 0) {
                cout << string(jenisWidth + 2, '-') << "+"
                     << string(bahanWidth + 2, '-') << "+"
                     << string(warnaWidth + 2, '-') << "+";
            }
            
            if (countBaju > 0) {
                cout << string(untukWidth + 2, '-') << "+"
                     << string(sizeWidth + 2, '-') << "+"
                     << string(merkWidth + 2, '-') << "+";
            }
            cout << "\n";
            
        } else if (choice == 2) {
            // Submenu for adding new data
            int produkType;
            cout << "\n=== TAMBAH DATA BARU ===\n";
            cout << "1. Tambah PetShop\n";
            cout << "2. Tambah Aksesoris\n";
            cout << "3. Tambah Baju\n";
            cout << "Pilihan: ";
            cin >> produkType;
            
            string id, nama;
            int harga, stok;
            
            // Common input for all types
            cout << "ID: ";
            cin >> id;
            
            cin.ignore();
            cout << "Nama Produk: ";
            getline(cin, nama);
            
            cout << "Harga: ";
            cin >> harga;
            
            cout << "Stok: ";
            cin >> stok;
            
            if (produkType == 1) {
                // Add PetShop product
                listProduk[countProduk] = PetShop(id, nama, harga, stok);
                countProduk++;
                cout << "Data PetShop berhasil ditambahkan!\n";
                
            } else if (produkType == 2) {
                // Add Aksesoris product with additional inputs
                string jenis, bahan, warna;
                
                cin.ignore();
                cout << "Jenis: ";
                getline(cin, jenis);
                
                cout << "Bahan: ";
                getline(cin, bahan);
                
                cout << "Warna: ";
                getline(cin, warna);
                
                listAksesoris[countAksesoris] = Aksesoris(id, nama, harga, stok, jenis, bahan, warna);
                countAksesoris++;
                cout << "Data Aksesoris berhasil ditambahkan!\n";
                
            } else if (produkType == 3) {
                // Add Baju product with all additional inputs
                string jenis, bahan, warna, untuk, size, merk;
                
                cin.ignore();
                cout << "Jenis: ";
                getline(cin, jenis);
                
                cout << "Bahan: ";
                getline(cin, bahan);
                
                cout << "Warna: ";
                getline(cin, warna);
                
                cout << "Untuk (jenis hewan): ";
                getline(cin, untuk);
                
                cout << "Size: ";
                getline(cin, size);
                
                cout << "Merk: ";
                getline(cin, merk);
                
                listBaju[countBaju] = Baju(id, nama, harga, stok, jenis, bahan, warna, untuk, size, merk);
                countBaju++;
                cout << "Data Baju berhasil ditambahkan!\n";
            }
        }
        
    } while (choice != 0);
    
    cout << "Terima kasih telah menggunakan program ini!\n";
    
    return 0;
}