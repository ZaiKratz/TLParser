#include "../Public/SendMessageRecordVideoAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordVideoAction::SendMessageRecordVideoAction()
{
	this->_ConstructorID = -1584933265;
}
void SendMessageRecordVideoAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageRecordVideoAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageRecordVideoAction::~SendMessageRecordVideoAction()
{
}
}//end namespace block
