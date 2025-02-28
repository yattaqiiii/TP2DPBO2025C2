public class Baju extends Aksesoris {
    // Additional attributes
    private String untuk;
    private String size;
    private String merk;
    
    // Constructor
    public Baju(int id, String nama_produk, int harga_produk, int stok_produk,
                String jenis, String bahan, String warna,
                String untuk, String size, String merk) {
        // Call the parent constructor
        super(id, nama_produk, harga_produk, stok_produk, jenis, bahan, warna);
        
        // Initialize additional attributes
        this.untuk = untuk;
        this.size = size;
        this.merk = merk;
    }
    
    // Getter methods
    public String getUntuk() {
        return untuk;
    }
    
    public String getSize() {
        return size;
    }
    
    public String getMerk() {
        return merk;
    }
    
    // Setter methods
    public void setUntuk(String untuk) {
        this.untuk = untuk;
    }
    
    public void setSize(String size) {
        this.size = size;
    }
    
    public void setMerk(String merk) {
        this.merk = merk;
    }
}