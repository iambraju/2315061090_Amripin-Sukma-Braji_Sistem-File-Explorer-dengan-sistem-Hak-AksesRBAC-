# 📁 Sistem File Explorer dengan Hak Akses RBAC

![PHP](https://img.shields.io/badge/PHP-Backend-blue)
![MySQL](https://img.shields.io/badge/MySQL-Database-orange)
![RBAC](https://img.shields.io/badge/Security-RBAC-green)
![Status](https://img.shields.io/badge/Status-Academic%20Project-success)

## 📖 Deskripsi

Sistem File Explorer dengan Hak Akses RBAC (Role-Based Access Control) merupakan aplikasi berbasis web yang dirancang untuk mengelola file dan folder secara aman dengan mekanisme pembatasan akses berdasarkan peran (role) pengguna.

Sistem ini memungkinkan pengguna untuk melakukan berbagai operasi manajemen file seperti membuat folder, mengunggah file, mengunduh file, mengubah nama file, dan menghapus file sesuai dengan hak akses yang diberikan. Dengan menerapkan konsep RBAC, setiap pengguna hanya dapat mengakses fitur dan data yang sesuai dengan perannya sehingga keamanan sistem dapat terjaga dengan lebih baik.

Proyek ini dikembangkan sebagai implementasi konsep Struktur Data dan Sistem Informasi dalam pengelolaan file berbasis web.

---

## 🎯 Tujuan Proyek

* Mengimplementasikan konsep struktur data dalam pengelolaan file dan folder.
* Mengembangkan sistem file explorer berbasis web.
* Menerapkan metode keamanan Role-Based Access Control (RBAC).
* Mengelola hak akses pengguna secara terstruktur.
* Memberikan pengalaman manajemen file yang aman dan efisien.

---

## ✨ Fitur Utama

### 🔐 Authentication & Authorization

* Login pengguna
* Session management
* Role-Based Access Control (RBAC)
* Validasi hak akses setiap fitur

### 📁 Manajemen File dan Folder

* Membuat folder baru
* Upload file
* Download file
* Rename file/folder
* Hapus file/folder
* Navigasi direktori

### 👥 Manajemen Pengguna

* Pengelolaan akun pengguna
* Pengaturan role pengguna
* Pembatasan akses berdasarkan role

### 📊 Monitoring Aktivitas

* Pencatatan aktivitas pengguna
* Riwayat perubahan file dan folder

---

## 🏗️ Arsitektur Sistem

```text
User
 │
 ▼
Authentication
 │
 ▼
Role Verification (RBAC)
 │
 ├── Admin
 │     ├── Manage Users
 │     ├── Manage Files
 │     └── Full Access
 │
 └── User
       ├── Upload File
       ├── Download File
       └── Limited Access
```

---

## 🔑 Role Pengguna

### Administrator

Memiliki hak akses penuh terhadap sistem:

* Kelola pengguna
* Kelola role
* Kelola seluruh file dan folder
* Monitoring aktivitas sistem

### User

Memiliki akses terbatas:

* Mengakses file yang diizinkan
* Upload file
* Download file
* Mengelola file sesuai izin yang diberikan

---

## 🛠️ Teknologi yang Digunakan

| Teknologi  | Fungsi                |
| ---------- | --------------------- |
| PHP        | Backend Development   |
| MySQL      | Database Management   |
| HTML5      | Struktur Halaman      |
| CSS3       | Styling Interface     |
| JavaScript | Interaktivitas Sistem |
| Bootstrap  | User Interface        |

---

## 📂 Struktur Direktori

```text
project/
│
├── assets/
│   ├── css/
│   ├── js/
│   └── images/
│
├── uploads/
│
├── config/
│
├── database/
│
├── auth/
│
├── pages/
│
├── controllers/
│
├── models/
│
├── index.php
│
└── README.md
```

---

## 🚀 Cara Instalasi

### 1. Clone Repository

```bash
git clone https://github.com/iambraju/2315061090_Amripin-Sukma-Braji_Sistem-File-Explorer-dengan-sistem-Hak-AksesRBAC-.git
```

### 2. Masuk ke Folder Proyek

```bash
cd 2315061090_Amripin-Sukma-Braji_Sistem-File-Explorer-dengan-sistem-Hak-AksesRBAC-
```

### 3. Import Database

1. Buka phpMyAdmin
2. Buat database baru
3. Import file SQL yang tersedia pada folder database

### 4. Konfigurasi Database

Sesuaikan file konfigurasi database:

```php
$host = "localhost";
$user = "root";
$password = "";
$database = "file_explorer_rbac";
```

### 5. Jalankan Server

Gunakan:

* XAMPP
* Laragon
* WAMP

Kemudian akses:

```text
http://localhost/nama_project
```

---

## 🧪 Pengujian Sistem

Pengujian dilakukan pada beberapa fitur utama:

* Login pengguna
* Validasi hak akses
* Upload file
* Download file
* Rename file
* Delete file
* Manajemen folder
* Pembatasan akses berdasarkan role

---

## 📚 Konsep yang Diimplementasikan

### Struktur Data

* Tree Structure (Hierarki Folder)
* Array/List
* Queue (Opsional pada proses tertentu)
* Hashing untuk autentikasi

### Algoritma

* Traversal direktori
* Pencarian file
* Validasi hak akses
* Session management

### Keamanan Sistem

* Authentication
* Authorization
* Role-Based Access Control (RBAC)
* Session Handling

---

## 👨‍💻 Pengembang

**Amripin Sukma Braji**
NPM: 2315061090
Program Studi Teknik Informatika
Universitas Lampung

---

## 📜 Lisensi

Proyek ini dibuat untuk keperluan akademik dan pembelajaran pada mata kuliah Struktur Data.

---

⭐ Jika repository ini bermanfaat, silakan berikan **Star** pada repository ini.
