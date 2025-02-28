from PetShop import PetShop
from Aksesoris import Aksesoris
from Baju import Baju

# Fungsi untuk menampilkan tabel dengan data produk
def display_table(products):
    # Menentukan lebar kolom berdasarkan data
    headers = ["ID", "Nama Produk", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"]
    col_widths = [len(header) for header in headers]
    
    # Memeriksa lebar data dan menyesuaikan lebar kolom
    for product in products:
        data = [
            str(product.get_id()),
            product.get_nama_produk(),
            str(product.get_harga_produk()),
            str(product.get_stok_produk()),
            product.get_jenis() if hasattr(product, 'get_jenis') else "-",
            product.get_bahan() if hasattr(product, 'get_bahan') else "-",
            product.get_warna() if hasattr(product, 'get_warna') else "-",
            product.get_untuk() if hasattr(product, 'get_untuk') else "-",
            product.get_size() if hasattr(product, 'get_size') else "-",
            product.get_merk() if hasattr(product, 'get_merk') else "-"
        ]
        
        for i, item in enumerate(data):
            col_widths[i] = max(col_widths[i], len(item))
    
    # Membuat garis horizontal untuk tabel
    separator = "+" + "+".join(["-" * (width + 2) for width in col_widths]) + "+"
    
    # Menampilkan header tabel
    print(separator)
    header_row = "|"
    for i, header in enumerate(headers):
        header_row += " " + header.ljust(col_widths[i]) + " |"
    print(header_row)
    print(separator)
    
    # Menampilkan data produk
    for product in products:
        data = [
            str(product.get_id()),
            product.get_nama_produk(),
            str(product.get_harga_produk()),
            str(product.get_stok_produk()),
            product.get_jenis() if hasattr(product, 'get_jenis') else "-",
            product.get_bahan() if hasattr(product, 'get_bahan') else "-",
            product.get_warna() if hasattr(product, 'get_warna') else "-",
            product.get_untuk() if hasattr(product, 'get_untuk') else "-",
            product.get_size() if hasattr(product, 'get_size') else "-",
            product.get_merk() if hasattr(product, 'get_merk') else "-"
        ]
        
        row = "|"
        for i, item in enumerate(data):
            row += " " + item.ljust(col_widths[i]) + " |"
        print(row)
    
    print(separator)

# Fungsi untuk menambahkan produk baru
def add_product(products):
    print("\n=== Tambah Produk Baru ===")
    print("1. Tambah Produk PetShop")
    print("2. Tambah Produk Aksesoris")
    print("3. Tambah Produk Baju")
    choice = input("Pilih jenis produk (1/2/3): ")
    
    # Meminta input data umum
    id = len(products) + 1
    nama_produk = input("Nama Produk: ")
    harga_produk = int(input("Harga Produk: "))
    stok_produk = int(input("Stok Produk: "))
    
    if choice == "1":
        # Tambah produk PetShop
        product = PetShop(id, nama_produk, harga_produk, stok_produk)
        products.append(product)
        print("Produk PetShop berhasil ditambahkan!")
    
    elif choice == "2":
        # Tambah produk Aksesoris
        jenis = input("Jenis Aksesoris: ")
        bahan = input("Bahan: ")
        warna = input("Warna: ")
        
        product = Aksesoris(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna)
        products.append(product)
        print("Produk Aksesoris berhasil ditambahkan!")
    
    elif choice == "3":
        # Tambah produk Baju
        jenis = input("Jenis Aksesoris: ")
        bahan = input("Bahan: ")
        warna = input("Warna: ")
        untuk = input("Untuk (Kucing/Anjing/dll): ")
        size = input("Size (S/M/L/XL): ")
        merk = input("Merk: ")
        
        product = Baju(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna, untuk, size, merk)
        products.append(product)
        print("Produk Baju berhasil ditambahkan!")
    
    else:
        print("Pilihan tidak valid!")

def main():
    # Inisialisasi 5 objek awal
    products = [
        Baju(1, "Baju Kucing Polkadot", 45000, 10, "Pakaian", "Katun", "Merah", "Kucing", "M", "PetLover"),
        Baju(2, "Sweater Anjing", 75000, 8, "Pakaian", "Wol", "Biru", "Anjing", "L", "DoggyStyle"),
        Aksesoris(3, "Kalung Kucing", 25000, 15, "Aksesoris Leher", "Kulit", "Hitam"),
        Aksesoris(4, "Topi Pet", 35000, 5, "Aksesoris Kepala", "Kain", "Kuning"),
        PetShop(5, "Tempat Makan", 50000, 20)
    ]
    
    while True:
        print("\n=== PETSHOP MANAGEMENT SYSTEM ===")
        print("1. Tampilkan Semua Produk")
        print("2. Tambah Produk Baru")
        print("3. Keluar")
        
        choice = input("Pilih menu (1/2/3): ")
        
        if choice == "1":
            display_table(products)
        elif choice == "2":
            add_product(products)
        elif choice == "3":
            print("Terima kasih! Program selesai.")
            break
        else:
            print("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.")

if __name__ == "__main__":
    main()