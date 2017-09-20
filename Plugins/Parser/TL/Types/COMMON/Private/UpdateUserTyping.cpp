#include "../Public/UpdateUserTyping.h"


//begin namespace block
namespace COMMON
{

UpdateUserTyping::UpdateUserTyping()
{
	this->_ConstructorID = 661211228;
}

UpdateUserTyping::UpdateUserTyping(int32 user_id, PRIVATE::SendMessageAction* action)
{
	this->_ConstructorID = 661211228;
	this->user_id = user_id;
	this->action = action;
}
void UpdateUserTyping::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	this->action->OnSend(Writer);
}


void UpdateUserTyping::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	action = reinterpret_cast<PRIVATE::SendMessageAction*>(Reader.TGReadObject());
}
UpdateUserTyping::~UpdateUserTyping()
{

}
}//end namespace block
