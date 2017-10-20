#include "../Public/GetChannels.h"


//begin namespace block
namespace CHANNELS
{

GetChannels::GetChannels()
{
	this->_ConstructorID = 176122811;
	this->_ContentRelated = true;
}

GetChannels::GetChannels(TArray<COMMON::InputChannel*>  id)
{
	this->_ConstructorID = 176122811;
	this->_ContentRelated = true;
	this->id = id;
}
void GetChannels::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	X->OnSend(Writer);
	}
}


void GetChannels::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::Chats*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetChannels::~GetChannels()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
