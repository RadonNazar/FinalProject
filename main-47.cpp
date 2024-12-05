//Завдання 1
/*#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Базовий клас для товарів
class Item {
protected:
    std::string name;
    std::string category;
    double price;
    int quantity;

public:
    Item(std::string n, std::string c, double p, int q)
        : name(n), category(c), price(p), quantity(q) {}

    virtual void display() const {
        std::cout << "Name: " << name << ", Category: " << category
                  << ", Price: " << price << ", Quantity: " << quantity << std::endl;
    }

    std::string getName() const {
        return name;
    }

    std::string getCategory() const {
        return category;
    }

    double getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    virtual ~Item() = default;
};

// Клас для продуктів (наслідує від Item)
class Product : public Item {
private:
    std::string expirationDate;

public:
    Product(std::string n, std::string c, double p, int q, std::string expDate)
        : Item(n, c, p, q), expirationDate(expDate) {}

    void display() const override {
        std::cout << "Product - ";
        Item::display();
        std::cout << "Expiration Date: " << expirationDate << std::endl;
    }
};

// Клас для побутових товарів (наслідує від Item)
class HouseholdItem : public Item {
public:
    HouseholdItem(std::string n, std::string c, double p, int q)
        : Item(n, c, p, q) {}

    void display() const override {
        std::cout << "Household Item - ";
        Item::display();
    }
};

// Клас для текстильних товарів (наслідує від Item)
class TextileItem : public Item {
public:
    TextileItem(std::string n, std::string c, double p, int q)
        : Item(n, c, p, q) {}

    void display() const override {
        std::cout << "Textile Item - ";
        Item::display();
    }
};

class Supermarket {
private:
    std::vector<Item*> items;  // Вектор для зберігання товарів

public:
    ~Supermarket() {
        for (auto item : items) {
            delete item;
        }
    }

    // Додавання товару до бази
    void addItem(Item* item) {
        for (auto& i : items) {
            if (i->getName() == item->getName()) {
                std::cout << "Item already exists in the base.\n";
                return;
            }
        }
        items.push_back(item);
        std::cout << "Item added to the base.\n";
    }

    // Перегляд всіх товарів
    void displayItems() const {
        std::cout << "Items in Supermarket:\n";
        for (const auto& item : items) {
            item->display();
        }
    }

    // Пошук товару за назвою
    Item* searchItem(const std::string& name) {
        for (auto& item : items) {
            if (item->getName() == name) {
                return item;
            }
        }
        std::cout << "Item not found.\n";
        return nullptr;
    }

    // Видалення товару
    void removeItem(const std::string& name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == name) {
                delete *it;
                items.erase(it);
                std::cout << "Item removed.\n";
                return;
            }
        }
        std::cout << "Item not found to remove.\n";
    }

    // Збереження товарів у файл
    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error opening file for saving.\n";
            return;
        }
        for (const auto& item : items) {
            file << item->getName() << "," << item->getCategory() << ","
                 << item->getPrice() << "," << item->getQuantity() << "\n";
        }
        std::cout << "Data saved to file.\n";
    }

    // Завантаження товарів з файлу
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file for loading.\n";
            return;
        }
        std::string line;
        while (std::getline(file, line)) {
            // Припускаємо, що дані у файлі в такому форматі: Назва,Категорія,Ціна,Кількість
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            std::string name = line.substr(0, pos1);
            std::string category = line.substr(pos1 + 1, pos2 - pos1 - 1);
            double price = std::stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
            int quantity = std::stoi(line.substr(pos3 + 1));

            if (category == "Household") {
                items.push_back(new HouseholdItem(name, category, price, quantity));
            } else if (category == "Textile") {
                items.push_back(new TextileItem(name, category, price, quantity));
            } else {
                items.push_back(new Product(name, category, price, quantity, "N/A"));
            }
        }
        std::cout << "Data loaded from file.\n";
    }
};

int main() {
    Supermarket supermarket;

    // Додавання товарів до супермаркету
    supermarket.addItem(new Product("Milk", "Dairy", 1.5, 100, "2024-12-01"));
    supermarket.addItem(new HouseholdItem("Detergent", "Household", 3.0, 50));
    supermarket.addItem(new TextileItem("Shirt", "Textile", 10.0, 200));

    // Перегляд усіх товарів
    supermarket.displayItems();

    // Пошук товару
    Item* item = supermarket.searchItem("Milk");
    if (item) item->display();

    // Видалення товару
    supermarket.removeItem("Milk");
    supermarket.displayItems();

    // Збереження товарів у файл
    supermarket.saveToFile("items.txt");

    // Завантаження товарів з файлу
    supermarket.loadFromFile("items.txt");
    supermarket.displayItems();

    return 0;
}*/

//Завдання 2
/*#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Employee {
protected:
    string name;
    string position;
    string id;
    string hireDate;
    int experience;

public:
    // Конструктор
    Employee(const string& n, const string& h, const string& p, const string& i, int exp)
        : name(n), hireDate(h), position(p), id(i), experience(exp) {}

    // Геттери та сеттери
    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    string getPosition() const { return position; }
    void setPosition(const string& p) { position = p; }

    string getId() const { return id; }
    void setId(const string& i) { id = i; }

    string getHireDate() const { return hireDate; }
    void setHireDate(const string& h) { hireDate = h; }

    int getExperience() const { return experience; }
    void setExperience(int exp) { experience = exp; }

    // Чиста віртуальна функція
    virtual double calculateSalary() = 0;
    
    virtual ~Employee() = default;
};

class Manager : public Employee {
public:
    Manager(const string& n, const string& h, const string& p, const string& i, int exp)
        : Employee(n, h, p, i, exp) {}

    double calculateSalary() override {
        return 5000 + experience * 200;  // Приклад нарахування зарплати для менеджера
    }
};

class EmployeeDatabase {
private:
    vector<Employee*> employees;

public:
    // Додавання співробітника
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    // Пошук співробітника
    void searchEmployee(const string& searchTerm) {
        for (const auto& employee : employees) {
            if (employee->getName().find(searchTerm) != string::npos || 
                employee->getPosition().find(searchTerm) != string::npos) {
                cout << "Found: " << employee->getName() << ", " << employee->getPosition() << endl;
            }
        }
    }

    // Збереження даних в файл
    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        for (const auto& employee : employees) {
            file << employee->getName() << ","
                 << employee->getHireDate() << ","
                 << employee->getPosition() << ","
                 << employee->getId() << ","
                 << employee->getExperience() << endl;
        }
        file.close();
    }

    // Завантаження даних з файлу
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string name, hireDate, position, id;
        int experience;
        while (getline(file, name, ',') &&
               getline(file, hireDate, ',') &&
               getline(file, position, ',') &&
               getline(file, id, ',') &&
               file >> experience) {
            file.ignore();  // ігноруємо символ нового рядка
            addEmployee(new Manager(name, hireDate, position, id, experience));
        }
        file.close();
    }

    // Деструктор для очищення пам'яті
    ~EmployeeDatabase() {
        for (auto& employee : employees) {
            delete employee;
        }
    }
};

int main() {
    EmployeeDatabase db;

    // Додавання кількох співробітників
    db.addEmployee(new Manager("John Doe", "2023-01-01", "Manager", "M001", 5));
    db.addEmployee(new Manager("Jane Smith", "2022-05-15", "Manager", "M002", 3));

    // Пошук співробітників
    db.searchEmployee("Manager");

    // Збереження в файл
    db.saveToFile("employees.txt");

    // Завантаження з файлу
    db.loadFromFile("employees.txt");

    return 0;
}*/

