#pragma once
#include "../Agent/Agent.h"
#include <log4cplus/logger.h>


namespace chilli{
namespace Avaya{

class TSAPIModule;
class AvayaAgent :public Agent::Agent{
public:
	AvayaAgent(TSAPIModule * model, const std::string &ext, const std::string &smFileName);
	virtual ~AvayaAgent();

public:

	//inherit from SendInterface
	virtual void fireSend(const fsm::FireDataType &fireData, const void * param) override;
protected:
	void processSend(const fsm::FireDataType &fireData, const void * param, bool & bHandled);

private:
	TSAPIModule * m_model = nullptr;
};
typedef std::shared_ptr<AvayaAgent>  AvayaAgentPtr;
}
}