class PetShop:
    # Constructor
    def __init__(self, id, nama_produk, harga_produk, stok_produk):
        self.__id = id
        self.__nama_produk = nama_produk
        self.__harga_produk = harga_produk
        self.__stok_produk = stok_produk
    
    # Getter methods
    def get_id(self):
        return self.__id
    
    def get_nama_produk(self):
        return self.__nama_produk
    
    def get_harga_produk(self):
        return self.__harga_produk
    
    def get_stok_produk(self):
        return self.__stok_produk
    
    # Setter methods
    def set_id(self, id):
        self.__id = id
    
    def set_nama_produk(self, nama_produk):
        self.__nama_produk = nama_produk
    
    def set_harga_produk(self, harga_produk):
        self.__harga_produk = harga_produk
    
    def set_stok_produk(self, stok_produk):
        self.__stok_produk = stok_produk