//Завдання 3
/*#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;

class Subject {
public:
    string name;

    Subject(const string& name) : name(name) {}
};

class Student {
public:
    string name;
    string groupName;
    map<string, vector<int>> grades;

    Student(const string& name, const string& groupName) : name(name), groupName(groupName) {}

    void addGrade(const string& subject, int grade) {
        grades[subject].push_back(grade);
    }
};

class Teacher {
public:
    string name;
    vector<string> subjects;

    Teacher(const string& name) : name(name) {}

    void addSubject(const string& subject) {
        subjects.push_back(subject);
    }
};

class Group {
public:
    string name;
    vector<shared_ptr<Student>> students;

    Group(const string& name) : name(name) {}
};

class Deanery {
private:
    vector<shared_ptr<Group>> groups;
    vector<shared_ptr<Teacher>> teachers;

public:
    void addStudent(const string& studentName, const string& groupName) {
        auto group = findGroup(groupName);
        if (!group) {
            group = make_shared<Group>(groupName);
            groups.push_back(group);
        }
        group->students.push_back(make_shared<Student>(studentName, groupName));
    }

    void addTeacher(const string& teacherName) {
        teachers.push_back(make_shared<Teacher>(teacherName));
    }

    void addSubjectToTeacher(const string& teacherName, const string& subjectName) {
        auto teacher = findTeacher(teacherName);
        if (teacher) {
            teacher->addSubject(subjectName);
        }
    }

    shared_ptr<Group> findGroup(const string& groupName) {
        for (auto& group : groups) {
            if (group->name == groupName) {
                return group;
            }
        }
        return nullptr;
    }

    shared_ptr<Teacher> findTeacher(const string& teacherName) {
        for (auto& teacher : teachers) {
            if (teacher->name == teacherName) {
                return teacher;
            }
        }
        return nullptr;
    }

    void saveToFile() {
        ofstream file("deanery_data.txt");
        if (file.is_open()) {
            for (const auto& group : groups) {
                for (const auto& student : group->students) {
                    file << "Student," << student->name << "," << group->name << endl;
                    for (const auto& [subject, grades] : student->grades) {
                        file << "Grade," << student->name << "," << subject;
                        for (int grade : grades) {
                            file << "," << grade;
                        }
                        file << endl;
                    }
                }
            }
            for (const auto& teacher : teachers) {
                file << "Teacher," << teacher->name << endl;
                for (const string& subject : teacher->subjects) {
                    file << "Subject," << teacher->name << "," << subject << endl;
                }
            }
            file.close();
        }
    }

    void loadFromFile() {
        ifstream file("deanery_data.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string type, name, groupOrSubject;
                getline(ss, type, ',');
                if (type == "Student") {
                    getline(ss, name, ',');
                    getline(ss, groupOrSubject, ',');
                    addStudent(name, groupOrSubject);
                } else if (type == "Teacher") {
                    getline(ss, name, ',');
                    addTeacher(name);
                } else if (type == "Subject") {
                    getline(ss, name, ',');
                    getline(ss, groupOrSubject, ',');
                    addSubjectToTeacher(name, groupOrSubject);
                } else if (type == "Grade") {
                    getline(ss, name, ',');
                    getline(ss, groupOrSubject, ',');
                    auto group = findGroup(groupOrSubject);
                    if (group) {
                        for (auto& student : group->students) {
                            if (student->name == name) {
                                int grade;
                                while (ss >> grade) {
                                    student->addGrade(groupOrSubject, grade);
                                    if (ss.peek() == ',') ss.ignore();
                                }
                            }
                        }
                    }
                }
            }
            file.close();
        }
    }
};

int main() {
    Deanery deanery;

    // Додавання студентів
    deanery.addStudent("Alice Brown", "Group 1");
    deanery.addStudent("Bob Green", "Group 2");

    // Додавання викладачів та предметів
    deanery.addTeacher("Dr. John Smith");
    deanery.addSubjectToTeacher("Dr. John Smith", "Mathematics");

    // Виставлення оцінок
    for (auto& student : deanery.findGroup("Group 1")->students) {
        student->addGrade("Mathematics", 95); // Оцінка з математики
    }

    for (auto& student : deanery.findGroup("Group 2")->students) {
        student->addGrade("Mathematics", 88); // Оцінка з математики
    }

    // Збереження даних у файл
    deanery.saveToFile();

    // Завантаження даних з файлу
    deanery.loadFromFile();

    return 0;
}*/

