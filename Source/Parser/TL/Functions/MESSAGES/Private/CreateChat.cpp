#include "../Public/CreateChat.h"


//begin namespace block
namespace MESSAGES
{

CreateChat::CreateChat()
{
	this->_ConstructorID = 164303470;
	this->_ContentRelated = true;
}

CreateChat::CreateChat(TArray<COMMON::InputUser*>  users, FString title)
{
	this->_ConstructorID = 164303470;
	this->_ContentRelated = true;
	this->users = users;
	this->title = title;
}
void CreateChat::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	X->OnSend(Writer);
	}
	Writer.TGWriteString(this->title);
}


void CreateChat::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
CreateChat::~CreateChat()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
