#include "../Public/SendMessageUploadAudioAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadAudioAction::SendMessageUploadAudioAction()
{
	this->_ConstructorID = -212740181;
}

SendMessageUploadAudioAction::SendMessageUploadAudioAction(int32 progress)
{
	this->_ConstructorID = -212740181;
	this->progress = progress;
}
void SendMessageUploadAudioAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->progress);
}


void SendMessageUploadAudioAction::OnResponce(BinaryReader& Reader)
{
	progress = Reader.ReadInt();
	this->_Responded = true;
}
SendMessageUploadAudioAction::~SendMessageUploadAudioAction()
{
}
}//end namespace block
