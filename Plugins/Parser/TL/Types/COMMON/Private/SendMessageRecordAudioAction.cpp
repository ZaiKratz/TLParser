#include "../Public/SendMessageRecordAudioAction.h"


//begin namespace block
namespace COMMON
{

SendMessageRecordAudioAction::SendMessageRecordAudioAction()
{
	this->_ConstructorID = -143446059;
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
}
SendMessageRecordAudioAction::~SendMessageRecordAudioAction()
{

}
}//end namespace block
