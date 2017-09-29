#include "../Public/GetCommonChats.h"


//begin namespace block
namespace MESSAGES
{

GetCommonChats::GetCommonChats()
{
	this->_ConstructorID = 218777796;
	this->_ContentRelated = true;
}

GetCommonChats::GetCommonChats(COMMON::InputUser*  user_id, int32 max_id, int32 limit)
{
	this->_ConstructorID = 218777796;
	this->_ContentRelated = true;
	this->user_id = user_id;
	this->max_id = max_id;
	this->limit = limit;
}
void GetCommonChats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->user_id->OnSend(Writer);
	Writer.WriteInt(this->max_id);
	Writer.WriteInt(this->limit);
}


void GetCommonChats::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetCommonChats::~GetCommonChats()
{

}
}//end namespace block
