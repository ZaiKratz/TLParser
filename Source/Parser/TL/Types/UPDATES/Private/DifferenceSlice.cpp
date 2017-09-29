#include "../Public/DifferenceSlice.h"


//begin namespace block
namespace UPDATES
{

DifferenceSlice::DifferenceSlice()
{
	this->_ConstructorID = -1459938943;
}

DifferenceSlice::DifferenceSlice(TArray<COMMON::Message*>  new_messages, TArray<COMMON::EncryptedMessage*>  new_encrypted_messages, TArray<PRIVATE::Update*>  other_updates, TArray<COMMON::Chat*>  chats, TArray<COMMON::User*>  users, UPDATES::State*  intermediate_state)
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
	int32 Len31132 = Reader.ReadInt();
	for(int32 i = 0; i < Len31132; i++)
	{
	auto X = reinterpret_cast<COMMON::Message*>(Reader.TGReadObject());
	new_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21188 = Reader.ReadInt();
	for(int32 i = 0; i < Len21188; i++)
	{
	auto X = reinterpret_cast<COMMON::EncryptedMessage*>(Reader.TGReadObject());
	new_encrypted_messages.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len21668 = Reader.ReadInt();
	for(int32 i = 0; i < Len21668; i++)
	{
	auto X = reinterpret_cast<PRIVATE::Update*>(Reader.TGReadObject());
	other_updates.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7791 = Reader.ReadInt();
	for(int32 i = 0; i < Len7791; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len11388 = Reader.ReadInt();
	for(int32 i = 0; i < Len11388; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	users.Add(X);
	}
	intermediate_state = reinterpret_cast<UPDATES::State* >(Reader.TGReadObject());
	this->_Responded = true;
}
DifferenceSlice::~DifferenceSlice()
{

}
}//end namespace block
