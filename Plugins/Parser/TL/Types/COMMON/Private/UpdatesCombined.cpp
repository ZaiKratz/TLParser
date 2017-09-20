#include "../Public/UpdatesCombined.h"


//begin namespace block
namespace COMMON
{

UpdatesCombined::UpdatesCombined()
{
	this->_ConstructorID = -1023124622;
}

UpdatesCombined::UpdatesCombined(TArray<PRIVATE::Update*> updates, TArray<COMMON::User*> users, TArray<COMMON::Chat*> chats, FDateTime date, int32 seq_start, int32 seq)
{
	this->_ConstructorID = -1023124622;
	this->updates = updates;
	this->users = users;
	this->chats = chats;
	this->date = date;
	this->seq_start = seq_start;
	this->seq = seq;
}
void UpdatesCombined::OnSend(BinaryWriter& Writer)
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
	Writer.WriteInt(this->seq_start);
	Writer.WriteInt(this->seq);
}


void UpdatesCombined::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len2538 = Reader.ReadInt();
	for(int32 i = 0; i < Len2538; i++)
	{
	auto X = reinterpret_cast<PRIVATE::Update*>(Reader.TGReadObject());
	updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len31784 = Reader.ReadInt();
	for(int32 i = 0; i < Len31784; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5098 = Reader.ReadInt();
	for(int32 i = 0; i < Len5098; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	date = Reader.TGReadDate();
	seq_start = Reader.ReadInt();
	seq = Reader.ReadInt();
}
UpdatesCombined::~UpdatesCombined()
{

}
}//end namespace block
