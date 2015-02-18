#ifndef __ControllerFactory_hxx__
#define __ControllerFactory_hxx__

#include <AgentController.hxx>
#include <string>

namespace Epnet
{

class ControllerFactory
{
private:
	Roman* _agent;
	static ControllerFactory* _instance;
	
public:
	ControllerFactory();
	virtual ~ControllerFactory();

	static ControllerFactory& get();
	AgentController* makeController(const std::string &controllerName);
	
};

} // namespace Epnet

#endif // __ControllerFactory_hxx__
