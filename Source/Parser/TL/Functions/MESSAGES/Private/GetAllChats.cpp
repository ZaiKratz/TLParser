#include "../Public/GetAllChats.h"


//begin namespace block
namespace MESSAGES
{

GetAllChats::GetAllChats()
{
	this->_ConstructorID = -341307408;
	this->_ContentRelated = true;
}

GetAllChats::GetAllChats(TArray<int32>  except_ids)
{
	this->_ConstructorID = -341307408;
	this->_ContentRelated = true;
	this->except_ids = except_ids;
}
void GetAllChats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->except_ids.Num());
	for(auto X : this->except_ids)
	{
	Writer.WriteInt(X);
	}
}


void GetAllChats::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetAllChats::~GetAllChats()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