//Завдання 4
/*#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

// Базовий клас для гарячих напоїв
class HotDrink {
protected:
    string name;
    double price;

public:
    HotDrink(const string& drinkName, double drinkPrice) : name(drinkName), price(drinkPrice) {}

    virtual ~HotDrink() {}

    string getName() const { return name; }

    double getPrice() const { return price; }

    void setPrice(double newPrice) { price = newPrice; }

    virtual map<string, int> getRequiredIngredients() const = 0;
};

// Клас для кави
class Coffee : public HotDrink {
public:
    Coffee() : HotDrink("coffee", 20.0) {}

    map<string, int> getRequiredIngredients() const override {
        return {{"water", 200}, {"coffee", 50}, {"sugar", 10}};
    }
};

// Клас для чаю
class Tea : public HotDrink {
public:
    Tea() : HotDrink("tea", 10.0) {}

    map<string, int> getRequiredIngredients() const override {
        return {{"water", 200}, {"tea", 50}, {"sugar", 10}};
    }
};

// Клас для капучіно
class Cappuccino : public HotDrink {
public:
    Cappuccino() : HotDrink("cappuccino", 30.0) {}

    map<string, int> getRequiredIngredients() const override {
        return {{"water", 200}, {"coffee", 50}, {"milk", 50}};
    }
};

// Клас Автомату
class HotDrinkAutomat {
private:
    map<string, int> ingredients = {
        {"water", 1000},
        {"coffee", 500},
        {"tea", 500},
        {"sugar", 300},
        {"milk", 300}
    };
    map<string, HotDrink*> drinks;
    double cash = 0.0;

    // Збереження даних у файл
    void saveData() const {
        ofstream file("automat_data.txt");
        if (file.is_open()) {
            file << cash << endl;
            for (const auto& [ingredient, amount] : ingredients) {
                file << ingredient << " " << amount << endl;
            }
            for (const auto& [name, drink] : drinks) {
                file << name << " " << drink->getPrice() << endl;
            }
            file.close();
        }
    }

    // Завантаження даних із файлу
    void loadData() {
        ifstream file("automat_data.txt");
        if (file.is_open()) {
            file >> cash;
            for (auto& [ingredient, amount] : ingredients) {
                string key;
                int value;
                file >> key >> value;
                if (key == ingredient) {
                    amount = value;
                }
            }
            for (auto& [name, drink] : drinks) {
                string key;
                double value;
                file >> key >> value;
                if (key == name) {
                    drink->setPrice(value);
                }
            }
            file.close();
        }
    }

    // Перевірка наявності інгредієнтів
    bool checkIngredients(const map<string, int>& required) const {
        for (const auto& [ingredient, amount] : required) {
            if (ingredients.at(ingredient) < amount) {
                return false;
            }
        }
        return true;
    }

    // Витрачання інгредієнтів
    void useIngredients(const map<string, int>& required) {
        for (const auto& [ingredient, amount] : required) {
            ingredients[ingredient] -= amount;
        }
    }

public:
    HotDrinkAutomat() {
        drinks["coffee"] = new Coffee();
        drinks["tea"] = new Tea();
        drinks["cappuccino"] = new Cappuccino();
        loadData();
    }

    ~HotDrinkAutomat() {
        for (auto& [name, drink] : drinks) {
            delete drink;
        }
        saveData();
    }

    // Режим адміна
    void adminMenu() {
        while (true) {
            cout << "\n--- Меню адміна ---" << endl;
            cout << "1. Завантаження автомату" << endl;
            cout << "2. Вивід статистики" << endl;
            cout << "3. Зміна цін" << endl;
            cout << "4. Вилучення кешу" << endl;
            cout << "0. Вихід" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    for (auto& [ingredient, amount] : ingredients) {
                        int addAmount;
                        cout << ingredient << " (залишок: " << amount << "): ";
                        cin >> addAmount;
                        amount += addAmount;
                    }
                    break;

                case 2:
                    cout << "\nСтатистика:" << endl;
                    for (const auto& [ingredient, amount] : ingredients) {
                        cout << ingredient << ": " << amount << endl;
                    }
                    cout << "Готівка: " << cash << " грн" << endl;
                    break;

                case 3:
                    for (auto& [name, drink] : drinks) {
                        double newPrice;
                        cout << name << " (поточна ціна: " << drink->getPrice() << " грн): ";
                        cin >> newPrice;
                        drink->setPrice(newPrice);
                    }
                    break;

                case 4:
                    cout << "Вилучено готівку: " << cash << " грн" << endl;
                    cash = 0.0;
                    break;

                case 0:
                    return;

                default:
                    cout << "Невірний вибір!" << endl;
            }
        }
    }

    // Режим користувача
    void userMenu() {
        while (true) {
            cout << "\n--- Меню користувача ---" << endl;
            cout << "Доступні напої:" << endl;
            for (const auto& [name, drink] : drinks) {
                cout << name << ": " << drink->getPrice() << " грн" << endl;
            }
            cout << "0. Вихід" << endl;

            string choice;
            cout << "Оберіть напій: ";
            cin >> choice;

            if (choice == "0") return;

            if (drinks.find(choice) == drinks.end()) {
                cout << "Напій недоступний!" << endl;
                continue;
            }

            HotDrink* selectedDrink = drinks[choice];
            if (!checkIngredients(selectedDrink->getRequiredIngredients())) {
                cout << "Недостатньо інгредієнтів для приготування " << choice << "!" << endl;
                continue;
            }

            double payment;
            cout << "Вартість: " << selectedDrink->getPrice() << " грн. Введіть суму: ";
            cin >> payment;

            if (payment < selectedDrink->getPrice()) {
                cout << "Недостатньо коштів!" << endl;
                continue;
            }

            useIngredients(selectedDrink->getRequiredIngredients());
            cash += selectedDrink->getPrice();
            cout << "Ваш " << choice << " готовий!" << endl;

            if (payment > selectedDrink->getPrice()) {
                cout << "Ваша здача: " << payment - selectedDrink->getPrice() << " грн" << endl;
            }
        }
    }
};

// Головна функція
int main() {
    HotDrinkAutomat automat;

    while (true) {
        cout << "\n--- Автомат гарячих напоїв ---" << endl;
        cout << "1. Режим адміна" << endl;
        cout << "2. Режим користувача" << endl;
        cout << "0. Вихід" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                automat.adminMenu();
                break;

            case 2:
                automat.userMenu();
                break;

            case 0:
                return 0;

            default:
                cout << "Невірний вибір!" << endl;
        }
    }
}*/

