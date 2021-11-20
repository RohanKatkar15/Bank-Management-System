#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<sstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;


vector<string> ReadFileLines(string path){
    vector<string> lines;

    fstream file(path.c_str());

    if(file.fail()){
            system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\tERROR: Can not open the file!!\n\n";
        return lines;
    }

    string line;

    while(getline(file, line))
        if(line.size() != 0)
            lines.push_back(line);

    file.close();

    return lines;
}

void WriteFileLines(string path, vector<string> lines, bool append = true){
    auto status = ios::in | ios::out | ios::app;

    if(!append)
        status = ios::in | ios::out | ios::trunc;

    fstream file(path.c_str(), status);

    if(file.fail()){
            system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\t\tERROR: Can not open the file!!\n\n";
        return;
    }

    for(auto line : lines)
        file << line << "\n";

    file.close();
}

vector<string> SpiltString(string line, string delimeter = ","){
    vector<string> subs;
    string subStr;
    int pos = 0;

    while((pos = (int)line.find(delimeter)) != -1){
        subStr = line.substr(0, pos);
        subs.push_back(subStr);
        line.erase(0, pos+delimeter.size());
    }
    subs.push_back(subStr);
    return subs;
}

int StringTOInteger(string num){
    istringstream iss(num);
    int val;
    iss >> val;
    return val;
}

int ValidChoice(int lft, int rit){
    int choice; cin >> choice;

    if(choice >= lft && choice <= rit)
        return choice;

    cout << "\nChoose number in range "<< lft << " - " << rit << " : ";
    ValidChoice(lft, rit);
}

int ShowMenu(vector<string> menu){
    cout << "\n\n";

    for(int i=0; i<menu.size(); ++i)
        cout << (i+1) << "- " << menu[i] << "\n";

    cout << "\n\n\n\t\t\tChoose number to continue: ";
    return ValidChoice(1, menu.size());
}



struct AdminAccount{
    string user_name;
    string password;
    string name;
    string phone_number;
    int age;

    AdminAccount(){
        user_name = password = name = phone_number = "";
        age = 0;
    }

    AdminAccount(string line){
        vector<string> user_data = SpiltString(line);
        assert(user_data.size() == 5);

        user_name = user_data[0];
        password = user_data[1];
        name = user_data[2];
        phone_number = user_data[3];
        age = StringTOInteger(user_data[4]);

    }

    string toString(){
        ostringstream oss;
        oss << user_name << ","
            << password << ","
            << name << ","
            << phone_number << ","
            << age;
        return oss.str();
    }

    void printData(){
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t:::::Admin Details:::::" << "\n"
             << "\n\n\t\t\t\t\t\tUser Name : " << user_name << "\n"
             << "\t\t\t\t\t\tPassword: " << password << "\n"
             << "\t\t\t\t\t\tName: " << name << "\n"
             << "\t\t\t\t\t\tPhone Number: " << phone_number << "\n\n";
    }

    void setData(){
        char ch;
        cin.ignore();
        cout << "\n\n\n\n\n\n\t\t\t\t\t\tEnter Username Number : "; getline(cin, user_name);
        cout << "\t\t\t\t\t\tEnter password: ";
                    string pass ="";

   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   password=pass;
   cout << endl;
        cout << "\t\t\t\t\t\tEnter name: "; getline(cin, name);
        cout << "\t\t\t\t\t\tEnter phone number: "; getline(cin, phone_number);
        cout << "\t\t\t\t\t\tEnter age: "; cin >> age;
        cout << "\n\n";
    }
};

struct UserAccount{
    string user_name;
    string password;
    string name;
    string phone_number;
    int balance;
    int amount_of_money;

    UserAccount(){
        user_name = password = name = phone_number = "";
        balance =0;
        amount_of_money = 0;
    }

    UserAccount(string line){
        vector<string> user_data = SpiltString(line);

        assert(user_data.size() == 6);

        user_name = user_data[0];
        password = user_data[1];
        name = user_data[2];
        phone_number = user_data[3];
        balance = StringTOInteger(user_data[4]);
        amount_of_money = StringTOInteger(user_data[5]);
    }

