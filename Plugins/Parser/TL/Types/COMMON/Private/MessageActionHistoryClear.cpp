#include "../Public/MessageActionHistoryClear.h"


//begin namespace block
namespace COMMON
{

MessageActionHistoryClear::MessageActionHistoryClear()
{
	this->_ConstructorID = 79084191;
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
}
MessageActionHistoryClear::~MessageActionHistoryClear()
{

}
}//end namespace block
