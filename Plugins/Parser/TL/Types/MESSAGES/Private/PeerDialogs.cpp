#include "../Public/PeerDialogs.h"


//begin namespace block
namespace MESSAGES
{

PeerDialogs::PeerDialogs()
{
	this->_ConstructorID = 1422094643;
}

PeerDialogs::PeerDialogs(TArray<COMMON::Dialog*> dialogs, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users, UPDATES::State* state)
{
	this->_ConstructorID = 1422094643;
	this->dialogs = dialogs;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
	this->state = state;
}
void PeerDialogs::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->dialogs.Num());
	for(auto X : this->dialogs)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->messages.Num());
	for(auto X : this->messages)
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
	this->state->OnSend(Writer);
}


void PeerDialogs::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len31029 = Reader.ReadInt();
	for(int32 i = 0; i < Len31029; i++)
	{
	auto X = reinterpret_cast<COMMON::Dialog*>(Reader.TGReadObject());
	dialogs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7762 = Reader.ReadInt();
	for(int32 i = 0; i < Len7762; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21420 = Reader.ReadInt();
	for(int32 i = 0; i < Len21420; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14839 = Reader.ReadInt();
	for(int32 i = 0; i < Len14839; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	state = reinterpret_cast<UPDATES::State*>(Reader.TGReadObject());
}
PeerDialogs::~PeerDialogs()
{

}
}//end namespace block
