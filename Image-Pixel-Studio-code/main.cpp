#include <iostream>
#include "users/Admin.h"
#include "users/Customer.h"
#include "managers/CustomerManager.h"
#include "managers/CatalogManager.h"
#include "managers/SessionManager.h"
#include "managers/ImageManager.h"
#include "filters/FilterSession.h"

using namespace std;

// ================= CNIC VALIDATION =================
bool isValidCNIC(string cnic, CustomerFileManager &cm) {

    if (cnic.length() != 13) {
        cout << "CNIC must be 13 digits!\n";
        return false;
    }

    for (int i = 0; i < 13; i++) {
        if (cnic[i] < '0' || cnic[i] > '9') {
            cout << "CNIC must contain digits only!\n";
            return false;
        }
    }

    if (cm.cnicExists(cnic)) {
        cout << "CNIC already exists!\n";
        return false;
    }

    return true;
}

// ================= PASSWORD VALIDATION =================
bool isValidPassword(string pass) {

    if (pass.length() != 9) {
        cout << "Password must be exactly 9 characters!\n";
        return false;
    }

    bool hasUpper = false, hasDigit = false;

    for (int i = 0; i < pass.length(); i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') hasUpper = true;
        if (pass[i] >= '0' && pass[i] <= '9') hasDigit = true;
    }

    if (!hasUpper || !hasDigit) {
        cout << "Password must contain at least 1 uppercase and 1 digit!\n";
        return false;
    }

    return true;
}

// ================= REGISTER =================
void registerCustomer(CustomerFileManager &cm) {

    string cnic, pass, confirm, name, gender, phone, city;

    cout << "\n=== CUSTOMER REGISTRATION ===\n";

    cout << "Enter CNIC: ";
    cin >> cnic;

    if (!isValidCNIC(cnic, cm)) return;

    cout << "Enter Password: ";
    cin >> pass;

    if (!isValidPassword(pass)) return;

    cout << "Confirm Password: ";
    cin >> confirm;

    if (pass != confirm) {
        cout << "Passwords do not match!\n";
        return;
    }

    cin.ignore();

    cout << "Enter Full Name: ";
    getline(cin, name);

    cout << "Enter Gender (M/F/O): ";
    cin >> gender;

    cout << "Enter Phone: ";
    cin >> phone;

    cout << "Enter City: ";
    cin >> city;

    Customer *c = new Customer(cnic, pass, name, gender, phone, city, false, 0);
    cm.addCustomer(c);

    cout << "Registration successful!\n";
}

// ================= LOGIN =================
Customer* loginCustomer(CustomerFileManager &cm) {

    string cnic, pass;
    int attempts = 0;

    while (attempts < 3) {

        cout << "Enter CNIC: ";
        cin >> cnic;

        cout << "Enter Password: ";
        cin >> pass;

        int cnt;
        Customer** list = cm.loadAll(cnt);

        for (int i = 0; i < cnt; i++) {

            if (list[i]->getCNIC() == cnic &&
                list[i]->getPassword() == pass) {

                if (list[i]->getIsBlocked()) {
                    cout << "Account is BLOCKED!\n";
                    return nullptr;
                }

                cout << "Login successful!\n";
                return list[i];
            }
        }

        attempts++;
        cout << "Invalid credentials!\n";
    }

    cout << "Too many attempts. Returning to main menu.\n";
    return nullptr;
}

// ================= MAIN =================
int main() {

    CustomerFileManager cm("data/customers.txt");
    CatalogFileManager catalog("data/catalog.txt");
    SessionManager sm("data/sessions.txt");

    int choice;

    do {
        cout << "\n╔══════════════════════════════════════════╗\n";
        cout <<   "║        IMAGE FILTER STUDIO               ║\n";
        cout <<   "╠══════════════════════════════════════════╣\n";
        cout <<   "║  1. Admin Login                         ║\n";
        cout <<   "║  2. Customer Login                      ║\n";
        cout <<   "║  3. New Customer? Register here         ║\n";
        cout <<   "║  4. Exit                                ║\n";
        cout <<   "╚══════════════════════════════════════════╝\n";
        cout << "Your choice: ";
        cin >> choice;

        // ===== ADMIN =====
        if (choice == 1) {

            Admin admin;

            string id, pass;
            cout << "Enter Admin ID: ";
            cin >> id;
            cout << "Enter Admin Password: ";
            cin >> pass;

            if (admin.login(id, pass)) {

                int opt;
                do {
                    admin.displayMenu();
                    cin >> opt;

                    switch (opt) {

                        case 1:
                            admin.manageCustomers(cm);
                            break;

                        case 2: {
                            admin.manageCatalog(catalog);
                        }

                        case 3:
                            admin.viewAllSessions(sm);
                            break;

                        case 4:
                            admin.logout();
                            break;

                        default:
                            cout << "Invalid option!\n";
                    }

                } while (opt != 4);
            }
        }

        // ===== CUSTOMER =====
        else if (choice == 2) {

            Customer* cust = loginCustomer(cm);

            if (cust != nullptr) {

                Image* currentImage = nullptr;
                FilterSession* session = nullptr;

                int opt;
                do {
                    cust->displayMenu();
                    cin >> opt;

                    switch (opt) {

                        case 1:
                            catalog.displayCatalog();
                            break;

                        case 2: { // LOAD IMAGE
                            string path;
                            cout << "Enter image path: ";
                            cin >> path;

                            ImageFileManager im;
                            currentImage = im.load(path);

                            if(currentImage){
                                currentImage->displayASCII();
                            }
                            break;
                        }

                        case 3: { // BUILD PIPELINE
                            if(!currentImage){
                                cout << "Load image first!\n";
                                break;
                            }

                            session = new FilterSession(cust->getCNIC(), currentImage);

                            int count;
                            Filter** filters = catalog.getEnabledFilters(count);

                            cout << "\nAvailable Filters:\n";
                            for(int i=0;i<count;i++){
                                cout << i+1 << ". " << filters[i]->getName() << endl;
                            }

                            int ch;
                            while(true){
                                cout << "Enter filter (0 to stop): ";
                                cin >> ch;

                                if(ch==0) break;

                                if(ch>=1 && ch<=count){
                                    session->addFilter(filters[ch-1]);
                                    cout << "Added\n";
                                }
                            }
                            break;
                        }

                        case 4: { // APPLY + SAVE
                            if(!session){
                                cout << "Build pipeline first!\n";
                                break;
                            }

                            session->applyAll();
                            currentImage->displayASCII();

                            string filename = cust->getCNIC() + "_output.png";

                            ImageFileManager im;
                            im.save(filename, currentImage);

                            sm.addSession(cust->getCNIC(), "pipeline", filename);

                            cout << "Image processed and saved!\n";
                            break;
                        }

                        case 5:
                            sm.viewSessions(cust->getCNIC());
                            break;

                        case 6:
                            cust->logout();
                            break;

                        default:
                            cout << "Invalid option!\n";
                    }

                } while (opt != 6);
            }
        }

        // ===== REGISTER =====
        else if (choice == 3) {
            registerCustomer(cm);
        }

        else if (choice == 4) {
            cout << "Exiting program...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
