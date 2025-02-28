import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Scanner for user input
    private static Scanner scanner = new Scanner(System.in);
    
    // Method to display table of products
    private static void displayTable(ArrayList<PetShop> products) {
        // Table headers
        String[] headers = {"ID", "Nama Produk", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk"};
        
        // Determine column widths based on data
        int[] colWidths = new int[headers.length];
        for (int i = 0; i < headers.length; i++) {
            colWidths[i] = headers[i].length();
        }
        
        // Check data widths and adjust column widths
        for (PetShop product : products) {
            String[] data = {
                String.valueOf(product.getId()),
                product.getNamaProduk(),
                String.valueOf(product.getHargaProduk()),
                String.valueOf(product.getStokProduk()),
                (product instanceof Aksesoris) ? ((Aksesoris) product).getJenis() : "-",
                (product instanceof Aksesoris) ? ((Aksesoris) product).getBahan() : "-",
                (product instanceof Aksesoris) ? ((Aksesoris) product).getWarna() : "-",
                (product instanceof Baju) ? ((Baju) product).getUntuk() : "-",
                (product instanceof Baju) ? ((Baju) product).getSize() : "-",
                (product instanceof Baju) ? ((Baju) product).getMerk() : "-"
            };
            
            for (int i = 0; i < data.length; i++) {
                colWidths[i] = Math.max(colWidths[i], data[i].length());
            }
        }
        
        // Create horizontal separator for table
        StringBuilder separator = new StringBuilder("+");
        for (int width : colWidths) {
            separator.append("-".repeat(width + 2)).append("+");
        }
        
        // Display table header
        System.out.println(separator);
        
        StringBuilder headerRow = new StringBuilder("|");
        for (int i = 0; i < headers.length; i++) {
            headerRow.append(" ").append(padRight(headers[i], colWidths[i])).append(" |");
        }
        System.out.println(headerRow);
        System.out.println(separator);
        
        // Display product data
        for (PetShop product : products) {
            StringBuilder row = new StringBuilder("|");
            
            // Prepare data for each product
            String[] data = {
                String.valueOf(product.getId()),
                product.getNamaProduk(),
                String.valueOf(product.getHargaProduk()),
                String.valueOf(product.getStokProduk()),
                (product instanceof Aksesoris) ? ((Aksesoris) product).getJenis() : "-",
                (product instanceof Aksesoris) ? ((Aksesoris) product).getBahan() : "-",
                (product instanceof Aksesoris) ? ((Aksesoris) product).getWarna() : "-",
                (product instanceof Baju) ? ((Baju) product).getUntuk() : "-",
                (product instanceof Baju) ? ((Baju) product).getSize() : "-",
                (product instanceof Baju) ? ((Baju) product).getMerk() : "-"
            };
            
            for (int i = 0; i < data.length; i++) {
                row.append(" ").append(padRight(data[i], colWidths[i])).append(" |");
            }
            
            System.out.println(row);
        }
        
        System.out.println(separator);
    }
    
    // Helper method to pad strings for table formatting
    private static String padRight(String s, int n) {
        return String.format("%-" + n + "s", s);
    }
    
    // Method to add a new product
    private static void addProduct(ArrayList<PetShop> products) {
        System.out.println("\n=== Tambah Produk Baru ===");
        System.out.println("1. Tambah Produk PetShop");
        System.out.println("2. Tambah Produk Aksesoris");
        System.out.println("3. Tambah Produk Baju");
        System.out.print("Pilih jenis produk (1/2/3): ");
        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        // Common data for all product types
        int id = products.size() + 1;
        
        System.out.print("Nama Produk: ");
        String namaProduk = scanner.nextLine();
        
        System.out.print("Harga Produk: ");
        int hargaProduk = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        System.out.print("Stok Produk: ");
        int stokProduk = scanner.nextInt();
        scanner.nextLine(); // Consume newline
        
        if (choice == 1) {
            // Add PetShop product
            products.add(new PetShop(id, namaProduk, hargaProduk, stokProduk));
            System.out.println("Produk PetShop berhasil ditambahkan!");
            
        } else if (choice == 2) {
            // Add Aksesoris product
            System.out.print("Jenis Aksesoris: ");
            String jenis = scanner.nextLine();
            
            System.out.print("Bahan: ");
            String bahan = scanner.nextLine();
            
            System.out.print("Warna: ");
            String warna = scanner.nextLine();
            
            products.add(new Aksesoris(id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna));
            System.out.println("Produk Aksesoris berhasil ditambahkan!");
            
        } else if (choice == 3) {
            // Add Baju product
            System.out.print("Jenis Aksesoris: ");
            String jenis = scanner.nextLine();
            
            System.out.print("Bahan: ");
            String bahan = scanner.nextLine();
            
            System.out.print("Warna: ");
            String warna = scanner.nextLine();
            
            System.out.print("Untuk (Kucing/Anjing/dll): ");
            String untuk = scanner.nextLine();
            
            System.out.print("Size (S/M/L/XL): ");
            String size = scanner.nextLine();
            
            System.out.print("Merk: ");
            String merk = scanner.nextLine();
            
            products.add(new Baju(id, namaProduk, hargaProduk, stokProduk, jenis, bahan, warna, untuk, size, merk));
            System.out.println("Produk Baju berhasil ditambahkan!");
            
        } else {
            System.out.println("Pilihan tidak valid!");
        }
    }
    
    public static void main(String[] args) {
        // Initialize product list with 5 initial objects
        ArrayList<PetShop> products = new ArrayList<>();
        
        // Adding 5 hardcoded products
        products.add(new Baju(1, "Baju Kucing Polkadot", 45000, 10, "Pakaian", "Katun", "Merah", "Kucing", "M", "PetLover"));
        products.add(new Baju(2, "Sweater Anjing", 75000, 8, "Pakaian", "Wol", "Biru", "Anjing", "L", "DoggyStyle"));
        products.add(new Aksesoris(3, "Kalung Kucing", 25000, 15, "Aksesoris Leher", "Kulit", "Hitam"));
        products.add(new Aksesoris(4, "Topi Pet", 35000, 5, "Aksesoris Kepala", "Kain", "Kuning"));
        products.add(new PetShop(5, "Tempat Makan", 50000, 20));
        
        // Main program loop
        boolean running = true;
        while (running) {
            System.out.println("\n=== PETSHOP MANAGEMENT SYSTEM ===");
            System.out.println("1. Tampilkan Semua Produk");
            System.out.println("2. Tambah Produk Baru");
            System.out.println("3. Keluar");
            System.out.print("Pilih menu (1/2/3): ");
            
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            
            switch (choice) {
                case 1:
                    displayTable(products);
                    break;
                case 2:
                    addProduct(products);
                    break;
                case 3:
                    System.out.println("Terima kasih! Program selesai.");
                    running = false;
                    break;
                default:
                    System.out.println("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.");
                    break;
            }
        }
        
        // Close scanner
        scanner.close();
    }
}