<?php
// Base class PetShop
class PetShop {
    private $id;
    private $nama_produk;
    private $harga_produk;
    private $stok_produk;
    private $foto_produk;

    // Constructor
    public function __construct($id = "", $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $foto_produk = "") {
        $this->id = $id;
        $this->nama_produk = $nama_produk;
        $this->harga_produk = $harga_produk;
        $this->stok_produk = $stok_produk;
        $this->foto_produk = $foto_produk;
    }

    // Getters
    public function getId() {
        return $this->id;
    }

    public function getNama() {
        return $this->nama_produk;
    }

    public function getHarga() {
        return $this->harga_produk;
    }

    public function getStok() {
        return $this->stok_produk;
    }

    public function getFoto() {
        return $this->foto_produk;
    }

    // Setters
    public function setId($id) {
        $this->id = $id;
    }

    public function setNama($nama_produk) {
        $this->nama_produk = $nama_produk;
    }

    public function setHarga($harga_produk) {
        $this->harga_produk = $harga_produk;
    }

    public function setStok($stok_produk) {
        $this->stok_produk = $stok_produk;
    }
    
    public function setFoto($foto_produk) {
        $this->foto_produk = $foto_produk;
    }
}

// Child class Aksesoris inherits from PetShop
class Aksesoris extends PetShop {
    private $jenis;
    private $bahan;
    private $warna;

    // Constructor
    public function __construct($id = "", $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $foto_produk = "", 
                                $jenis = "", $bahan = "", $warna = "") {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $foto_produk);
        $this->jenis = $jenis;
        $this->bahan = $bahan;
        $this->warna = $warna;
    }

    // Getters
    public function getJenis() {
        return $this->jenis;
    }

    public function getBahan() {
        return $this->bahan;
    }

    public function getWarna() {
        return $this->warna;
    }

    // Setters
    public function setJenis($jenis) {
        $this->jenis = $jenis;
    }

    public function setBahan($bahan) {
        $this->bahan = $bahan;
    }

    public function setWarna($warna) {
        $this->warna = $warna;
    }
}

// Grandchild class Baju inherits from Aksesoris
class Baju extends Aksesoris {
    private $untuk;
    private $size;
    private $merk;

    // Constructor
    public function __construct($id = "", $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $foto_produk = "",
                               $jenis = "", $bahan = "", $warna = "", 
                               $untuk = "", $size = "", $merk = "") {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $foto_produk, $jenis, $bahan, $warna);
        $this->untuk = $untuk;
        $this->size = $size;
        $this->merk = $merk;
    }

    // Getters
    public function getUntuk() {
        return $this->untuk;
    }

    public function getSize() {
        return $this->size;
    }

    public function getMerk() {
        return $this->merk;
    }

    // Setters
    public function setUntuk($untuk) {
        $this->untuk = $untuk;
    }

    public function setSize($size) {
        $this->size = $size;
    }

    public function setMerk($merk) {
        $this->merk = $merk;
    }
}
?>