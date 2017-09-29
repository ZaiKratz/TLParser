#include "../Public/AdminLogResults.h"


//begin namespace block
namespace CHANNELS
{

AdminLogResults::AdminLogResults()
{
	this->_ConstructorID = -309659827;
}

AdminLogResults::AdminLogResults(TArray<COMMON::ChannelAdminLogEvent*>  events, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = -309659827;
	this->events = events;
	this->chats = chats;
	this->users = users;
}
void AdminLogResults::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->events.Num());
	for(auto X : this->events)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->chats.Num());
	for(auto X : this->chats)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
}


void AdminLogResults::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len112 = Reader.ReadInt();
	for(int32 i = 0; i < Len112; i++)
	{
	auto X = reinterpret_cast<COMMON::ChannelAdminLogEvent*>(Reader.TGReadObject());
	events.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16754 = Reader.ReadInt();
	for(int32 i = 0; i < Len16754; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26716 = Reader.ReadInt();
	for(int32 i = 0; i < Len26716; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
AdminLogResults::~AdminLogResults()
{

}
}//end namespace block