//Завдання 5
/*#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Клас продукту (інгредієнта)
class Product {
public:
    string name;
    double price;

    Product(string name, double price) : name(name), price(price) {}
};

// Клас піци
class Pizza {
public:
    string name;
    vector<Product> ingredients;

    Pizza(string name) : name(name) {}

    void addIngredient(Product product) {
        ingredients.push_back(product);
    }

    double getTotalPrice() {
        double total = 0;
        for (auto& ingredient : ingredients) {
            total += ingredient.price;
        }
        return total;
    }

    void printPizza() {
        cout << "Піца: " << name << endl;
        cout << "Інгредієнти:" << endl;
        for (auto& ingredient : ingredients) {
            cout << "- " << ingredient.name << " ($" << ingredient.price << ")" << endl;
        }
        cout << "Загальна ціна: $" << getTotalPrice() << endl;
    }
};

// Клас піцерії
class Pizzeria {
private:
    vector<Product> products; // Список продуктів
    vector<Pizza> pizzas; // Список піц
    string filename = "pizzeria_data.txt"; // Файл для збереження

    void loadFromFile() {
        ifstream file(filename);
        if (!file) {
            return; // Якщо файл не існує, нічого не завантажуємо
        }
        int numProducts, numPizzas;
        file >> numProducts;
        products.clear();
        for (int i = 0; i < numProducts; ++i) {
            string name;
            double price;
            file >> name >> price;
            products.push_back(Product(name, price));
        }

        file >> numPizzas;
        pizzas.clear();
        for (int i = 0; i < numPizzas; ++i) {
            string name;
            file >> name;
            Pizza pizza(name);
            int numIngredients;
            file >> numIngredients;
            for (int j = 0; j < numIngredients; ++j) {
                string ingredientName;
                file >> ingredientName;
                for (auto& product : products) {
                    if (product.name == ingredientName) {
                        pizza.addIngredient(product);
                        break;
                    }
                }
            }
            pizzas.push_back(pizza);
        }
    }

    void saveToFile() {
        ofstream file(filename);
        file << products.size() << endl;
        for (auto& product : products) {
            file << product.name << " " << product.price << endl;
        }
        file << pizzas.size() << endl;
        for (auto& pizza : pizzas) {
            file << pizza.name << endl;
            file << pizza.ingredients.size() << endl;
            for (auto& ingredient : pizza.ingredients) {
                file << ingredient.name << endl;
            }
        }
    }

    void adminMenu() {
        while (true) {
            cout << "\n1. Додати продукт\n2. Додати піцу\n3. Змінити ціни на продукти\n4. Переглянути статистику\n5. Вийти" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    string name;
                    double price;
                    cout << "Введіть назву продукту: ";
                    cin >> name;
                    cout << "Введіть ціну: ";
                    cin >> price;
                    products.push_back(Product(name, price));
                    break;
                }
                case 2: {
                    string pizzaName;
                    cout << "Введіть назву піци: ";
                    cin >> pizzaName;
                    Pizza pizza(pizzaName);
                    cout << "Введіть кількість інгредієнтів: ";
                    int numIngredients;
                    cin >> numIngredients;
                    for (int i = 0; i < numIngredients; ++i) {
                        string ingredientName;
                        cout << "Введіть назву інгредієнта: ";
                        cin >> ingredientName;
                        for (auto& product : products) {
                            if (product.name == ingredientName) {
                                pizza.addIngredient(product);
                                break;
                            }
                        }
                    }
                    pizzas.push_back(pizza);
                    break;
                }
                case 3: {
                    string productName;
                    double newPrice;
                    cout << "Введіть назву продукту для зміни ціни: ";
                    cin >> productName;
                    cout << "Введіть нову ціну: ";
                    cin >> newPrice;
                    for (auto& product : products) {
                        if (product.name == productName) {
                            product.price = newPrice;
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    cout << "\nПродукти в базі:" << endl;
                    for (auto& product : products) {
                        cout << product.name << " ($" << product.price << ")" << endl;
                    }
                    cout << "\nПіци в базі:" << endl;
                    for (auto& pizza : pizzas) {
                        pizza.printPizza();
                    }
                    break;
                }
                case 5:
                    saveToFile();
                    return;
            }
        }
    }

    void userMenu() {
        while (true) {
            cout << "\n1. Переглянути піци\n2. Замовити піцу\n3. Вийти" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1: {
                    for (auto& pizza : pizzas) {
                        pizza.printPizza();
                    }
                    break;
                }
                case 2: {
                    string pizzaName;
                    cout << "Введіть назву піци, яку хочете замовити: ";
                    cin >> pizzaName;
                    bool found = false;
                    for (auto& pizza : pizzas) {
                        if (pizza.name == pizzaName) {
                            pizza.printPizza();
                            double totalPrice = pizza.getTotalPrice();
                            cout << "Ціна замовлення: $" << totalPrice << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Піцу не знайдено!" << endl;
                    }
                    break;
                }
                case 3:
                    return;
            }
        }
    }

public:
    Pizzeria() {
        loadFromFile();
    }

    void run() {
        cout << "1. Адмін\n2. Користувач" << endl;
        int role;
        cin >> role;
        if (role == 1) {
            adminMenu();
        } else if (role == 2) {
            userMenu();
        } else {
            cout << "Невірний вибір!" << endl;
        }
    }
};

int main() {
    Pizzeria pizzeria;
    pizzeria.run();
    return 0;
}*/

