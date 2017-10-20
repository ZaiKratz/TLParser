#include "../Public/UpdateUserTyping.h"


//begin namespace block
namespace COMMON
{

UpdateUserTyping::UpdateUserTyping()
{
	this->_ConstructorID = 1548249383;
}

UpdateUserTyping::UpdateUserTyping(int32 user_id, TLBaseObject*  action)
{
	this->_ConstructorID = 1548249383;
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
	action = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
UpdateUserTyping::~UpdateUserTyping()
{
	if(this->action)
	{
		delete this->action;
	}
}
}//end namespace block
