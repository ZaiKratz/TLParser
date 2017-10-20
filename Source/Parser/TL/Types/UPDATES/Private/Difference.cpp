#include "../Public/Difference.h"


//begin namespace block
namespace UPDATES
{

Difference::Difference()
{
	this->_ConstructorID = 16030880;
}

Difference::Difference(TArray<COMMON::Message*>  new_messages, TArray<COMMON::EncryptedMessage*>  new_encrypted_messages, TArray<TLBaseObject*>  other_updates, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users, UPDATES::State*  state)
{
	this->_ConstructorID = 16030880;
	this->new_messages = new_messages;
	this->new_encrypted_messages = new_encrypted_messages;
	this->other_updates = other_updates;
	this->chats = chats;
	this->users = users;
	this->state = state;
}
void Difference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->new_messages.Num());
	for(auto X : this->new_messages)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->new_encrypted_messages.Num());
	for(auto X : this->new_encrypted_messages)
	{
	X->OnSend(Writer);
	}
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->other_updates.Num());
	for(auto X : this->other_updates)
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


void Difference::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len15582 = Reader.ReadInt();
	for(int32 i = 0; i < Len15582; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	new_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len28821 = Reader.ReadInt();
	for(int32 i = 0; i < Len28821; i++)
	{
	auto X = reinterpret_cast<COMMON::EncryptedMessage*>(Reader.TGReadObject());
	new_encrypted_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len15337 = Reader.ReadInt();
	for(int32 i = 0; i < Len15337; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	other_updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len16375 = Reader.ReadInt();
	for(int32 i = 0; i < Len16375; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len30049 = Reader.ReadInt();
	for(int32 i = 0; i < Len30049; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	state = reinterpret_cast<UPDATES::State* >(Reader.TGReadObject());
	this->_Responded = true;
}
Difference::~Difference()
{
	if(this->state)
	{
		delete this->state;
	}
}
}//end namespace block
