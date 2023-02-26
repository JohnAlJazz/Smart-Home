#include "json_web_updator.hpp"

#include "event.hpp"

#include <string>

#include <iostream>

int main(int argc, char ** argv)
{

    if (argc < 5) {
        std::cout << "type location payload time";
    }
    

    std::string jsonFileName = "../../web_app/src/web_app_logs.json";
    web::JsonWebUpdator json{jsonFileName};

    event::Event event{argv[1],argv[2],argv[3],argv[4],1};
    
    json.UpdateJsonFile(event);

    return 0;
}