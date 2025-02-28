
public class PetShop {
    // Attributes
    private int id;
    private String nama_produk;
    private int harga_produk;
    private int stok_produk;
    
    // Constructor
    public PetShop(int id, String nama_produk, int harga_produk, int stok_produk) {
        this.id = id;
        this.nama_produk = nama_produk;
        this.harga_produk = harga_produk;
        this.stok_produk = stok_produk;
    }
    
    // Getter methods
    public int getId() {
        return id;
    }
    
    public String getNamaProduk() {
        return nama_produk;
    }
    
    public int getHargaProduk() {
        return harga_produk;
    }
    
    public int getStokProduk() {
        return stok_produk;
    }
    
    // Setter methods
    public void setId(int id) {
        this.id = id;
    }
    
    public void setNamaProduk(String nama_produk) {
        this.nama_produk = nama_produk;
    }
    
    public void setHargaProduk(int harga_produk) {
        this.harga_produk = harga_produk;
    }
    
    public void setStokProduk(int stok_produk) {
        this.stok_produk = stok_produk;
    }
}