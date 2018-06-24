#include <iostream>
#include <random>

#include <boost/asio.hpp>

#include "random_generator.h"
#include "log_tools.h"
#include "json_commands.h"
#include "engine.h"
#include "basic_selectors.h"

using boost::asio::ip::tcp;

int main(int argc, char **argv){
    int PORT = 1024;
    int seed;
    if(argc==2){
      seed=atoi(argv[1]);
    }
    else{
      std::random_device rd;
      seed=rd();
    }
    try
    {
	boost::asio::io_service io_service;

	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), PORT));

	std::unique_ptr<RandomGenerator> generator(new RandomGenerator(4,3,2,seed));
	Engine engine(std::move(generator));
	engine.AddSelector(std::unique_ptr<Selector>(new Closest()));
	engine.AddSelector(std::unique_ptr<Selector>(new Closest()));

	print_cities(engine.GetCities());
	for (;;)
	{
	    tcp::socket socket(io_service);

	    std::cout << "Wating for socket" << std::endl;
	    // wait and listen
	    acceptor.accept(socket);
	    std::cout << "Socket recieved" << std::endl;

	    // prepare message to send back to client
	    boost::asio::streambuf sb;

	    boost::system::error_code ignored_error;
            boost::system::error_code error_code;
            std::vector<char> buf(65536);
            int len = socket.read_some(boost::asio::buffer(buf), error_code);
            std::string content(buf.begin(), buf.end());

	    if(len > 0){
                std::cout << "Content: " << content << std::endl;
		std::string response = "";
		if(content.find("generate_map") == 0){
		  engine.GenerateNewMap();
		  response = NewMapGeneratedResponse(engine.GetMap());

		} else if(content.find("perform_turn") == 0){
		  if(engine.PerformTurnSecure()){
		    response = TurnPerformedResponse(engine);
		  }else {
		    response = NoActionResponse("no turn performed");
		  }
		}
		else{
		  response = UnknownCommandResponse(content);
		}
		std::cout << "Response: " << response << std::endl;
                boost::asio::write(socket, boost::asio::buffer(response, response.size()), ignored_error);
	    }

        }
    }
    catch (std::exception& e)
    {
	std::cerr << "ERROR: " << e.what() << std::endl;
    }
  return 0;
}
