#include "../Public/GetChats.h"


//begin namespace block
namespace MESSAGES
{

GetChats::GetChats()
{
	this->_ConstructorID = -2019464644;
	this->_ContentRelated = true;
}

GetChats::GetChats(TArray<int32> id)
{
	this->_ConstructorID = -2019464644;
	this->_ContentRelated = true;
	this->id = id;
}
void GetChats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
}


void GetChats::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
}
GetChats::~GetChats()
{

}
}//end namespace block