//Завдання 6
/*#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Клас Fuel для пального
class Fuel {
private:
    string type;
    double quantity;
    double pricePerLiter;

public:
    Fuel(const string& type, double quantity, double pricePerLiter)
        : type(type), quantity(quantity), pricePerLiter(pricePerLiter) {}

    string getType() const { return type; }
    double getQuantity() const { return quantity; }
    double getPricePerLiter() const { return pricePerLiter; }

    void setQuantity(double newQuantity) { quantity = newQuantity; }
    void setPrice(double newPrice) { pricePerLiter = newPrice; }
};

// Клас CoffeeMachine для кавового автомата
class CoffeeMachine {
private:
    double coffeePrice;
    double coffeeQuantity;

public:
    CoffeeMachine(double price, double quantity)
        : coffeePrice(price), coffeeQuantity(quantity) {}

    double getCoffeePrice() const { return coffeePrice; }
    double getCoffeeQuantity() const { return coffeeQuantity; }

    void setCoffeePrice(double newPrice) { coffeePrice = newPrice; }
    void loadCoffee(double quantity) { coffeeQuantity += quantity; }
};

// Клас FuelStation для автозаправки
class FuelStation {
private:
    vector<Fuel> fuels;
    CoffeeMachine coffeeMachine;
    double cashFromFuel;
    double cashFromCoffee;

public:
    FuelStation()
        : coffeeMachine(20.0, 100.0), cashFromFuel(0), cashFromCoffee(0) {}

    // Геттер для пального
    const vector<Fuel>& getFuels() const { return fuels; }

    // Геттер для кавового автомата
    const CoffeeMachine& getCoffeeMachine() const { return coffeeMachine; }
    CoffeeMachine& getCoffeeMachine() { return coffeeMachine; }

    // Геттери для грошових сум
    double getCashFromFuel() const { return cashFromFuel; }
    double getCashFromCoffee() const { return cashFromCoffee; }

    // Поповнення заправки пальним
    void refillFuel(const string& type, double quantity, double price) {
        // Перевірка, чи такий тип пального вже є
        for (auto& fuel : fuels) {
            if (fuel.getType() == type) {
                fuel.setQuantity(fuel.getQuantity() + quantity);
                fuel.setPrice(price);
                return;
            }
        }
        // Якщо немає, додаємо новий тип пального
        fuels.push_back(Fuel(type, quantity, price));
    }

    // Метод для вилучення коштів
    void withdrawCash(double amount) {
        // Спочатку намагаємось вилучити з виручки від пального
        if (cashFromFuel >= amount) {
            cashFromFuel -= amount;
            cout << "Вилучено " << amount << " грн з виручки від пального.\n";
            return;
        }

        // Якщо не вистачає коштів від пального, перевіряємо виручку від кави
        double totalCash = cashFromFuel + cashFromCoffee;
        if (totalCash >= amount) {
            // Спочатку вичерпуємо кошти від пального
            amount -= cashFromFuel;
            cashFromFuel = 0;
            
            // Решту вилучаємо з виручки від кави
            cashFromCoffee -= amount;
            cout << "Вилучено " << amount << " грн (частково з пального, частково з кави).\n";
        } else {
            cout << "Недостатньо коштів для вилучення.\n";
        }
    }

    // Заправка авто пальним
    void fuelCar(const string& type, double liters, double& amount) {
        for (auto& fuel : fuels) {
            if (fuel.getType() == type && fuel.getQuantity() >= liters) {
                double totalCost = liters * fuel.getPricePerLiter();
                amount -= totalCost;
                fuel.setQuantity(fuel.getQuantity() - liters);
                cashFromFuel += totalCost;
                cout << "Заправка виконана. Загальна вартість: " << totalCost << " грн.\n";
                return;
            }
        }
        cout << "Недостатньо пального або невірний тип пального.\n";
    }

    // Замовлення кави
    void orderCoffee(double& amount) {
        if (coffeeMachine.getCoffeeQuantity() > 0) {
            double coffeeCost = coffeeMachine.getCoffeePrice();
            amount -= coffeeCost;
            cashFromCoffee += coffeeCost;
            coffeeMachine.loadCoffee(-1); // Один стакан кави
            cout << "Кава замовлена. Загальна вартість: " << coffeeCost << " грн.\n";
        } else {
            cout << "Кава не доступна.\n";
        }
    }

    // Виведення статистики
    void displayStats() const {
        cout << "Статистика:\n";
        cout << "Пальне:\n";
        for (const auto& fuel : fuels) {
            cout << "Тип: " << fuel.getType() << ", Кількість: " << fuel.getQuantity() << " л, Ціна: " << fuel.getPricePerLiter() << " грн/л\n";
        }
        cout << "Кава:\n";
        cout << "Ціна: " << coffeeMachine.getCoffeePrice() << " грн, Кількість: " << coffeeMachine.getCoffeeQuantity() << " порцій\n";
        cout << "Загальні кошти від пального: " << cashFromFuel << " грн\n";
        cout << "Загальні кошти від кави: " << cashFromCoffee << " грн\n";
    }
};

// Збереження даних в файл
void saveDataToFile(const FuelStation& station) {
    ofstream outFile("station_data.txt");

    // Збереження інформації про пального
    for (const auto& fuel : station.getFuels()) {
        outFile << fuel.getType() << "," << fuel.getQuantity() << "," << fuel.getPricePerLiter() << "\n";
    }

    // Збереження інформації про кавовий автомат
    outFile << station.getCoffeeMachine().getCoffeePrice() << "," << station.getCoffeeMachine().getCoffeeQuantity() << "\n";
    outFile.close();
}

// Завантаження даних з файлу
void loadDataFromFile(FuelStation& station) {
    ifstream inFile("station_data.txt");
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos2 != string::npos) {
            string type = line.substr(0, pos1);
            double quantity = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
            double price = stod(line.substr(pos2 + 1));
            station.refillFuel(type, quantity, price);
        } else {
            double price = stod(line.substr(0, pos1));
            double quantity = stod(line.substr(pos1 + 1));
            station.getCoffeeMachine().loadCoffee(quantity);
        }
    }
    inFile.close();
}

// Основна функція
int main() {
    FuelStation station;
    loadDataFromFile(station);

    double amount = 500.0; // Початкова сума грошей у користувача

    int mode;
    cout << "Виберіть режим:\n1 - Адмін\n2 - Користувач\n";
    cin >> mode;

    if (mode == 1) {
        // Адмінський режим
        int adminOption;
        do {
            cout << "1 - Поповнити заправку\n2 - Переглянути статистику\n3 - Вилучити кошти\n4 - Вийти\n";
            cin >> adminOption;

            switch (adminOption) {
            case 1: {
                string type;
                double quantity, price;
                cout << "Введіть тип пального: ";
                cin >> type;
                cout << "Введіть кількість пального: ";
                cin >> quantity;
                cout << "Введіть ціну за літр: ";
                cin >> price;
                station.refillFuel(type, quantity, price);
                break;
            }
            case 2:
                station.displayStats();
                break;
            case 3: {
                double cash;
                cout << "Введіть суму для вилучення: ";
                cin >> cash;
                station.withdrawCash(cash);
                break;
            }
            case 4:
                cout << "Вихід з адмінського режиму.\n";
                break;
            default:
                cout << "Невірний вибір.\n";
                break;
            }
        } while (adminOption != 4);
    } else {
        // Користувацький режим
        int userOption;
        do {
            cout << "1 - Заправити машину\n2 - Замовити каву\n3 - Переглянути статистику\n4 - Вийти\n";
            cin >> userOption;

            switch (userOption) {
            case 1: {
                string type;
                double liters;
                cout << "Введіть тип пального: ";
                cin >> type;
                cout << "Введіть кількість літрів: ";
                cin >> liters;
                station.fuelCar(type, liters, amount);
                break;
            }
            case 2:
                station.orderCoffee(amount);
                break;
            case 3:
                station.displayStats();
                break;
            case 4:
                cout << "Вихід з користувацького режиму.\n";
                break;
            default:
                cout << "Невірний вибір.\n";
                break;
            }
        } while (userOption != 4);
    }

    saveDataToFile(station);
    return 0;
}*/

//Завдання 7
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Service {
protected:
    std::string type;
    double price;
public:
    Service(const std::string& type, double price) : type(type), price(price) {}
    virtual ~Service() = default;
    virtual void display() const = 0;
    std::string getType() const { return type; }
    double getPrice() const { return price; }
    virtual void editService(const std::string& newType, double newPrice) {
        type = newType;
        price = newPrice;
    }
};

class Haircut : public Service {
public:
    Haircut(const std::string& type, double price) : Service(type, price) {}
    void display() const override {
        std::cout << "Haircut - Type: " << type << ", Price: " << price << std::endl;
    }
};

class Coloring : public Service {
public:
    Coloring(const std::string& type, double price) : Service(type, price) {}
    void display() const override {
        std::cout << "Coloring - Type: " << type << ", Price: " << price << std::endl;
    }
};

class Manicure : public Service {
    std::string additional;
public:
    Manicure(const std::string& type, double price, const std::string& additional)
        : Service(type, price), additional(additional) {}
    void display() const override {
        std::cout << "Manicure - Type: " << type << ", Price: " << price << ", Additional: " << additional << std::endl;
    }
    void editService(const std::string& newType, double newPrice, const std::string& newAdditional) {
        Service::editService(newType, newPrice);
        additional = newAdditional;
    }
};

class CosmeticProcedure : public Service {
    double duration;
public:
    CosmeticProcedure(const std::string& type, double duration, double price)
        : Service(type, price), duration(duration) {}
    void display() const override {
        std::cout << "Cosmetic Procedure - Type: " << type << ", Duration: " << duration << "h, Price: " << price << std::endl;
    }
    void editService(const std::string& newType, double newDuration, double newPrice) {
        Service::editService(newType, newPrice);
        duration = newDuration;
    }
};

