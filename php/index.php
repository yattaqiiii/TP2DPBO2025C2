<?php
require('PetShop.php');

// Initialize session array if it doesn't exist
session_start();
if (!isset($_SESSION['bajuList'])) {
    // Create 5 hardcoded initial objects
    $_SESSION['bajuList'] = array(
        new Baju("B001", "Kemeja Kucing", 75000, 10, "cat_shirt.jpg", "Formal", "Katun", "Biru", "Kucing", "S", "CatStyle"),
        new Baju("B002", "Sweater Anjing", 120000, 8, "dog_sweater.jpg", "Casual", "Wol", "Merah", "Anjing", "M", "DogFashion"),
        new Baju("B003", "Romper Kelinci", 85000, 15, "rabbit_romper.jpg", "Casual", "Flanel", "Pink", "Kelinci", "XS", "BunnyWear"),
        new Baju("B004", "Jaket Husky", 150000, 5, "husky_jacket.jpg", "Outdoor", "Polyester", "Hitam", "Anjing", "L", "HuskyGear"),
        new Baju("B005", "Piyama Hamster", 60000, 20, "hamster_pajama.jpg", "Tidur", "Katun", "Kuning", "Hamster", "XXS", "SmallPet")
    );
}

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $uploadOk = 1;
    $foto = "";
    
    // Check if image file is an actual image or fake image
    if(isset($_FILES["foto"])) {
        $target_dir = "uploads/";
        
        // Create directory if it doesn't exist
        if (!file_exists($target_dir)) {
            mkdir($target_dir, 0777, true);
        }
        
        $foto = basename($_FILES["foto"]["name"]);
        $target_file = $target_dir . $foto;
        $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
        
        // Check if file already exists
        if (file_exists($target_file)) {
            $foto = time() . "_" . $foto; // Add timestamp to make filename unique
            $target_file = $target_dir . $foto;
        }
        
        // Check file size
        if ($_FILES["foto"]["size"] > 5000000) { // 5MB limit
            echo "<script>alert('Sorry, your file is too large.');</script>";
            $uploadOk = 0;
        }
        
        // Allow certain file formats
        if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
        && $imageFileType != "gif") {
            echo "<script>alert('Sorry, only JPG, JPEG, PNG & GIF files are allowed.');</script>";
            $uploadOk = 0;
        }
        
        // Check if $uploadOk is set to 0 by an error
        if ($uploadOk == 1) {
            if (move_uploaded_file($_FILES["foto"]["tmp_name"], $target_file)) {
                $foto = $target_file;
            } else {
                echo "<script>alert('Sorry, there was an error uploading your file.');</script>";
                $uploadOk = 0;
            }
        }
    }
    
    if ($uploadOk == 1) {
        // Get form data
        $id = $_POST['id'];
        $nama = $_POST['nama'];
        $harga = $_POST['harga'];
        $stok = $_POST['stok'];
        $jenis = $_POST['jenis'];
        $bahan = $_POST['bahan'];
        $warna = $_POST['warna'];
        $untuk = $_POST['untuk'];
        $size = $_POST['size'];
        $merk = $_POST['merk'];

        // Create new Baju object
        $newBaju = new Baju($id, $nama, $harga, $stok, $foto, $jenis, $bahan, $warna, $untuk, $size, $merk);
        
        // Add to array
        $_SESSION['bajuList'][] = $newBaju;
        
        echo "<script>alert('Data berhasil ditambahkan!');</script>";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Pet Shop - TP2 DPBO</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        h1, h2 {
            color: #333;
        }
        table {
            border-collapse: collapse;
            width: 100%;
            margin-bottom: 20px;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        form {
            width: 50%;
            margin-bottom: 20px;
        }
        label {
            display: inline-block;
            width: 150px;
            margin-bottom: 8px;
        }
        input {
            padding: 5px;
            margin-bottom: 8px;
            width: 250px;
        }
        input[type="submit"] {
            background-color: #4CAF50;
            color: white;
            cursor: pointer;
            width: 100px;
        }
        .pet-image {
            max-width: 100px;
            max-height: 100px;
            object-fit: cover;
        }
        .placeholder-image {
            width: 100px;
            height: 100px;
            background-color: #ccc;
            display: flex;
            align-items: center;
            justify-content: center;
            color: #666;
        }
    </style>
</head>
<body>
    <h1>Pet Shop - Produk Baju Hewan</h1>
    
    <!-- Display data table -->
    <h2>Data Produk</h2>
    <table>
        <tr>
            <th>ID</th>
            <th>Nama Produk</th>
            <th>Harga</th>
            <th>Stok</th>
            <th>Foto</th>
            <th>Jenis</th>
            <th>Bahan</th>
            <th>Warna</th>
            <th>Untuk</th>
            <th>Size</th>
            <th>Merk</th>
        </tr>
        <?php
        // Display all Baju objects
        foreach ($_SESSION['bajuList'] as $baju) {
            echo "<tr>";
            echo "<td>" . $baju->getId() . "</td>";
            echo "<td>" . $baju->getNama() . "</td>";
            echo "<td>Rp " . number_format($baju->getHarga(), 0, ',', '.') . "</td>";
            echo "<td>" . $baju->getStok() . "</td>";
            
            // Display the image
            $foto = $baju->getFoto();
            if (file_exists($foto)) {
                echo "<td><img class='pet-image' src='" . $foto . "' alt='" . $baju->getNama() . "'></td>";
            } else {
                // Check if it's a placeholder from the server
                echo "<td>";
                if (strpos($foto, 'uploads/') === 0) {
                    echo "<div class='placeholder-image'>No Image</div>";
                } else {
                    // Try to use hardcoded image (for test cases)
                    echo "<img class='pet-image' src='images/" . $foto . "' alt='" . $baju->getNama() . "'>";
                }
                echo "</td>";
            }
            
            echo "<td>" . $baju->getJenis() . "</td>";
            echo "<td>" . $baju->getBahan() . "</td>";
            echo "<td>" . $baju->getWarna() . "</td>";
            echo "<td>" . $baju->getUntuk() . "</td>";
            echo "<td>" . $baju->getSize() . "</td>";
            echo "<td>" . $baju->getMerk() . "</td>";
            echo "</tr>";
        }
        ?>
    </table>
    
    <!-- Add new data form -->
    <h2>Tambah Data Baru</h2>
    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>" enctype="multipart/form-data">
        <div>
            <label for="id">ID:</label>
            <input type="text" id="id" name="id" required>
        </div>
        <div>
            <label for="nama">Nama Produk:</label>
            <input type="text" id="nama" name="nama" required>
        </div>
        <div>
            <label for="harga">Harga:</label>
            <input type="number" id="harga" name="harga" required>
        </div>
        <div>
            <label for="stok">Stok:</label>
            <input type="number" id="stok" name="stok" required>
        </div>
        <div>
            <label for="foto">Foto:</label>
            <input type="file" id="foto" name="foto" accept="image/*">
        </div>
        <div>
            <label for="jenis">Jenis:</label>
            <input type="text" id="jenis" name="jenis" required>
        </div>
        <div>
            <label for="bahan">Bahan:</label>
            <input type="text" id="bahan" name="bahan" required>
        </div>
        <div>
            <label for="warna">Warna:</label>
            <input type="text" id="warna" name="warna" required>
        </div>
        <div>
            <label for="untuk">Untuk (jenis hewan):</label>
            <input type="text" id="untuk" name="untuk" required>
        </div>
        <div>
            <label for="size">Size:</label>
            <input type="text" id="size" name="size" required>
        </div>
        <div>
            <label for="merk">Merk:</label>
            <input type="text" id="merk" name="merk" required>
        </div>
        <div>
            <input type="submit" value="Tambah">
        </div>
    </form>
</body>
</html>