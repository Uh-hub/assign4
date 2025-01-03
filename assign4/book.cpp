#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
    //���� ��� �߰�
    bool operator==(const Book& other) const {
        return title == other.title && author == other.author;
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    //å �������� �˻� �޼���
    void searchByTitle(string title) {
        //books ���� �˻��� å������ �����ϸ� å����� �۰��� ��� 
        int idx = -1;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                idx = i;
                break;
            }
        }
        if(idx != -1){
            cout << "�˻��� ����Դϴ�" << endl;
            idx = find(books.begin(), books.end(), title) - books.begin();
            cout << "- " << books[idx].title << " by " << books[idx].author << endl;
        }
        //�˻��� å�� books ���� �������� �����Ƿ� �������� ������ ���
        else {
            cout << "�˻� ����� �����ϴ�." << endl;
        }
    }
    void searchByAuthor(string author) {
        //books ���� �˻��� ������ �����ϸ� å����� �۰��� ��� 
        int idx = -1;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].author== author) {
                idx = i;
                break;
            }
        }
        if(idx != -1){
            cout << "�˻��� ����Դϴ�" << endl;
            idx = find(books.begin(), books.end(), author) - books.begin();
            cout << "- " << books[idx].title << " by " << books[idx].author << endl;
        }
        //�˻��� �۰��� books ���� �������� �����Ƿ� �������� ������ ���
        else {
            cout << "�˻� ����� �����ϴ�." << endl;
        }
    }

};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �������� �˻�" << endl; //�˻��� å ���
        cout << "4. �۰��� �˻�" << endl; //�˻��� å ���
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: �˻��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            string title;
            cout << "å ���� :";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 4�� ����: �˻��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            string author;
            cout << "�۰� �̸� :";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 5�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
