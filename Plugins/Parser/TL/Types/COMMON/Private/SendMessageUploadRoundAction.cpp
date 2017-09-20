#include "../Public/SendMessageUploadRoundAction.h"


//begin namespace block
namespace COMMON
{

SendMessageUploadRoundAction::SendMessageUploadRoundAction()
{
	this->_ConstructorID = 1713126948;
}

SendMessageUploadRoundAction::SendMessageUploadRoundAction(int32 progress)
{
	this->_ConstructorID = 1713126948;
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
}
SendMessageUploadRoundAction::~SendMessageUploadRoundAction()
{

}
}//end namespace block
