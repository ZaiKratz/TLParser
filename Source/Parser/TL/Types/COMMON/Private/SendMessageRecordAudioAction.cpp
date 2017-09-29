#include "../Public/SendMessageRecordAudioAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordAudioAction::SendMessageRecordAudioAction()
{
	this->_ConstructorID = -718310409;
}
void SendMessageRecordAudioAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void SendMessageRecordAudioAction::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
SendMessageRecordAudioAction::~SendMessageRecordAudioAction()
{

}
}//end namespace block
