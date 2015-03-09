#include <ConsumptionAction.hxx>

#include <World.hxx>
#include <Province.hxx>

#include <Logger.hxx>

namespace Epnet
{

ConsumptionAction::ConsumptionAction()
{
}

ConsumptionAction::~ConsumptionAction()
{
}

void ConsumptionAction::execute(Engine::Agent& agent)
{
	Roman & romanAgent = (Roman&)agent;
	Engine::World * world = agent.getWorld();
	Province & provinceWorld = (Province&) *world;
	
	
	std::vector< std::tuple< std::string, double, double, double, double, double > > allGood= romanAgent.getListGoods();
	std::vector< std::tuple< std::string, double, double, double, double, double > >::iterator it = allGood.begin();
	int utilityFunction=1;
//	it++;//skip money ou plus
	while(it!=allGood.end())
	{
	    std::string good=std::get<0>(*it);
	  if(good == std::get<0>(romanAgent.getProducedGood()) && romanAgent.getQuantity(good) == 0)
	    romanAgent.setQuantity(good,1);
	  if(utilityFunction> romanAgent.getQuantity(good)/romanAgent.getNeed(good))
			utilityFunction=romanAgent.getQuantity(good)/romanAgent.getNeed(good);
	  it++;
	  romanAgent.setQuantity(good,0.0);
	  
	}
	
	double score=romanAgent.getScore();
	romanAgent.setScore(score+utilityFunction);


}

std::string ConsumptionAction::describe() const
{
	return "Consumption action";
}

} // namespace Epnet