    string toString(){
        ostringstream oss;
        oss << user_name << ","
            << password << ","
            << name << ","
            << phone_number << ","
            << balance << ","
            << amount_of_money;
        return oss.str();
    }

    void printData(){
        cout << "\n\n\n\n\n\n\t\t\t\t\t\tAccount Number : " << user_name << "\n"
             << "\t\t\t\t\t\tPassword : " << password << "\n"
             << "\t\t\t\t\t\tName : " << name << "\n"
             << "\t\t\t\t\t\tPhone Number : " << phone_number << "\n"
             << "\t\t\t\t\t\tMoney : RS " << balance << "\n\n";
    }

    void setData(){
        cin.ignore();
        int data;
        ifstream infile("acc_number.txt",ios::in);
        infile >> data;
        char ch;
        string str = to_string(data);
        user_name = str;
        cout << "\n\n\n\n\n\n\t\t\t\t\tYour Account Number is : "; cout << user_name<< endl;
        cout << "\t\t\t\t\tEnter password: ";
                    string pass ="";

   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   password=pass;
   cout << endl;
        cout << "\t\t\t\t\tEnter name: "; getline(cin, name);
        cout << "\t\t\t\t\tEnter phone number: "; getline(cin, phone_number);
        cout << "\t\t\t\t\tEnter amount of money: "; cin >> balance;
        cout << "\n\n";
        infile.close();
        data++;
        remove("acc_number.txt");
        ofstream outfile("acc_number.txt",ios::out);
        outfile << data;
    }
};

struct AdminManager{
    map<string, AdminAccount> admins_data_map;
    AdminAccount cur_admin;

    void loadDatabase(){
        admins_data_map.clear();

        vector<string> lines = ReadFileLines("admins.txt");

        for(auto &line : lines){
            AdminAccount admin(line);
            admins_data_map[admin.user_name] = admin;
        }
    }

    void login(){
        cin.ignore();
        system("cls");
        char ch;
        while(true){
            cout << "\n\n";
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter User name : "; getline(cin, cur_admin.user_name);
            cout << "\t\t\t\t\t\tEnter Password: ";             string pass ="";

   ch = _getch();

   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout << endl;
   cur_admin.password=pass;
            if(!adminExist()){
                    system("cls");
                cout << "\n\n\n\n\n\n\t\t\t\t\t\tWrong user name!!";
                continue;
            }

            AdminAccount ext_admin = admins_data_map[cur_admin.user_name];

            if(ext_admin.password != cur_admin.password){
                    system("cls");
                cout << "\n\n\n\n\n\n\t\t\t\t\t\tWrong Password!!";
                continue;
            }

            cur_admin  = ext_admin;
            break;
        }
    }

    bool adminExist(){
        return admins_data_map.count(cur_admin.user_name);
    }

    void insertAdmin(){
        vector<string> lines(1, cur_admin.toString());

        WriteFileLines("admins.txt", lines);
    }

    void deleteAdmin(){
        cin.ignore();
        cout << "\n\n";
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter User Name : "; getline(cin, cur_admin.user_name);

        if(adminExist())
            admins_data_map.erase(cur_admin.user_name);
        else
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe Account is not Exsist\n\n";
    }

    void updateDatabase(){
        vector<string> lines;

		for(auto &pair : admins_data_map)
			lines.push_back(pair.second.toString());

		WriteFileLines("admins.txt", lines, false);
    }

    void updateAdmin(){
        cin.ignore();
        cout << "\n\n";
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter user name: "; getline(cin, cur_admin.user_name);

        if(!adminExist()){
                system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe User Name Doesn't Exist";
            return;
        }
        char ch;
        cout << "\n\n";
        cout << "\t\t\t\t\t\tEnter password: ";             string pass ="";

   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cur_admin.password=pass;
   cout << endl;
        cout << "\t\t\t\t\t\tEnter name: "; getline(cin, cur_admin.name);
        cout << "\t\t\t\t\t\tEnter phone number: "; getline(cin, cur_admin.phone_number);
        cout << "\t\t\t\t\t\tEnter age: "; cin >> cur_admin.age;

        admins_data_map[cur_admin.user_name] = cur_admin;
    }

