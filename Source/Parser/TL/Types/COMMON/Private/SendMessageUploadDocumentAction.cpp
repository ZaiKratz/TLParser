#include "../Public/SendMessageUploadDocumentAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadDocumentAction::SendMessageUploadDocumentAction()
{
	this->_ConstructorID = -1441998364;
}

SendMessageUploadDocumentAction::SendMessageUploadDocumentAction(int32 progress)
{
	this->_ConstructorID = -1441998364;
	this->progress = progress;
}
void SendMessageUploadDocumentAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->progress);
}


void SendMessageUploadDocumentAction::OnResponce(BinaryReader& Reader)
{
	progress = Reader.ReadInt();
	this->_Responded = true;
}
SendMessageUploadDocumentAction::~SendMessageUploadDocumentAction()
{

}
}//end namespace block
