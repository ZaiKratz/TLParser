#include "../Public/Updates.h"


//begin namespace block
namespace COMMON
{

Updates::Updates()
{
	this->_ConstructorID = 1957577280;
}

Updates::Updates(TArray<PRIVATE::Update*>  updates, TArray<COMMON::User*>  users, TArray<COMMON::Chat*>  chats, FDateTime date, int32 seq)
{
	this->_ConstructorID = 1957577280;
	this->updates = updates;
	this->users = users;
	this->chats = chats;
	this->date = date;
	this->seq = seq;
}
void Updates::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->updates.Num());
	for(auto X : this->updates)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->chats.Num());
	for(auto X : this->chats)
	{
	X->OnSend(Writer);
	}
	Writer.TGWriteDate(this->date);
	Writer.WriteInt(this->seq);
}


void Updates::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len32327 = Reader.ReadInt();
	for(int32 i = 0; i < Len32327; i++)
	{
	auto X = reinterpret_cast<PRIVATE::Update*>(Reader.TGReadObject());
	updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6238 = Reader.ReadInt();
	for(int32 i = 0; i < Len6238; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len2211 = Reader.ReadInt();
	for(int32 i = 0; i < Len2211; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	date = Reader.TGReadDate();
	seq = Reader.ReadInt();
	this->_Responded = true;
}
Updates::~Updates()
{

}
}//end namespace block
