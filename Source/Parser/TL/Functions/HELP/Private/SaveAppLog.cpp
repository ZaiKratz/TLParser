#include "../Public/SaveAppLog.h"


//begin namespace block
namespace HELP
{

SaveAppLog::SaveAppLog()
{
	this->_ConstructorID = 1862465352;
	this->_ContentRelated = true;
}

SaveAppLog::SaveAppLog(TArray<COMMON::InputAppEvent*>  events)
{
	this->_ConstructorID = 1862465352;
	this->_ContentRelated = true;
	this->events = events;
}
void SaveAppLog::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->events.Num());
	for(auto X : this->events)
	{
	X->OnSend(Writer);
	}
}


void SaveAppLog::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveAppLog::~SaveAppLog()
{
}
}//end namespace block
