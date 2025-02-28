from PetShop import PetShop

class Aksesoris(PetShop):
    # Constructor
    def __init__(self, id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna):
        # Memanggil constructor dari parent class (PetShop)
        super().__init__(id, nama_produk, harga_produk, stok_produk)
        
        # Atribut tambahan untuk Aksesoris
        self.__jenis = jenis
        self.__bahan = bahan
        self.__warna = warna
    
    # Getter methods
    def get_jenis(self):
        return self.__jenis
    
    def get_bahan(self):
        return self.__bahan
    
    def get_warna(self):
        return self.__warna
    
    # Setter methods
    def set_jenis(self, jenis):
        self.__jenis = jenis
    
    def set_bahan(self, bahan):
        self.__bahan = bahan
    
    def set_warna(self, warna):
        self.__warna = warna