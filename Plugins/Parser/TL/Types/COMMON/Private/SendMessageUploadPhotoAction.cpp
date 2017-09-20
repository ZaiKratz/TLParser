#include "../Public/SendMessageUploadPhotoAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadPhotoAction::SendMessageUploadPhotoAction()
{
	this->_ConstructorID = 642438097;
}

SendMessageUploadPhotoAction::SendMessageUploadPhotoAction(int32 progress)
{
	this->_ConstructorID = 642438097;
	this->progress = progress;
}
void SendMessageUploadPhotoAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->progress);
}


void SendMessageUploadPhotoAction::OnResponce(BinaryReader& Reader)
{
	progress = Reader.ReadInt();
}
SendMessageUploadPhotoAction::~SendMessageUploadPhotoAction()
{

}
}//end namespace block