class Client {
    std::string name;
    std::string contactInfo;
public:
    Client(const std::string& name, const std::string& contactInfo) : name(name), contactInfo(contactInfo) {}
    void display() const {
        std::cout << "Client - Name: " << name << ", Contact Info: " << contactInfo << std::endl;
    }
    std::string getName() const { return name; }
};

class Master {
    std::string name;
    std::string specialty;
public:
    Master(const std::string& name, const std::string& specialty) : name(name), specialty(specialty) {}
    void display() const {
        std::cout << "Master - Name: " << name << ", Specialty: " << specialty << std::endl;
    }
    std::string getName() const { return name; }
};

class Product {
    std::string name;
    double price;
public:
    Product(const std::string& name, double price) : name(name), price(price) {}
    void display() const {
        std::cout << "Product - Name: " << name << ", Price: " << price << std::endl;
    }
    std::string getName() const { return name; }
};

class Salon {
    std::vector<Service*> services;
    std::vector<Client> clients;
    std::vector<Master> masters;
    std::vector<Product> products;

    void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& service : services) {
                file << service->getType() << "," << service->getPrice() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving\n";
        }
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string type;
            double price;
            while (file >> type >> price) {
                if (type == "Haircut") {
                    services.push_back(new Haircut(type, price));
                } else if (type == "Coloring") {
                    services.push_back(new Coloring(type, price));
                } else if (type == "Manicure") {
                    std::string additional;
                    file >> additional;
                    services.push_back(new Manicure(type, price, additional));
                } else if (type == "CosmeticProcedure") {
                    double duration;
                    file >> duration;
                    services.push_back(new CosmeticProcedure(type, duration, price));
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading\n";
        }
    }

public:
    ~Salon() {
        for(auto service : services) {
            delete service;
        }
    }

    void addService(Service* service) {
        services.push_back(service);
        saveToFile("services.txt");
    }

    void removeService(const std::string& type) {
        services.erase(std::remove_if(services.begin(), services.end(), [&type](Service* service) {
            return service->getType() == type;
        }), services.end());
        saveToFile("services.txt");
    }

    void editService(const std::string& type, const std::string& newType, double newPrice) {
        for (auto& service : services) {
            if (service->getType() == type) {
                service->editService(newType, newPrice);
                break;
            }
        }
        saveToFile("services.txt");
    }

    void displayServices() const {
        for(const auto& service : services) {
            service->display();
        }
    }

    void addClient(const Client& client) {
        clients.push_back(client);
    }

    void removeClient(const std::string& name) {
        clients.erase(std::remove_if(clients.begin(), clients.end(), [&name](const Client& client) {
            return client.getName() == name;
        }), clients.end());
    }

    void displayClients() const {
        for(const auto& client : clients) {
            client.display();
        }
    }

    void addMaster(const Master& master) {
        masters.push_back(master);
    }

    void removeMaster(const std::string& name) {
        masters.erase(std::remove_if(masters.begin(), masters.end(), [&name](const Master& master) {
            return master.getName() == name;
        }), masters.end());
    }

    void displayMasters() const {
        for(const auto& master : masters) {
            master.display();
        }
    }

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(const std::string& name) {
        products.erase(std::remove_if(products.begin(), products.end(), [&name](const Product& product) {
            return product.getName() == name;
        }), products.end());
    }

    void displayProducts() const {
        for(const auto& product : products) {
            product.display();
        }
    }

    void bookService(const std::string& clientName, const std::string& serviceType, const std::string& date, const std::string& masterName) {
        std::cout << "Booking: " << clientName << " booked " << serviceType << " on " << date << " with " << masterName << std::endl;
    }

    void registerService(const std::string& clientName, const std::string& serviceType, const std::string& date, const std::string& masterName) {
        std::cout << "Registering: " << clientName << " received " << serviceType << " on " << date << " from " << masterName << std::endl;
    }
};

int main() {
    Salon salon;

    salon.addService(new Haircut("Men's Cut", 20.0));
    salon.addService(new Coloring("Hair Dye", 40.0));
    salon.displayServices();

    salon.addClient(Client("John Doe", "123-456-789"));
    salon.addMaster(Master("Jane Smith", "Hair Stylist"));
    salon.addProduct(Product("Shampoo", 10.0));

    salon.displayClients();
    salon.displayMasters();
    salon.displayProducts();

    salon.bookService("John Doe", "Men's Cut", "2024-12-05", "Jane Smith");
    salon.registerService("John Doe", "Men's Cut", "2024-12-05", "Jane Smith");

    return 0;
}

//Завдання 8
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Athlete {
    std::string name;
    std::string coach;
    std::string country;
public:
    Athlete(const std::string& name, const std::string& coach, const std::string& country)
        : name(name), coach(coach), country(country) {}
    std::string getName() const { return name; }
    std::string getCoach() const { return coach; }
    std::string getCountry() const { return country; }
    void display() const {
        std::cout << "Athlete - Name: " << name << ", Coach: " << coach << ", Country: " << country << std::endl;
    }
};

class Competition {
    std::string name;
public:
    Competition(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
    void display() const {
        std::cout << "Competition - Name: " << name << std::endl;
    }
};

class Result {
    std::string athleteName;
    std::string competitionName;
    std::string date;
    double result;
public:
    Result(const std::string& athleteName, const std::string& competitionName, const std::string& date, double result)
        : athleteName(athleteName), competitionName(competitionName), date(date), result(result) {}
    void display() const {
        std::cout << "Result - Athlete: " << athleteName << ", Competition: " << competitionName
                  << ", Date: " << date << ", Result: " << result << std::endl;
    }
    std::string getAthleteName() const { return athleteName; }
    std::string getCompetitionName() const { return competitionName; }
    std::string getDate() const { return date; }
    double getResult() const { return result; }
};

class CompetitionManager {
    std::vector<Athlete> athletes;
    std::vector<Competition> competitions;
    std::vector<Result> results;

    void saveAthletesToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& athlete : athletes) {
                file << athlete.getName() << "," << athlete.getCoach() << "," << athlete.getCountry() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving athletes\n";
        }
    }

    void saveCompetitionsToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& competition : competitions) {
                file << competition.getName() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving competitions\n";
        }
    }

    void saveResultsToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& result : results) {
                file << result.getAthleteName() << "," << result.getCompetitionName() << ","
                     << result.getResult() << "," << result.getDate() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving results\n";
        }
    }

