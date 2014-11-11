
#ifndef __EatAction_hxx__
#define __EatAction_hxx__

#include <Action.hxx>
#include <string>

namespace Engine
{
	class Agent;
}

namespace Epnet
{

class EatAction : public Engine::Action
{
public:
	EatAction();
	virtual ~EatAction();
	void execute( Engine::Agent & agent );
	std::string describe() const;
};

} // namespace Epnet

#endif // __EatAction_hxx__

