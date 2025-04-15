#include "Windows.h"

#include <iostream>
#include <string>
#include <pqxx/pqxx>

#include "ClientsControl.h"

int main()
{
    try
    {
        ClientsControl clients_control{"host=localhost port=5432 dbname=postgres user=postgres password=12345"};

        char select{};
        bool connection{true};
        int id{};
        std::string first_name{};
        std::string last_name{};
        std::string email{};
        std::string phone{};
        int client_id{};
        while(connection)
        {
            std::cout << 
                         "0. Create tables for clients.\n"
                         "1. Insert client.\n"
                         "2. Insert phone of client.\n"
                         "3. Update client.\n"
                         "4. Delete phone of client.\n"
                         "5. Delete client.\n"
                         "6. Delete tables for clients.\n"
                         "7. Select all clients.\n"
                         "8. Select all phones.\n"
                         "9. Select client of first name.\n"
                         "+. Select client of last name.\n"
                         "-. Select client of email.\n"
                         "=. Select client of phone.\n"
                         "\\. Exit.\n";
            std::cin >> select;
            switch(select)
            {
                case '0':
                {
                    std::cout << "\033c";
                    clients_control.create_tables_for_clients();
                } break;
                case '1':
                {
                    std::cout << "Enter id of client: ";
                    std::cin >> id;
                    std::cout << "Enter first name of client: ";
                    std::cin >> first_name;
                    std::cout << "Enter last name of client: ";
                    std::cin >> last_name;
                    std::cout << "Enter email of client: ";
                    std::cin >> email;
                    std::cout << "\033c";
                    clients_control.insert_client(id, first_name, last_name, email);
                } break;
                case '2':
                {
                    std::cout << "Enter id of phone: ";
                    std::cin >> id;
                    std::cout << "Enter id of client: ";
                    std::cin >> client_id;
                    std::cout << "Enter phone of client: ";
                    std::cin >> phone;
                    std::cout << "\033c";
                    clients_control.insert_phone(id, phone, client_id);
                } break;
                case '3':
                {
                    std::cout << "Select id of client: ";
                    std::cin >> id;
                    std::cout << "Enter first name: ";
                    std::cin >> first_name;
                    std::cout << "Enter last name: ";
                    std::cin >> last_name;
                    std::cout << "Enter email: ";
                    std::cin >> email;
                    std::cout << "\033c";
                    clients_control.update_client(id, first_name, last_name, email);
                } break;
                case '4':
                {
                    std::cout << "Select id of phone: ";
                    std::cin >> id;
                    std::cout << "\033c";
                    clients_control.delete_phone(id);
                } break;
                case '5':
                {
                    std::cout << "Select id of client: ";
                    std::cin >> id;
                    std::cout << "\033c";
                    clients_control.delete_client(id);
                } break;
                case '6':
                {
                    std::cout << "\033c";
                    clients_control.delete_tables_for_clients();
                } break;
                case '7':
                {
                    std::cout << "\033c";
                    clients_control.select_all_clients();
                } break;
                case '8':
                {
                    std::cout << "\033c";
                    clients_control.select_all_phones();
                } break;
                case '9':
                {
                    std::cout << "Enter first name: ";
                    std::cin >> first_name;
                    std::cout << "\033c";
                    clients_control.select_client_by_first_name(first_name);
                } break;
                case '+':
                {
                    std::cout << "Enter last name: ";
                    std::cin >> last_name;
                    std::cout << "\033c";
                    clients_control.select_client_by_last_name(last_name);
                } break;
                case '-':
                {
                    std::cout << "Enter email: ";
                    std::cin >> email;
                    std::cout << "\033c";
                    clients_control.select_client_by_email(email);
                } break;
                case '=':
                {
                    std::cout << "Enter phone: ";
                    std::cin >> phone;
                    std::cout << "\033c";
                    clients_control.select_client_by_phone(phone);
                } break;
                case '\\': connection = false; break;
            }
        }
        clients_control.commit();
    }
    catch(pqxx::sql_error e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}
