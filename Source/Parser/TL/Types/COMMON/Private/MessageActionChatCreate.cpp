#include "../Public/MessageActionChatCreate.h"


//begin namespace block
namespace COMMON
{

MessageActionChatCreate::MessageActionChatCreate()
{
	this->_ConstructorID = -1503425638;
}

MessageActionChatCreate::MessageActionChatCreate(FString title, TArray<int32>  users)
{
	this->_ConstructorID = -1503425638;
	this->title = title;
	this->users = users;
}
void MessageActionChatCreate::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->title);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	Writer.WriteInt(X);
	}
}


void MessageActionChatCreate::OnResponce(BinaryReader& Reader)
{
	title = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len14850 = Reader.ReadInt();
	for(int32 i = 0; i < Len14850; i++)
	{
	auto X = Reader.ReadInt();
	users.Add(X);
	}
	this->_Responded = true;
}
MessageActionChatCreate::~MessageActionChatCreate()
{

}
}//end namespace block
