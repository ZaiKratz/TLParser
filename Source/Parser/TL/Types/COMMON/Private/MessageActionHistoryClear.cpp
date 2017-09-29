#include "../Public/MessageActionHistoryClear.h"


//begin namespace block
namespace COMMON
{

MessageActionHistoryClear::MessageActionHistoryClear()
{
	this->_ConstructorID = -1615153660;
}
void MessageActionHistoryClear::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void MessageActionHistoryClear::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
MessageActionHistoryClear::~MessageActionHistoryClear()
{

}
}//end namespace block
