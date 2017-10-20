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
	int32 Len11984 = Reader.ReadInt();
	for(int32 i = 0; i < Len11984; i++)
	{
	auto X = reinterpret_cast<COMMON::ChannelAdminLogEvent*>(Reader.TGReadObject());
	events.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6392 = Reader.ReadInt();
	for(int32 i = 0; i < Len6392; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len10249 = Reader.ReadInt();
	for(int32 i = 0; i < Len10249; i++)
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
