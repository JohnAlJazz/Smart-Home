# h71.prj.BurjKhalifa

# Smart home simulator

![alt text](https://t3.ftcdn.net/jpg/01/62/71/72/240_F_162717288_H9gde7vwbfrChJLwImFz5j9QeMfPoRuv.jpg)

This project simulates a smart home. It includes sensors
which send event requests over tcp network using protocol, agents drivers which translate the
request, create a new event and send it to the controllers.
Beside the server application, there is an online logger app UI written in order to show the
loggers, and to give the user the opportunity to monitor the requests and sort them by priority.

## some features and technologies we are proud of:

* multi threaded server app written in c++
* tcp networking and an epoll monitoring descriptors
* threads safe data structures
* two data bases => sql and mongo db
* web technology stacks based on React & Node.Js

# Getting Started

## dependencies

* after cloning the project, you can install all the project dependencies as follows:

Note !

In case you are using ubuntu 22.04 and above, you should download mongodb, the

makefile could not do that for you, please checkout the official website:

* [mondodb official website](https://www.mongodb.com/cloud/atlas/lp/try4?utm_content=rlsavisitor&utm_source=google&utm_campaign=search_gs_pl_evergreen_atlas_core_retarget-brand_gic-null_emea-all_ps-all_desktop_eng_lead&utm_term=mongodb&utm_medium=cpc_paid_search&utm_ad=e&utm_ad_campaign_id=14412646455&adgroup=131761126492&gclid=CjwKCAiA68ebBhB-EiwALVC-NmpJajYzyGTx6O3KQV6iHOJ61WXWbL0TLsLvinUE25GRX-Z2TfDt9RoC6gwQAvD_BwE)

### command :

```bash
make prep
```
## server

* you can run the server by copying the link below, by running this command, 4 terminals are goint to be opened:
1. server terminal
2. Node.Js server terminal
3. React terminal(should open the online UI web application on your browser)
4. mongodb terminal

### command :
```bash
make runserver
```

## sensors:
* you can run the sensors demo by pressing the command below, at the end of this page there is an example of the main function that runs the program.

# important !!

## before running sensors, wait until the server is set up, it might take some time !! 

## command
```bash
make runsensors
```

## examples

### configure your app with .ini file as shown in server_app dir and run your server quickly

### example of server setup:

```cpp
#include <memory>

#include "app_server.hpp"
#include "config_streams.hpp"
#include "agent_creator_factory.hpp"

int main()
{
    std::string serverConfigPath{"server.config"};
    std::string sensorAgentsConfig{"sensor_agents.ini"};    
    
    std::ifstream serverConfig(serverConfigPath);

    auto agentsFactory = std::make_shared<agentsFactory::AgentsFactory>(sensorAgentsConfig);
    server::AppServer server{serverConfig, agentsFactory};

    server.Run();
    
    return 0;
}

```

### you can easily create a new agent factory and inject to your own server as shown in agents_factory such as:
```cpp

AgentsFactory::AgentsMapPtr AgentsFactory::GenerateAgentsMap(device::AppDB a_dataBase) 
{    
    AgentMap agentsMap;
    device::DeviceConfigParser parser;
    std::map<uint32_t,fun_ptr>sensorDecider = AgentDecidor();

    device::DeviceTranslator translator;

    while (!m_configFile.eof()) {    
        device::DeviceDetails device = GenerateDevice(m_configFile, parser);
        auto deviceId = device.DeviceId();
        uint32_t key = translator.translate(deviceId);
        fun_ptr func = sensorDecider[key];
        agentsMap[device.DeviceId()] = func(device);
        a_dataBase.InsertDevice(device.DeviceId());
    }
    
    return std::make_shared<AgentMap>(agentsMap);
}
```

### example of how sensors communicate with the server:

```cpp
#include <thread>

#include "temperature_sensor.hpp"
#include "badge_sensor.hpp"
#include "motion_sensor.hpp"

int main()
{
    std::string typeTemp {"temperature_1_a_1"};
    std::string typeBadge {"badge_sensor"};
    std::string typeMotion {"motion_sensor"};

    const char *ip = "127.0.0.1";

    uint16_t port = 8080;

    std::thread temperature([&typeTemp](){sensors::TemperatureSensor temperatureSensor(ip, port,
    typeTemp);
    temperatureSensor.Send();});

    std::thread badge([&typeBadge](){sensors::BadgeSensor badgeSensor(ip,port,
    typeBadge);
    badgeSensor.Send();});

    std::thread motion([&typeMotion](){sensors::MotionSensor motionSensor(ip, port, typeMotion);
    motionSensor.Send();});

    temperature.join();
    badge.join();
    motion.join();
    
    return 0;
}

```
