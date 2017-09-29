#include "../Public/Dialogs.h"


//begin namespace block
namespace MESSAGES
{

Dialogs::Dialogs()
{
	this->_ConstructorID = 364538944;
}

Dialogs::Dialogs(TArray<COMMON::Dialog*>  dialogs, TArray<COMMON::Message*>  messages, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users)
{
	this->_ConstructorID = 364538944;
	this->dialogs = dialogs;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
}
void Dialogs::OnSend(BinaryWriter& Writer)
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
}


void Dialogs::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len386 = Reader.ReadInt();
	for(int32 i = 0; i < Len386; i++)
	{
	auto X = reinterpret_cast<COMMON::Dialog*>(Reader.TGReadObject());
	dialogs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17282 = Reader.ReadInt();
	for(int32 i = 0; i < Len17282; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5191 = Reader.ReadInt();
	for(int32 i = 0; i < Len5191; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26718 = Reader.ReadInt();
	for(int32 i = 0; i < Len26718; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	this->_Responded = true;
}
Dialogs::~Dialogs()
{

}
}//end namespace block
