#include "../Public/SendMessageUploadRoundAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadRoundAction::SendMessageUploadRoundAction()
{
	this->_ConstructorID = 608050278;
}

SendMessageUploadRoundAction::SendMessageUploadRoundAction(int32 progress)
{
	this->_ConstructorID = 608050278;
	this->progress = progress;
}
void SendMessageUploadRoundAction::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->progress);
}


void SendMessageUploadRoundAction::OnResponce(BinaryReader& Reader)
{
	progress = Reader.ReadInt();
	this->_Responded = true;
}
SendMessageUploadRoundAction::~SendMessageUploadRoundAction()
{

}
}//end namespace block
