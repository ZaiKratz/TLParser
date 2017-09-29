#include "../Public/MessageActionChatAddUser.h"


//begin namespace block
namespace COMMON
{

MessageActionChatAddUser::MessageActionChatAddUser()
{
	this->_ConstructorID = 1217033015;
}

MessageActionChatAddUser::MessageActionChatAddUser(TArray<int32>  users)
{
	this->_ConstructorID = 1217033015;
	this->users = users;
}
void MessageActionChatAddUser::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->users.Num());
	for(auto X : this->users)
	{
	Writer.WriteInt(X);
	}
}


void MessageActionChatAddUser::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len19224 = Reader.ReadInt();
	for(int32 i = 0; i < Len19224; i++)
	{
	auto X = Reader.ReadInt();
	users.Add(X);
	}
	this->_Responded = true;
}
MessageActionChatAddUser::~MessageActionChatAddUser()
{

}
}//end namespace block
