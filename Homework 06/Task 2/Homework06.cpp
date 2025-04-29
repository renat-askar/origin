#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

#include <iostream>
#include <string>

class Book;
class Shop;
class Stock;
class Sale;

class Publisher
{
	public:
		std::string name{};
		Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books{};

		template<class Action>
		void persist(Action& a)
		{
			Wt::Dbo::field(a, name, "name");
			Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
		}
};

class Book
{
	public:
		std::string title{};
		Wt::Dbo::ptr<Publisher> publisher{};
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks{};

		template<class Action>
		void persist(Action& a)
		{
			Wt::Dbo::field(a, title, "title");
			Wt::Dbo::belongsTo(a, publisher, "publisher");
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
		}
};

class Shop
{
	public:
		std::string name{};
		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks{};

		template<class Action>
		void persist(Action& a)
		{
			Wt::Dbo::field(a, name, "name");
			Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
		}
};

class Stock
{
	public:
		Wt::Dbo::ptr<Book> book{};
		Wt::Dbo::ptr<Shop> shop{};
		int count{};
		Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales{};

		template<class Action>
		void persist(Action& a)
		{
			Wt::Dbo::belongsTo(a, book, "book");
			Wt::Dbo::belongsTo(a, shop, "shop");
			Wt::Dbo::field(a, count, "count");
			Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
		}
};

class Sale
{
	public:
		int price{};
		std::string date_sale{};
		Wt::Dbo::ptr<Stock> stock{};
		int count{};

		template<class Action>
		void persist(Action& a)
		{
			Wt::Dbo::field(a, price, "price");
			Wt::Dbo::field(a, date_sale, "date_sale");
			Wt::Dbo::belongsTo(a, stock, "stock");
			Wt::Dbo::field(a, count, "count");
		}
};

int main()
{
	try
	{
		std::string connectionString =
			"host=localhost"
			" port=5432"
			" dbname=Homework06"
			" user=postgres"
			" password=12345";
		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session{};
		session.setConnection(std::move(postgres));
		
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");
		session.createTables();
		
		Wt::Dbo::Transaction transaction{session};
		
		std::unique_ptr<Publisher> publisher_1{std::make_unique<Publisher>()};
		std::unique_ptr<Publisher> publisher_2{std::make_unique<Publisher>()};
		std::unique_ptr<Publisher> publisher_3{std::make_unique<Publisher>()};
		publisher_1->name = "publisher_1";
		publisher_2->name = "publisher_2";
		publisher_3->name = "publisher_3";
		Wt::Dbo::ptr<Publisher> publisher_1_ptr{session.add(std::move(publisher_1))};
		Wt::Dbo::ptr<Publisher> publisher_2_ptr{session.add(std::move(publisher_2))};
		Wt::Dbo::ptr<Publisher> publisher_3_ptr{session.add(std::move(publisher_3))};

		std::unique_ptr<Book> book_1{std::make_unique<Book>()};
		std::unique_ptr<Book> book_2{std::make_unique<Book>()};
		std::unique_ptr<Book> book_3{std::make_unique<Book>()};
		book_1->title = "book_1";
		book_2->title = "book_2";
		book_3->title = "book_3";
		book_1->publisher = publisher_1_ptr;
		book_2->publisher = publisher_2_ptr;
		book_3->publisher = publisher_3_ptr;
		Wt::Dbo::ptr<Book> book_1_ptr{session.add(std::move(book_1))};
		Wt::Dbo::ptr<Book> book_2_ptr{session.add(std::move(book_2))};
		Wt::Dbo::ptr<Book> book_3_ptr{session.add(std::move(book_3))};

		std::unique_ptr<Shop> shop_1{std::make_unique<Shop>()};
		std::unique_ptr<Shop> shop_2{std::make_unique<Shop>()};
		std::unique_ptr<Shop> shop_3{std::make_unique<Shop>()};
		shop_1->name = "shop_1";
		shop_2->name = "shop_2";
		shop_3->name = "shop_3";
		Wt::Dbo::ptr<Shop> shop_1_ptr{session.add(std::move(shop_1))};
		Wt::Dbo::ptr<Shop> shop_2_ptr{session.add(std::move(shop_2))};
		Wt::Dbo::ptr<Shop> shop_3_ptr{session.add(std::move(shop_3))};

		std::unique_ptr<Stock> stock_1{std::make_unique<Stock>()};
		std::unique_ptr<Stock> stock_2{std::make_unique<Stock>()};
		std::unique_ptr<Stock> stock_3{std::make_unique<Stock>()};
		stock_1->book = book_1_ptr;
		stock_2->book = book_2_ptr;
		stock_3->book = book_3_ptr;
		stock_1->shop = shop_1_ptr;
		stock_2->shop = shop_2_ptr;
		stock_3->shop = shop_3_ptr;
		stock_1->count = 1;
		stock_2->count = 1;
		stock_3->count = 1;
		Wt::Dbo::ptr<Stock> stock_1_ptr{session.add(std::move(stock_1))};
		Wt::Dbo::ptr<Stock> stock_2_ptr{session.add(std::move(stock_2))};
		Wt::Dbo::ptr<Stock> stock_3_ptr{session.add(std::move(stock_3))};

		std::unique_ptr<Sale> sale_1{std::make_unique<Sale>()};
		std::unique_ptr<Sale> sale_2{std::make_unique<Sale>()};
		std::unique_ptr<Sale> sale_3{std::make_unique<Sale>()};
		sale_1->price = 100;
		sale_2->price = 200;
		sale_3->price = 300;
		sale_1->date_sale = "10";
		sale_2->date_sale = "11";
		sale_3->date_sale = "12";
		sale_1->stock = stock_1_ptr;
		sale_2->stock = stock_2_ptr;
		sale_3->stock = stock_3_ptr;
		sale_1->count = 1;
		sale_2->count = 1;
		sale_3->count = 1;
		Wt::Dbo::ptr<Sale> sale_1_ptr{session.add(std::move(sale_1))};
		Wt::Dbo::ptr<Sale> sale_2_ptr{session.add(std::move(sale_2))};
		Wt::Dbo::ptr<Sale> sale_3_ptr{session.add(std::move(sale_3))};
		
		
		int select{};
		std::cout << "Select id of publisher: ";
		std::cin >> select;

		Wt::Dbo::ptr<Publisher> publisher{session.find<Publisher>().where("id = ?").bind(select)};
		std::cout << "Publisher Id: " << publisher.id() << "\nPublisher Name: " << publisher->name << "\n\n";

		Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks{session.find<Stock>()};
		for(const auto& stock: stocks)
		{
			if(stock->book->publisher.id() == select)
			{
				std::cout << "Shop Id: " << stock->shop.id()
					<< "\nShop Name: " << stock->shop->name
					<< "\nPublisher Id: " << stock->book->publisher.id() << "\n\n";
			}
		}
		transaction.commit();
	}
	catch(const Wt::Dbo::Exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