    void searchAdmin(){
        cin.ignore();
        cout << "\n\n";
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter user name: "; getline(cin, cur_admin.user_name);

        if(!adminExist()){
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe User Name Doesn't Exist";
            return;
        }

        admins_data_map[cur_admin.user_name].printData();
    }
};


struct UsersManager{
    map<string, UserAccount> users_data_map;
    UserAccount cur_user;

    void loadDatabase(){
        users_data_map.clear();

        vector<string> lines = ReadFileLines("users.txt");

        for(auto &line : lines){
            UserAccount user(line);
            users_data_map[user.user_name] = user;
        }
    }

    void login(){
        cin.ignore();
        char ch;
        while(true){
            cout << "\n\n";
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Account Number : "; getline(cin, cur_user.user_name);
            cout << "\t\t\t\t\t\tEnter Password : ";
               string pass ="";

   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cur_user.password=pass;
   cout << endl;

            if(!userExist()){
                    system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tWrong Account Number!!";
                continue;
            }

            UserAccount ext_user = users_data_map[cur_user.user_name];

            if(ext_user.password != cur_user.password){
                cout << "\n\nWrong Password!!";
                continue;
            }

            cur_user  = ext_user;
            break;
        }
    }

    void depositMoney(){

        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tYour money = RS " << cur_user.balance << "\n";
        cout << "\t\t\t\t\t\tEnter the value: ";
        int depositMoney; cin >> depositMoney;

        cur_user.balance += depositMoney;

        users_data_map[cur_user.user_name] = cur_user;
    }

    void withdrawMoney(){
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tYour money = Rs " << cur_user.balance << "\n";
        cout << "\t\t\t\t\t\tEnter the value: ";
        int withdraw_money = ValidChoice(0, cur_user.amount_of_money);

        cur_user.balance -= withdraw_money;

        users_data_map[cur_user.user_name] = cur_user;
    }

    void updateDatabase(){
        vector<string> lines;

		for(auto &pair : users_data_map)
			lines.push_back(pair.second.toString());

		WriteFileLines("users.txt", lines, false);
    }

    void insertUser(){
        vector<string> lines(1, cur_user.toString());

        WriteFileLines("users.txt", lines);
    }

    bool userExist(){
        return users_data_map.count(cur_user.user_name);
    }

    void deleteUser(){
        cin.ignore();
        cout << "\n\n";
        cout << "Enter Account Number : "; getline(cin, cur_user.user_name);

        if(userExist())
            users_data_map.erase(cur_user.user_name);
        else
            cout << "\nThe Account doesn't exist";
    }

    void updateUser(){
        cin.ignore();
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Account Number : "; getline(cin, cur_user.user_name);

        if(!userExist()){
                system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe Account doesn't exist";
            return;
        }
        char ch;
        cout << "\t\t\t\t\t\tEnter password: ";             string pass ="";

   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cur_user.password=pass;
   cout << endl;
        cout << "\t\t\t\t\t\tEnter name: "; getline(cin, cur_user.name);
        cout << "\t\t\t\t\t\tEnter phone number: "; getline(cin, cur_user.phone_number);
        cout << "\t\t\t\t\t\tEnter amount of money: "; cin>> cur_user.balance;

        users_data_map[cur_user.user_name] = cur_user;
    }

    void searchUser(){
        cin.ignore();
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Account Number : "; getline(cin, cur_user.user_name);

        if(!userExist()){
                system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe Account doesn't exist";
            return;
        }

        users_data_map[cur_user.user_name].printData();
    }
};

struct BankSystem{
    AdminManager admin_manager;
    AdminManager newAdmin;
    UsersManager user_manager;

    void loadDatabase(){
        admin_manager.loadDatabase();
        newAdmin.loadDatabase();
        user_manager.loadDatabase();
    }

    vector<string> adminOrUser(){
        vector<string> menu;
        menu.push_back("\t\t\t\t\t\t\tAdmin");
        menu.push_back("\t\t\t\t\t\t\tUser");

        return menu;
    }

