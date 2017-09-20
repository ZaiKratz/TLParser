#include "../Public/SendMessageUploadAudioAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadAudioAction::SendMessageUploadAudioAction()
{
	this->_ConstructorID = -1411952141;
}

SendMessageUploadAudioAction::SendMessageUploadAudioAction(int32 progress)
{
	this->_ConstructorID = -1411952141;
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
}
SendMessageUploadAudioAction::~SendMessageUploadAudioAction()
{

}
}//end namespace block
