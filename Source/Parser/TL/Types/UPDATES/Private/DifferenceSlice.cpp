#include "../Public/DifferenceSlice.h"


//begin namespace block
namespace UPDATES
{

DifferenceSlice::DifferenceSlice()
{
	this->_ConstructorID = -1459938943;
}

DifferenceSlice::DifferenceSlice(TArray<COMMON::Message*>  new_messages, TArray<COMMON::EncryptedMessage*>  new_encrypted_messages, TArray<TLBaseObject*>  other_updates, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users, UPDATES::State*  intermediate_state)
{
	this->_ConstructorID = -1459938943;
	this->new_messages = new_messages;
	this->new_encrypted_messages = new_encrypted_messages;
	this->other_updates = other_updates;
	this->chats = chats;
	this->users = users;
	this->intermediate_state = intermediate_state;
}
void DifferenceSlice::OnSend(BinaryWriter& Writer)
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
	this->intermediate_state->OnSend(Writer);
}


void DifferenceSlice::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len30036 = Reader.ReadInt();
	for(int32 i = 0; i < Len30036; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	new_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9747 = Reader.ReadInt();
	for(int32 i = 0; i < Len9747; i++)
	{
	auto X = reinterpret_cast<COMMON::EncryptedMessage*>(Reader.TGReadObject());
	new_encrypted_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len3710 = Reader.ReadInt();
	for(int32 i = 0; i < Len3710; i++)
	{
	auto X = reinterpret_cast<TLBaseObject*>(Reader.TGReadObject());
	other_updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len32761 = Reader.ReadInt();
	for(int32 i = 0; i < Len32761; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len6981 = Reader.ReadInt();
	for(int32 i = 0; i < Len6981; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	intermediate_state = reinterpret_cast<UPDATES::State* >(Reader.TGReadObject());
	this->_Responded = true;
}
DifferenceSlice::~DifferenceSlice()
{
	if(this->intermediate_state)
	{
		delete this->intermediate_state;
	}
}
}//end namespace block