    bool main_admin = false;
    vector<string> adminMenu(){
        vector<string> menu;
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t:::  Welcome to Admin Login  :::\n\n";
        menu.push_back("\t\t\t\t\t\tDisplay your data");
        menu.push_back("\t\t\t\t\t\tCreate new user account");
        menu.push_back("\t\t\t\t\t\tDelete user account");
        menu.push_back("\t\t\t\t\t\tUpdate user account");
        menu.push_back("\t\t\t\t\t\tSearch for user account");

        if(admin_manager.cur_admin.user_name == "Admin"){
            main_admin = true;
            menu.push_back("\t\t\t\t\t\tCreate new Admin account");
            menu.push_back("\t\t\t\t\t\tDelete Admin account");
            menu.push_back("\t\t\t\t\t\tUpdate Admin account");
            menu.push_back("\t\t\t\t\t\tSearch for Admin account");
        }
        menu.push_back("\t\t\t\t\t\tLogout");

        return menu;
    }

    vector<string> userMenu(){
        vector<string> menu;
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t:::  Welcome to User Login  :::\n\n";
        menu.push_back("\t\t\t\t\t\tDisplay your data");
        menu.push_back("\t\t\t\t\t\tWithdraw money");
        menu.push_back("\t\t\t\t\t\tDeposit money");
        menu.push_back("\t\t\t\t\t\tLogout");

        return menu;
    }

    void run(){
        system("color E0");
        loadDatabase();
        cout << "\n\n\t\t\t\t\t\tBank Management System\n\n" <<endl;

        int choice = ShowMenu(adminOrUser());

        if(choice == 1){
            admin_manager.login();
            system("cls");

            while(true){
                loadDatabase();
                choice = ShowMenu(adminMenu());

                if(choice == 1){
                    system("cls");
                    admin_manager.cur_admin.printData();
                    cin.get();
                    cin.get();
                    system("cls");
                }

                else if(choice == 2){
                    while(true){
                        system("cls");
                        user_manager.cur_user.setData();

                        if(user_manager.userExist()){
                                system("cls");
                            cout << "\nThe user name already exists!\n\n";
                            continue;
                        }

                        user_manager.insertUser();
                        break;
                    }
                }
                else if(choice == 3){
                        system("cls");
                    user_manager.deleteUser();
                    user_manager.updateDatabase();
                }
                else if(choice == 4){
                    system("cls");
                    user_manager.updateUser();
                    user_manager.updateDatabase();
                }
                else if(choice == 5){
                        system("cls");
                    user_manager.searchUser();
                }
                else if(choice == 6 && main_admin){
                        system("cls");
                    while(true){
                        newAdmin.cur_admin.setData();

                        if(newAdmin.adminExist()){
                            cout << "\nThe User Name already exists!\n\n";
                            continue;
                        }

                        newAdmin.insertAdmin();
                        break;
                    }
                }
                else if(choice == 7 && main_admin){
                        system("cls");
                    newAdmin.deleteAdmin();
                    newAdmin.updateDatabase();
                }
                else if(choice == 8 && main_admin){
                    system("cls");
                    newAdmin.updateAdmin();
                    newAdmin.updateDatabase();
                }
                else if(choice == 9 && main_admin){
                    system("cls");
                    newAdmin.searchAdmin();
                }
                else{
                    main_admin = false;
                    break;
                }
            }
        }
        else {
            user_manager.login();
            system("cls");

            while(true){
                loadDatabase();
                choice = ShowMenu(userMenu());

                if(choice == 1){
                        system("cls");
                    user_manager.cur_user.printData();}
                else if(choice == 2){
                    system("cls");
                    user_manager.withdrawMoney();
                    user_manager.updateDatabase();
                }
                else if(choice == 3){
                    system("cls");
                    user_manager.depositMoney();
                    user_manager.updateDatabase();
                }
                else
                    break;
            }
        }
        run();
    }

};


int main(){

    BankSystem bank;

    bank.run();

return 0;
}