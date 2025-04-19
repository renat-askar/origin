#include "ClientsControl.h"

void ClientsControl::commit()
{
    tx.commit();
}

void ClientsControl::create_tables_for_clients()
{
    tx.exec("CREATE TABLE IF NOT EXISTS clients"
        "("
        "id serial PRIMARY KEY,"
        "first_name text NOT NULL,"
        "last_name text NOT NULL,"
        "email text NOT NULL"
        ");"

        "CREATE TABLE IF NOT EXISTS phones"
        "("
        "id serial PRIMARY KEY,"
        "phone text,"
        "clients_id integer references clients(id)"
        ");");
}

void ClientsControl::delete_tables_for_clients()
{
    tx.exec("DROP TABLE phones; DROP TABLE clients;");
}

void ClientsControl::insert_client(int id, const std::string& first_name, const std::string& last_name, const std::string& email)
{
    tx.exec("INSERT INTO clients(id, first_name, last_name, email)\n"
            "VALUES(" + tx.esc(std::to_string(id)) + ", '" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "')");
}

void ClientsControl::insert_phone(int id, const std::string& phone, int client_id)
{
    tx.exec("INSERT INTO phones(id, phone, clients_id)\n"
            "VALUES(" + tx.esc(std::to_string(id)) + ", '" + tx.esc(phone) + "', " + tx.esc(std::to_string(client_id)) + ')');
}

void ClientsControl::update_client(int id, const std::string& first_name, const std::string& last_name, const std::string& email)
{
    tx.exec("UPDATE clients "
            "SET first_name = '" + tx.esc(first_name) + "',\n"
            "last_name = '" + tx.esc(last_name) + "',\n"
            "email = '" + tx.esc(email) + "'"
            "WHERE id = " + std::to_string(id) + ';');
}

void ClientsControl::delete_phone(int id)
{
    tx.exec("DELETE from phones WHERE id = " + std::to_string(id) + ";");
}

void ClientsControl::delete_client(int id)
{
    tx.exec("DELETE from clients WHERE id = " + std::to_string(id) + ";");
}

int ClientsControl::select_client_by_first_name(const std::string& first_name)
{
    for (const auto& [id, first_name, last_name, email] : tx.query<int, std::string, std::string, std::string>
        ("SELECT id, first_name, last_name, email FROM clients\n"
         "WHERE first_name = '" + tx.esc(first_name) + "';"))
    {
        std::cout << "Id: " << id << "\nFirst name: " << first_name << "\nLast name: " << last_name << "\nEmail: " << email << "\n\n";
    }
    return tx.query_value<int>("SELECT id FROM clients WHERE first_name = '" + tx.esc(first_name) + "';");
}

int ClientsControl::select_client_by_last_name(const std::string& last_name)
{
    for (const auto& [id, first_name, last_name, email] : tx.query<int, std::string, std::string, std::string>
        ("SELECT id, first_name, last_name, email FROM clients\n"
         "WHERE last_name = '" + tx.esc(last_name) + "';"))
    {
        std::cout << "Id: " << id << "\nFirst name: " << first_name << "\nLast name: " << last_name << "\nEmail: " << email << "\n\n";
    }
    return tx.query_value<int>("SELECT id FROM clients WHERE last_name = '" + tx.esc(last_name) + "';");
}

int ClientsControl::select_client_by_email(const std::string& email)
{
    for(const auto& [id, first_name, last_name, email]: tx.query<int, std::string, std::string, std::string>
        ("SELECT id, first_name, last_name, email FROM clients "
         "WHERE email = '" + tx.esc(email) + "';"))
    {
        std::cout << "Id: " << id << "\nFirst name: " << first_name << "\nLast name: " << last_name << "\nEmail: " << email << "\n\n";
    }
    return tx.query_value<int>("SELECT id FROM clients WHERE email = '" + tx.esc(email) + "';");
}

int ClientsControl::select_client_by_phone(const std::string& phone)
{
    for (const auto& [id, first_name, last_name, email, phone]: tx.query<int, std::string, std::string, std::string, std::string>
        ("SELECT clients.id, first_name, last_name, email, phone FROM clients\n"
         "JOIN phones ON clients.id = phones.clients_id\n"
         "WHERE phone = '" + tx.esc(phone) + "';"))
    {
        std::cout << "Id: " << id << "\nFirst name: " << first_name << "\nLast name: " << last_name << "\nEmail: " << email << "\nPhone: " << phone << '\n';
    }
    return tx.query_value<int>("SELECT clients.id FROM clients JOIN phones ON clients.id = phones.clients_id WHERE phone = '" + tx.esc(phone) + "';");
}

void ClientsControl::select_all_clients()
{
    for(const auto& [id, first_name, last_name, email]: tx.query<int, std::string, std::string, std::string>
       ("SELECT * FROM clients"))
    {
        std::cout << "Id: " << id << "\nFirst name: " << first_name << "\nLast name: " << last_name << "\nEmail: " << email << "\n\n";
    }
}

void ClientsControl::select_all_phones()
{
    for (const auto& [id, phone, client_id]: tx.query<int, std::string, int>
        ("SELECT * FROM phones"))
    {
        std::cout << "Id: " << id << "\nPhone: " << phone << "\nClientId: " << client_id << "\n\n";
    }
}
