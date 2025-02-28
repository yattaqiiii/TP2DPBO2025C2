from Aksesoris import Aksesoris

class Baju(Aksesoris):
    # Constructor
    def __init__(self, id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna, untuk, size, merk):
        # Memanggil constructor dari parent class (Aksesoris)
        super().__init__(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna)
        
        # Atribut tambahan untuk Baju
        self.__untuk = untuk
        self.__size = size
        self.__merk = merk
    
    # Getter methods
    def get_untuk(self):
        return self.__untuk
    
    def get_size(self):
        return self.__size
    
    def get_merk(self):
        return self.__merk
    
    # Setter methods
    def set_untuk(self, untuk):
        self.__untuk = untuk
    
    def set_size(self, size):
        self.__size = size
    
    def set_merk(self, merk):
        self.__merk = merk