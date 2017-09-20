#include "../Public/SendMessageRecordVideoAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordVideoAction::SendMessageRecordVideoAction()
{
	this->_ConstructorID = 1876330401;
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
}
SendMessageRecordVideoAction::~SendMessageRecordVideoAction()
{

}
}//end namespace block
