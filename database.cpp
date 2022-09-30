// beginning prompt for keeping program running and providing exit function
bool startPrompt() { 
     

    bool a = true; 
    std::string prompt;
    std::cout << "Input a command and your URL. For a list of commands, type 'help'." << std::endl;
    std::cin >> prompt;
    if (prompt == "help" || prompt == "Help") {
        help();
    }
    if (prompt == "exit" || prompt == "Exit") {
        return a = false; 
    }  
    if (prompt == "show" || prompt == "Show") {
        std::string connectionString = "host= port= dbname=ArticleDB user=postgres password=";

        // connecting to PostgreSQL database
        try
        {
            pqxx::connection connectionObject(connectionString.c_str());

            pqxx::work worker(connectionObject);


            // confirming successful connection
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