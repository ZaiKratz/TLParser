#include "../Public/Dialogs.h"


//begin namespace block
namespace MESSAGES
{

Dialogs::Dialogs()
{
	this->_ConstructorID = 1080867349;
}

Dialogs::Dialogs(TArray<COMMON::Dialog*> dialogs, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users)
{
	this->_ConstructorID = 1080867349;
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
	int32 Len9814 = Reader.ReadInt();
	for(int32 i = 0; i < Len9814; i++)
	{
	auto X = reinterpret_cast<COMMON::Dialog*>(Reader.TGReadObject());
	dialogs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len15367 = Reader.ReadInt();
	for(int32 i = 0; i < Len15367; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len3398 = Reader.ReadInt();
	for(int32 i = 0; i < Len3398; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len20230 = Reader.ReadInt();
	for(int32 i = 0; i < Len20230; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
Dialogs::~Dialogs()
{

}
}//end namespace block
