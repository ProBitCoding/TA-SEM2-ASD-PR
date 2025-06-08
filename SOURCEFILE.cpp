#include <iostream>
using namespace std;

struct node {
    string nama;
    long nim;
    char kelamin;
    node *next;
    node *prev;
};

    node *head = nullptr, *tail = nullptr;
    int choice;
    string NAMA;
    long NIM;
    char KELAMIN;
    int keluar = 0;

void enqueue(long nim, string nama, char kelamin) {
    node *baru = new node;
    baru->nim = nim;
    baru->nama = nama;
    baru->kelamin = kelamin;
    baru->next = nullptr;
    baru->prev = nullptr;

    if (tail == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "Data berhasil ditambahkan ke antrian.\n";
}


void printAll() {
    if (head == nullptr) {
        cout << "\nData Kosong\n";
        return;
    }

    node *current = head;
    cout << "\nData Mahasiswa :\n";
    while (current != nullptr) {
        cout << "NIM     : " << current->nim << endl;
        cout << "Nama    : " << current->nama << endl;
        cout << "Kelamin : " << current->kelamin << endl;
        cout << "-------------------------\n";
        current = current->next;
    }
}

void dequeue() {
    if (head == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }

    node *hapus = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;

    cout << "Data dengan NIM " << hapus->nim << " dihapus dari depan.\n";
    delete hapus;
}

void update(long nim) {
    node *current = head;
    while (current != nullptr) {
        if (current->nim == nim) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            getline(cin, current->nama);

            cout << "Masukkan jenis kelamin baru: ";
            cin >> current->kelamin;

            cout << "Data berhasil diperbarui.\n";
            return;
        }
        current = current->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void deletebyNIM(long nim) {
    node *current = head;

    while (current != nullptr) {
        if (current->nim == nim) {
            if (current == head) {
                head = current->next;
                if (head) head->prev = nullptr;
                else tail = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            cout << "Data dengan NIM " << nim << " berhasil dihapus.\n";
            delete current;
            return;
        }
        current = current->next;
    }

    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}

void search(long nim) {
    node *current = head;
    while (current != nullptr) {
        if (current->nim == nim) {
            
            cout << "Menampilkan Mahasiswa Dengan NIM: "<< current->nim<<endl;
            cout << " Nama Mahasiswa: "<< current->nama<<endl;
            cout << "Jenis kelamin Mahasiswa: " << current->kelamin<<endl;
            return;
        }
        current = current->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
}


void menu() {
    cout << "\n1. Memasukkan data \n2. Hapus data terdepan (Dequeue) \n3. Update data \n4. Hapus data Berdasarkan NIM \n5. Print data \n6. Search Data Berdasarkan NIM \n7.Exit ";
    cout << "\nMasukkan operasi yang akan dilakukan: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\nMasukkan NIM Anda: ";
            cin >> NIM;
            cin.ignore();
            cout << "Masukkan Nama Anda: ";
            getline(cin, NAMA);
            cout << "Masukkan Kelamin Anda (M/F): ";
            cin >> KELAMIN;
            enqueue(NIM, NAMA, KELAMIN);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            cout << "Masukkan NIM yang ingin diperbarui: ";
            cin >> NIM;
            update(NIM);
            break;
        case 4:
            cout << "Masukkan NIM yang ingin dihapus: ";
            cin >> NIM;
            deletebyNIM(NIM);
            break;
        case 5:
            printAll();
            break;
         case 6:
            cout<<"Masukkan NIM yang ingin Dicari: ";
            cin >> NIM;
            search(NIM);
            break;
        case 7:
            cout << "Program Shutdown...";
            keluar = 1;
            break;
        default:
            cout << "Pilihan tidak valid. Silahkan coba lagi\n";
    }
}


int main(){
    do{menu();} while (keluar==0);

    return 0;
}