public:
    void loadAthletesFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string name, coach, country;
            while (file >> name >> coach >> country) {
                athletes.emplace_back(name, coach, country);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading athletes\n";
        }
    }

    void loadCompetitionsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string name;
            while (file >> name) {
                competitions.emplace_back(name);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading competitions\n";
        }
    }

    void loadResultsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string athleteName, competitionName, date;
            double result;
            while (file >> athleteName >> competitionName >> result >> date) {
                results.emplace_back(athleteName, competitionName, date, result);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading results\n";
        }
    }

    void addAthlete(const Athlete& athlete) {
        athletes.push_back(athlete);
        saveAthletesToFile("athletes.txt");
    }

    void removeAthlete(const std::string& name) {
        athletes.erase(std::remove_if(athletes.begin(), athletes.end(), [&name](const Athlete& athlete) {
            return athlete.getName() == name;
        }), athletes.end());
        saveAthletesToFile("athletes.txt");
    }

    void displayAthletes() const {
        for (const auto& athlete : athletes) {
            athlete.display();
        }
    }

    void addCompetition(const Competition& competition) {
        competitions.push_back(competition);
        saveCompetitionsToFile("competitions.txt");
    }

    void removeCompetition(const std::string& name) {
        competitions.erase(std::remove_if(competitions.begin(), competitions.end(), [&name](const Competition& competition) {
            return competition.getName() == name;
        }), competitions.end());
        saveCompetitionsToFile("competitions.txt");
    }

    void displayCompetitions() const {
        for (const auto& competition : competitions) {
            competition.display();
        }
    }

    void recordResult(const Result& result) {
        results.push_back(result);
        saveResultsToFile("results.txt");
    }

    void displayResults() const {
        for (const auto& result : results) {
            result.display();
        }
    }

    void determineWinners(const std::string& competitionName) const {
        std::vector<Result> competitionResults;
        for (const auto& result : results) {
            if (result.getCompetitionName() == competitionName) {
                competitionResults.push_back(result);
            }
        }

        if (!competitionResults.empty()) {
            std::sort(competitionResults.begin(), competitionResults.end(), [](const Result& a, const Result& b) {
                return a.getResult() < b.getResult();
            });

            std::cout << "Winners for " << competitionName << ":\n";
            for (const auto& result : competitionResults) {
                result.display();
            }
        } else {
            std::cout << "No results for " << competitionName << "\n";
        }
    }
};

int main() {
    CompetitionManager manager;

    manager.loadAthletesFromFile("athletes.txt");
    manager.loadCompetitionsFromFile("competitions.txt");
    manager.loadResultsFromFile("results.txt");

    manager.addAthlete(Athlete("John Doe", "Jane Smith", "USA"));
    manager.addCompetition(Competition("100m Dash"));
    manager.recordResult(Result("John Doe", "100m Dash", "2024-12-04", 10.5));

    manager.displayAthletes();
    manager.displayCompetitions();
    manager.displayResults();

    manager.determineWinners("100m Dash");

    return 0;
}

//Завдання 9
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Service {
    std::string name;
    double price;
public:
    Service(const std::string& name, double price) : name(name), price(price) {}
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    void setName(const std::string& newName) { name = newName; }
    void setPrice(double newPrice) { price = newPrice; }
    void display() const {
        std::cout << "Service - Name: " << name << ", Price: " << price << std::endl;
    }
};

class Order {
    std::string serviceName;
    std::string customerName;
    std::string date;
    bool isCompleted;
public:
    Order(const std::string& serviceName, const std::string& customerName, const std::string& date, bool isCompleted)
        : serviceName(serviceName), customerName(customerName), date(date), isCompleted(isCompleted) {}
    std::string getServiceName() const { return serviceName; }
    std::string getCustomerName() const { return customerName; }
    std::string getDate() const { return date; }
    bool getIsCompleted() const { return isCompleted; }
    void setIsCompleted(bool status) { isCompleted = status; }
    void display() const {
        std::cout << "Order - Service: " << serviceName << ", Customer: " << customerName
                  << ", Date: " << date << ", Completed: " << (isCompleted ? "Yes" : "No") << std::endl;
    }
};

class PostOffice {
    std::vector<Service> services;
    std::vector<Order> orders;

    void saveServicesToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& service : services) {
                file << service.getName() << "," << service.getPrice() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving services\n";
        }
    }

    void loadServicesFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string name;
            double price;
            while (file >> name >> price) {
                services.emplace_back(name, price);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading services\n";
        }
    }

    void saveOrdersToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& order : orders) {
                file << order.getServiceName() << "," << order.getCustomerName() << ","
                     << order.getDate() << "," << order.getIsCompleted() << "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for saving orders\n";
        }
    }

    void loadOrdersFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string serviceName, customerName, date;
            bool isCompleted;
            while (file >> serviceName >> customerName >> date >> isCompleted) {
                orders.emplace_back(serviceName, customerName, date, isCompleted);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for loading orders\n";
        }
    }

public:
    void addService(const Service& service) {
        services.push_back(service);
        saveServicesToFile("services.txt");
    }

    void removeService(const std::string& name) {
        services.erase(std::remove_if(services.begin(), services.end(), [&name](const Service& service) {
            return service.getName() == name;
        }), services.end());
        saveServicesToFile("services.txt");
    }

    void editService(const std::string& name, const std::string& newName, double newPrice) {
        for (auto& service : services) {
            if (service.getName() == name) {
                service.setName(newName);
                service.setPrice(newPrice);
                break;
            }
        }
        saveServicesToFile("services.txt");
    }

    void displayServices() const {
        for (const auto& service : services) {
            service.display();
        }
    }

    void addOrder(const Order& order) {
        orders.push_back(order);
        saveOrdersToFile("orders.txt");
    }

    void completeOrder(const std::string& serviceName, const std::string& customerName) {
        for (auto& order : orders) {
            if (order.getServiceName() == serviceName && order.getCustomerName() == customerName) {
                order.setIsCompleted(true);
                break;
            }
        }
        saveOrdersToFile("orders.txt");
    }

    void displayOrders() const {
        for (const auto& order : orders) {
            order.display();
        }
    }

    void displayCompletedOrders() const {
        for (const auto& order : orders) {
            if (order.getIsCompleted()) {
                order.display();
            }
        }
    }

    void loadFromFile() {
        loadServicesFromFile("services.txt");
        loadOrdersFromFile("orders.txt");
    }
};

int main() {
    PostOffice postOffice;

    postOffice.loadFromFile();

    postOffice.addService(Service("Parcel Delivery", 50.0));
    postOffice.addService(Service("Document Delivery", 20.0));
    postOffice.displayServices();

    postOffice.addOrder(Order("Parcel Delivery", "John Doe", "2024-12-04", false));
    postOffice.displayOrders();

    postOffice.completeOrder("Parcel Delivery", "John Doe");
    postOffice.displayCompletedOrders();

    return 0;
}

//Завдання 10
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Animal {
public:
    std::string name;
    std::string species;

    Animal(std::string n, std::string s) : name(n), species(s) {}
};

class Food {
public:
    std::string name;
    double price;

    Food(std::string n, double p) : name(n), price(p) {}
};

