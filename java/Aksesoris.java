public class Aksesoris extends PetShop {
    // Additional attributes
    private String jenis;
    private String bahan;
    private String warna;
    
    // Constructor
    public Aksesoris(int id, String nama_produk, int harga_produk, int stok_produk, 
                     String jenis, String bahan, String warna) {
        // Call the parent constructor
        super(id, nama_produk, harga_produk, stok_produk);
        
        // Initialize additional attributes
        this.jenis = jenis;
        this.bahan = bahan;
        this.warna = warna;
    }
    
    // Getter methods
    public String getJenis() {
        return jenis;
    }
    
    public String getBahan() {
        return bahan;
    }
    
    public String getWarna() {
        return warna;
    }
    
    // Setter methods
    public void setJenis(String jenis) {
        this.jenis = jenis;
    }
    
    public void setBahan(String bahan) {
        this.bahan = bahan;
    }
    
    public void setWarna(String warna) {
        this.warna = warna;
    }
}