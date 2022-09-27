#include <iostream>
#include <string>
#include <stdlib.h>
#include <pqxx/pqxx>



void help() {

    std::cout << "Here is a list of commands:" << std::endl << "1: add (URL)" << std::endl << "2: remove (URL)" << std::endl << "3: show (URL)" << std::endl << "4: exit" << std::endl;
}


// beginning prompt for keeping program running and providing exit function
bool startPrompt() { 
     

    bool a = true; 
    std::string prompt;
    std::cout << "Input a command and your URL. For a list of commands, type 'help'." << std::endl;
    std::cin >> prompt;
    if (prompt == "help") {
        help();
    }
    if (prompt == "exit") {
        return a = false;
    }  
    if (prompt == "show") {
        std::string connectionString = "host= port= dbname=ArticleDB user=postgres password=";

        // connecting to PostgreSQL database
        try
        {
            pqxx::connection connectionObject(connectionString.c_str());

            pqxx::work worker(connectionObject);

            pqxx::result response = worker.exec("SELECT * FROM public.articles");

            for (size_t i = 0; i < response.size(); i++)
            {
                std::cout << "URL: " << response[i][0] << std::endl;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        system("pause");
    }
    

   

    return a;



}

int main() {

    
    while (startPrompt() == true) {
        startPrompt();
       
    }
}
