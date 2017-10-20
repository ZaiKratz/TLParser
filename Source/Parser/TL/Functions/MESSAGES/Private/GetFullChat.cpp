#include "../Public/GetFullChat.h"


//begin namespace block
namespace MESSAGES
{

GetFullChat::GetFullChat()
{
	this->_ConstructorID = 998448230;
	this->_ContentRelated = true;
}

GetFullChat::GetFullChat(int32 chat_id)
{
	this->_ConstructorID = 998448230;
	this->_ContentRelated = true;
	this->chat_id = chat_id;
}
void GetFullChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->chat_id);
}


void GetFullChat::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::ChatFull*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetFullChat::~GetFullChat()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
