#include "../Public/SendMessageUploadVideoAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadVideoAction::SendMessageUploadVideoAction()
{
	this->_ConstructorID = -378127636;
}

SendMessageUploadVideoAction::SendMessageUploadVideoAction(int32 progress)
{
	this->_ConstructorID = -378127636;
	this->progress = progress;
}
void SendMessageUploadVideoAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->progress);
}


void SendMessageUploadVideoAction::OnResponce(BinaryReader& Reader)
{
	progress = Reader.ReadInt();
	this->_Responded = true;
}
SendMessageUploadVideoAction::~SendMessageUploadVideoAction()
{
}
}//end namespace block
