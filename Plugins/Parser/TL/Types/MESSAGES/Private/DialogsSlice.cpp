#include "../Public/DialogsSlice.h"


//begin namespace block
namespace MESSAGES
{

DialogsSlice::DialogsSlice()
{
	this->_ConstructorID = -208347023;
}

DialogsSlice::DialogsSlice(int32 count, TArray<COMMON::Dialog*> dialogs, TArray<COMMON::Message*> messages, TArray<COMMON::Chat*> chats, TArray<COMMON::User*> users)
{
	this->_ConstructorID = -208347023;
	this->count = count;
	this->dialogs = dialogs;
	this->messages = messages;
	this->chats = chats;
	this->users = users;
}
void DialogsSlice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
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


void DialogsSlice::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len25593 = Reader.ReadInt();
	for(int32 i = 0; i < Len25593; i++)
	{
	auto X = reinterpret_cast<COMMON::Dialog*>(Reader.TGReadObject());
	dialogs.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len26231 = Reader.ReadInt();
	for(int32 i = 0; i < Len26231; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len27435 = Reader.ReadInt();
	for(int32 i = 0; i < Len27435; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len2039 = Reader.ReadInt();
	for(int32 i = 0; i < Len2039; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
}
DialogsSlice::~DialogsSlice()
{

}
}//end namespace block
