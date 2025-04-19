#pragma once

#include <iostream>
#include <string>
#include <pqxx/pqxx>

class ClientsControl
{
    pqxx::connection connectionObject;
    pqxx::work tx;

public:
    ClientsControl(const std::string& connectionString): connectionObject{connectionString}, tx{connectionObject}{}

    void commit();

    void create_tables_for_clients();

    void delete_tables_for_clients();

    void insert_client(int id, const std::string& first_name, const std::string& last_name, const std::string& email);

    void insert_phone(int id, const std::string& phone, int client_id);

    void update_client(int id, const std::string& first_name, const std::string& last_name, const std::string& email);

    void delete_phone(int id);

    void delete_client(int id);

    int select_client_by_first_name(const std::string& first_name);

    int select_client_by_last_name(const std::string& last_name);

    int select_client_by_email(const std::string& email);

    int select_client_by_phone(const std::string& phone);

    void select_all_clients();
    
    void select_all_phones();
};