class Zoo {
private:
    std::vector<Animal> animals;
    std::vector<Food> foods;
    double dailyExpenses;

public:
    Zoo() : dailyExpenses(0) {}

    void addAnimal(const std::string& name, const std::string& species) {
        animals.emplace_back(name, species);
    }

    void addFood(const std::string& name, double price) {
        foods.emplace_back(name, price);
    }

    void logDailyExpense(double expense) {
        dailyExpenses += expense;
        std::ofstream outFile("expenses.txt", std::ios::app);
        outFile << "Витрати: " << expense << "\n";
        outFile.close();
    }

    void saveAnimalsToFile() {
        std::ofstream outFile("animals.txt");
        for (const auto& animal : animals) {
            outFile << animal.name << "," << animal.species << "\n";
        }
        outFile.close();
    }

    void loadAnimalsFromFile() {
        std::ifstream inFile("animals.txt");
        std::string line;
        while (std::getline(inFile, line)) {
            size_t pos = line.find(',');
            if (pos != std::string::npos) {
                std::string name = line.substr(0, pos);
                std::string species = line.substr(pos + 1);
                addAnimal(name, species);
            }
        }
        inFile.close();
    }

    void showAnimals() {
        for (const auto& animal : animals) {
            std::cout << "Ім'я: " << animal.name << ", Вид: " << animal.species << "\n";
        }
    }

    void showFoods() {
        for (const auto& food : foods) {
            std::cout << "Корм: " << food.name << ", Ціна: " << food.price << "\n";
        }
    }
};

int main() {
    Zoo zoo;
    zoo.loadAnimalsFromFile();

    int choice;
    do {
        std::cout << "1. Додати тварину\n";
        std::cout << "2. Показати тварин\n";
        std::cout << "3. Додати корм\n";
        std::cout << "4. Показати корми\n";
        std::cout << "5. Записати щоденні витрати\n";
        std::cout << "6. Зберегти тварин у файл\n";
        std::cout << "0. Вихід\n";
        std::cout << "Виберіть опцію: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name, species;
                std::cout << "Введіть ім'я тварини: ";
                std::cin >> name;
                std::cout << "Введіть вид: ";
                std::cin >> species;
                zoo.addAnimal(name, species);
                break;
            }
            case 2:
                zoo.showAnimals();
                break;
            case 3: {
                std::string foodName;
                double price;
                std::cout << "Введіть назву корму: ";
                std::cin >> foodName;
                std::cout << "Введіть ціну: ";
                std::cin >> price;
                zoo.addFood(foodName, price);
                break;
            }
            case 4:
                zoo.showFoods();
                break;
            case 5: {
                double expense;
                std::cout << "Введіть щоденні витрати: ";
                std::cin >> expense;
                zoo.logDailyExpense(expense);
                break;
            }
            case 6:
                zoo.saveAnimalsToFile();
                break;
            case 0:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Неправильний вибір. Спробуйте знову.\n";
        }
    } while (choice != 0);

    return 0;
}

//Завдання 11
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class Student {
public:
    std::string name;
    std::vector<double> grades;

    Student(const std::string& n) : name(n) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    double calculateAverage() const {
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return (grades.empty()) ? 0 : sum / grades.size();
    }
};

class Subject {
public:
    std::string name;
    int lessonsPerWeek;

    Subject(const std::string& n, int l) : name(n), lessonsPerWeek(l) {}
};

class ClassJournal {
private:
    std::vector<Student> students;
    std::vector<Subject> subjects;

public:
    void addStudent(const std::string& name) {
        students.emplace_back(name);
    }

    void removeStudent(const std::string& name) {
        students.erase(std::remove_if(students.begin(), students.end(),
                        [&](Student& s) { return s.name == name; }), students.end());
    }

    void addSubject(const std::string& name, int lessons) {
        subjects.emplace_back(name, lessons);
    }

    void removeSubject(const std::string& name) {
        subjects.erase(std::remove_if(subjects.begin(), subjects.end(),
                        [&](Subject& s) { return s.name == name; }), subjects.end());
    }

    void addGrade(const std::string& studentName, double grade) {
        for (auto& student : students) {
            if (student.name == studentName) {
                student.addGrade(grade);
                return;
            }
        }
    }

    void displayStudents() {
        for (const auto& student : students) {
            std::cout << "Учень: " << student.name << ", Середній бал: " 
                      << std::fixed << std::setprecision(2) << student.calculateAverage() << "\n";
        }
    }

    void saveStudentsToFile() {
        std::ofstream outFile("learners.txt");
        for (const auto& student : students) {
            outFile << student.name << "\n";
            for (double grade : student.grades) {
                outFile << grade << " ";
            }
            outFile << "\n";
        }
        outFile.close();
    }

    void loadStudentsFromFile() {
        std::ifstream inFile("learners.txt");
        std::string name;
        while (std::getline(inFile, name)) {
            Student student(name);
            double grade;
            while (inFile >> grade) {
                student.addGrade(grade);
            }
            students.push_back(student);
            inFile.ignore();
        }
        inFile.close();
    }
};

int main() {
    ClassJournal journal;
    journal.loadStudentsFromFile();

    int choice;
    do {
        std::cout << "1. Додати учня\n";
        std::cout << "2. Видалити учня\n";
        std::cout << "3. Додати предмет\n";
        std::cout << "4. Видалити предмет\n";
        std::cout << "5. Додати оцінку\n";
        std::cout << "6. Показати учнів\n";
        std::cout << "7. Зберегти учнів у файл\n";
        std::cout << "0. Вихід\n";
        std::cout << "Виберіть опцію: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Введіть ім'я учня: ";
                std::cin >> name;
                journal.addStudent(name);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Введіть ім'я учня для видалення: ";
                std::cin >> name;
                journal.removeStudent(name);
                break;
            }
            case 3: {
                std::string subjectName;
                int lessons;
                std::cout << "Введіть назву предмета: ";
                std::cin >> subjectName;
                std::cout << "Введіть кількість уроків на тиждень: ";
                std::cin >> lessons;
                journal.addSubject(subjectName, lessons);
                break;
            }
            case 4: {
                std::string subjectName;
                std::cout << "Введіть назву предмета для видалення: ";
                std::cin >> subjectName;
                journal.removeSubject(subjectName);
                break;
            }
            case 5: {
                std::string studentName;
                double grade;
                std::cout << "Введіть ім'я учня: ";
                std::cin >> studentName;
                std::cout << "Введіть оцінку: ";
                std::cin >> grade;
                journal.addGrade(studentName, grade);
                break;
            }
            case 6:
                journal.displayStudents();
                break;
            case 7:
                journal.saveStudentsToFile();
                break;
            case 0:
                std::cout << "Вихід...\n";
                break;
            default:
                std::cout << "Неправильний вибір. Спробуйте знову.\n";
        }
    } while (choice != 0);

    return 0;
}